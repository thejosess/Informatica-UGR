// 9.- gcc suma_09_Casm.c -o suma_09_Casm -O / -Og -g

// gcc popcount.c -o popcount -Og -g -D TEST=1

/*
	=== TESTS === ____________________________________

	for i in 0 g 1 2; do printf "__OPTIM%1c__%48s\n" $i "" | tr " " "=";  for j in $(seq 1 4); do printf "__TEST%02d__%48s\n" $j "" | tr " " "-"; rm popcount; gcc popcount.c -o popcount -O$i -D TEST=$j -g; ./popcount; done; done

	=== CRONOS === ____________________________________

	for i in 0 g 1 2; do printf "__OPTIM%1c__%48s\n" $i "" | tr " " "="; rm popcount; gcc popcount.c -o popcount -O$i -D TEST=0; for j in $(seq 0 10); do echo $j; ./popcount; done | pr -11 -l 22 -w 80; done

	___________________________________________________
*/


#include <stdio.h>		// para printf()
#include <stdlib.h>		// para exit()
#include <sys/time.h>		// para gettimeofday(), struct timeval

int resultado=0;

#ifndef TEST
   #define TEST 5
#endif

/* -------------------------------------------------------------------- */
#if TEST==1
/* -------------------------------------------------------------------- */
   #define SIZE 4
   unsigned lista[SIZE]={0x80000000, 0x00400000, 0x00000200, 0x00000001};
   #define RESULT 4
/* -------------------------------------------------------------------- */
#elif TEST==2
/* -------------------------------------------------------------------- */   
   #define SIZE 8
   unsigned lista[SIZE]={0x7fffffff, 0xffbfffff, 0xfffffdff, 0xfffffffe,
			 0x01000023, 0x00456700, 0x8900ab00, 0x00cd00ef};
   #define RESULT 156
/* -------------------------------------------------------------------- */
#elif TEST==3
/* -------------------------------------------------------------------- */   
   #define SIZE 8
   unsigned lista[SIZE]={0x0       , 0x01020408, 0x35906a0c, 0x70b0d0e0,
			 0xffffffff, 0x12345678, 0x9abcdef0, 0xdeadbeef};
   #define RESULT 116
/* -------------------------------------------------------------------- */
#elif ( TEST==4 || TEST==0 )
/* -------------------------------------------------------------------- */
   #define NBITS 20
   #define SIZE (1<<NBITS)
   unsigned lista[SIZE];
   #define RESULT (NBITS*(1<<NBITS-1))
/* -------------------------------------------------------------------- */
#else
   #error "Definir TEST entre 0..4"
#endif
/* -------------------------------------------------------------------- */
// POPCOUNT_1 - Para cada elemento del vector hace and a nivel de bit y suma uno a result en caso de que el bit este activado.

#define WSIZE 8*sizeof(long)
int pcount_for(unsigned x){
	size_t i;
	int result = 0;
	for (i = 0; i < WSIZE; i++){
		result += x & 0x1;
		x >>= 1;
	}
	
	return result;
}

int popcount1(unsigned* array, size_t len){
	int numeroUnos=0;
	
	for(int i=0; i<len; i++)
		numeroUnos+=pcount_for(array[i]);

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_2 - Igual que el POPCOUNT_1, pero cuando el numero a comprobar es 0 (no tiene ningun bit mas activado) acaba el bucle while.

int pcount_while(unsigned x){
	int result = 0;
	
	while (x){
		result += x & 0x1;
		x >>= 1;
	}
	
	return result;
}

int popcount2(unsigned* array, size_t len){
	int numeroUnos=0;
	
	for(int i=0; i<len; i++)
		numeroUnos+=pcount_while(array[i]);

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_3 - Para cada elemento del vector, mueve un bit a la derecha y si ese bit era 1 se suma a result (ya que si el bit que movemos con shr es un uno se activa el flag CF y por eso utilizamos adc).

int popcount3(unsigned* array, size_t len){
	int result=0;
	unsigned x=0;
	
	for(int i=0; i<len; i++){
		x = array[i];
		asm("\n"
	"ini3:				\n\t"
		"shr %[x]		\n\t"
		"adc $0, %[r]		\n\t"
		"test %[x], %[x]	\n\t"
		"jnz ini3		\n\t"
		: [r]"+r" (result)
		: [x] "r" (x));
	}
	return result;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_4 - Similar al POPCOUNT_3 pero aprovecha que shr activa el flag ZF para comprobar si el numero ya no tiene mas bits activados (a cambio debemos añadir adc tras el bucle porque en caso de que el ultimo but que desplazamos sea uno no se suma a result).

int popcount4(unsigned* array, size_t len){
	int numeroUnos=0, x=0;
	
	for(int i=0; i<len; i++){
		x = array[i];
		asm("\n"
		"clc			\n\t"
	"ini4:				\n\t"
		"adc $0, %[r]		\n\t"
		"shr %[x]		\n\t"
		"jnz ini4		\n\t"
		"adc $0, %[r]		\n\t"
		: [r]"+r" (numeroUnos)
		: [x] "r" (x));
	}
	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_5 - Para cada elemento del vector utiliza una mascara 0x01010101 y suma los bits que aparacen en cada byte, a continuacion hace la suma en arbol de manera que el resultado queda en el LSB por eso hacemos un and con 0xFF.

int pcount_msk(unsigned x) {
	int val = 0;

	for (int i = 0; i < 8; i++) {
		val += x & 0x01010101U;
		x >>= 1;
	}

	val += (val >> 16);
	val += (val >> 8);
	return val & 0xFF;
}

int popcount5(unsigned* array, size_t len){
	int numeroUnos=0;
	
	for(int i=0; i<len; i++)
		numeroUnos+=pcount_msk(array[i]);

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_6 - Para cada elemento del vector, acumula la suma de los bits en cada 2 bits, despues los suma en cada nibble, despues en cada byte, despues cada 2 bytes y finalmente cada 4 bytes (en el elemento x ya que es un unsigned int(4B)).

const unsigned m1 = 0x55555555;
const unsigned m2 = 0x33333333;
const unsigned m4 = 0x0f0f0f0f;
const unsigned m8 = 0x00ff00ff;
const unsigned m16 = 0x0000ffff;

int pcount_tree(unsigned x){
	x = (x & m1 ) + ((x >> 1) & m1 );
	x = (x & m2 ) + ((x >> 2) & m2 );
	x = (x & m4 ) + ((x >> 4) & m4 );
	x = (x & m8 ) + ((x >> 8) & m8 );
	x = (x & m16) + ((x >> 16) & m16);
	return x;
}

int popcount6(unsigned* array, size_t len){
	int numeroUnos=0;
	
	for(int i=0; i<len; i++)
		numeroUnos+=pcount_tree(array[i]);

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_7 - Igual que el anterior pero utilizando variables unsigned long (8B) con lo que podemos hacer el popcount de 4 en 4 elementos (x1 son 2 unsigned int y x2 otros 2, en total en cada iteracion se calcula el popcount de 4 elementos del vector).

int popcount7(unsigned* array, size_t len){
	unsigned long x1,x2;
	int numeroUnos=0;

	const unsigned long m1 = 0x5555555555555555;
	const unsigned long m2 = 0x3333333333333333;
	const unsigned long m4 = 0x0f0f0f0f0f0f0f0f;
	const unsigned long m8 = 0x00ff00ff00ff00ff;
	const unsigned long m16 = 0x0000ffff0000ffff;
	const unsigned long m32 = 0x00000000ffffffff;

	if (len & 0x3)
		printf("leyendo 128b pero len no múltiplo de 4\n");
	
	for (int i=0; i<len; i+=4){
		x1 = *(unsigned long*) &array[i ];
		x2 = *(unsigned long*) &array[i+2];

		x1 = (x1 & m1 ) + ((x1 >> 1) & m1 );
		x1 = (x1 & m2 ) + ((x1 >> 2) & m2 );
		x1 = (x1 & m4 ) + ((x1 >> 4) & m4 );
		x1 = (x1 & m8 ) + ((x1 >> 8) & m8 );
		x1 = (x1 & m16) + ((x1 >> 16) & m16);
		x1 = (x1 & m32) + ((x1 >> 32) & m32);

		x2 = (x2 & m1 ) + ((x2 >> 1) & m1 );
		x2 = (x2 & m2 ) + ((x2 >> 2) & m2 );
		x2 = (x2 & m4 ) + ((x2 >> 4) & m4 );
		x2 = (x2 & m8 ) + ((x2 >> 8) & m8 );
		x2 = (x2 & m16) + ((x2 >> 16) & m16);
		x2 = (x2 & m32) + ((x2 >> 32) & m32);
		
		numeroUnos+= x1+x2;
	}

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_8 - Para cada 4 elementos del vector (pues se utilizan registros de 128 bits), se separan en dos registros los nibbles pares y los nibbles impares, se hace un and con la mascara 0x0f0f0f0f, se hacen 2 copias de la tabla de correspondencias, y se hacen las correspondientes operaciones pshufb para los registros de los nibbles pares e impares, de manera que en el sitio donde teniamos los datos (bits activados o desactivados) quedan el numero de bits que estaban activos en cada nible. Posteriormente se suman los registros de nibbles pares e impares para que nos queden los numeros de bits por byte en cada byte, acumulamos las sumas de los numeros de bits por byte en cada 8B, los MS8B y los LS8B (2 elementos del vector de unsigned int o 1 elemento unsigned long) y finalmente los suma en el registro de 128 bits, aunque el resultado en si con los 4B de un int nos sobra, por lo que el popcount queda en val.

int popcount8(unsigned* array, size_t len){
	int val, numeroUnos=0;
	int SSE_mask[] = {0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
	int SSE_LUTb[] = {0x02010100, 0x03020201, 0x03020201, 0x04030302};
			//3 2 1 0	7 6 5 4		11 10 9 8	15 14 13 12
	if (len & 0x3)
		printf("leyendo 128b pero len no múltiplo de 4\n");

	for (int i=0; i<len; i+=4){
		asm(	"movdqu %[x], %%xmm0	\n\t"
			"movdqa %%xmm0, %%xmm1	\n\t" //x: two copies xmm0-1
			"movdqu %[m], %%xmm6	\n\t" //mask: xmm6
			"psrlw $4 , %%xmm1	\n\t"
			"pand %%xmm6, %%xmm0	\n\t" //; xmm0 – lower nibbles
			"pand %%xmm6, %%xmm1	\n\t" //; xmm1 – higher nibbles
			"movdqu %[l], %%xmm2	\n\t" //; since instruction pshufb modifies LUT
			"movdqa %%xmm2, %%xmm3	\n\t" //; we need 2 copies
			"pshufb %%xmm0, %%xmm2	\n\t" //; xmm2 = vector of popcount lower nibbles
			"pshufb %%xmm1, %%xmm3	\n\t" //; xmm3 = vector of popcount upper nibbles
			"paddb %%xmm2, %%xmm3	\n\t" //; xmm3 - vector of popcount for bytes
			"pxor %%xmm0, %%xmm0	\n\t" //; xmm0 = 0,0,0,0
			"psadbw %%xmm0, %%xmm3	\n\t" //; xmm3 = [pcnt bytes0..7|pcnt bytes8..15]
			"movhlps %%xmm3, %%xmm0	\n\t" //; xmm0 = [    0    |pcnt bytes0..7 ]
			"paddd %%xmm3, %%xmm0	\n\t" //; xmm0 = [ not needed |pcnt bytes0..15]
			"movd %%xmm0, %[val]" //;
			: [val]"=r" (val)
			: [x] "m" (array[i]),
			[m] "m" (SSE_mask[0]),
			[l] "m" (SSE_LUTb[0])
		);
		numeroUnos += val;
	}

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_9 - Para cada elemento del vector calcula el popcount a traves de la instruccion explicita en ensamblador.

int popcount9(unsigned* array, size_t len){
	int val, numeroUnos=0;

	for (int i=0; i<len; i++){
		asm(	"popcnt %[x], %[val]"

			: [val]"=r" (val)
			: [x] "r" (array[i])
		);
		numeroUnos += val;
	}

	return numeroUnos;
}

/* -------------------------------------------------------------------- */
// POPCOUNT_10 - Igual que el anterior pero calculando el popcount de 4 elementos del vecor en cada iteracion (calcula el popcount de 2 elementos del vector en x1 y el de los 2 elementos contiguos en x2 y los suma en val).

int popcount10(unsigned* array, size_t len){
	int numeroUnos=0;
	unsigned long x1, x2, val1, val2;

	if (len & 0x3)
		printf("leyendo 128b pero len no múltiplo de 4\n");

	for (int i=0; i<len; i+=4){
		x1 = *(unsigned long*) &array [i];
		x2 = *(unsigned long*) &array[i+2];
		asm(	"popcnt %[x1], %[val1] \n\t"
			"popcnt %[x2], %[val2] \n\t"
			"add %[val2], %[val1] \n\t"
			: [val1] "=&r" (val1),
			[val2] "=&r" (val2)
			: [x1] "r" (x1),
			[x2] "r" (x2)
		);
		numeroUnos += val1;
	}

	return numeroUnos;
}

/* -------------------------------------------------------------------- */

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2; 			// gettimeofday() secs-usecs
    long           tv_usecs;			// y sus cuentas

    gettimeofday(&tv1,NULL);
    resultado = func(lista, SIZE);
    gettimeofday(&tv2,NULL);

    tv_usecs=(tv2.tv_sec -tv1.tv_sec )*1E6+
             (tv2.tv_usec-tv1.tv_usec);
    
#if TEST==0
	printf("%ld" "\n", tv_usecs);

#else
	printf("resultado = %d\t", resultado);
	printf("%s:%9ld us\n", msg, tv_usecs);
#endif
}

/* -------------------------------------------------------------------- */

int main()
{
#if TEST==0 || TEST==4
    size_t i;					// inicializar array
    for (i=0; i<SIZE; i++)
	 lista[i]=i;
#endif

    crono(popcount1, "popcount1 (lenguaje C -       for)");
    crono(popcount2, "popcount2 (lenguaje C -     while)");
    crono(popcount3, "popcount3 (leng.ASM-body while 4i)");
    crono(popcount4, "popcount4 (leng.ASM-body while 3i)");
    crono(popcount5, "popcount5 (CS:APP2e 3.49-group 8b)");
    crono(popcount6, "popcount6 (Wikipedia- naive - 32b)");
    crono(popcount7, "popcount7 (Wikipedia- naive -128b)");
    crono(popcount8, "popcount8 (asm SSE3 - pshufb 128b)");
    crono(popcount9, "popcount9 (asm SSE3- popcount 32b)");
    crono(popcount10, "popcount10 (asm SSE3- popcount128b)");
    
#if TEST!=0
	printf("calculado = %d\n", RESULT);
#endif

    exit(0);
}
