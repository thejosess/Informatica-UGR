/*
for i in $(seq 1 19); do
 rm media
gcc -x assembler-with-cpp -D TEST=$i -no-pie media.s -o media
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./media 
done
*/
.section .data

#ifndef TEST
#define TEST 9
#endif
		.macro linea					# Resultado - Comentario
#if TEST	==1
				.int 1,1,1,1

#elif TEST==2
				.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff

#elif TEST==3
				.int 0x10000000, 0x10000000, 0x10000000, 0x10000000

#elif TEST==4
				.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff

#elif TEST==5
				.int -1, -1, -1, -1

#elif TEST==6
				.int 200000000, 200000000, 200000000, 200000000

#elif TEST==7
				.int 300000000, 300000000, 300000000, 300000000

#elif TEST==8
				.int 5000000000, 5000000000, 5000000000, 5000000000
#else
		.error "Definir TEST entre 1..8"
#endif
		.endm
lista: .irpc i,1234
		linea
	.endr

longlista:	.int   (.-lista)/4
media: .int 0
resto: .int 0		
formato:.ascii "media \t = %11d \t resto \t = %11d \n"
		.asciz		  "\t = 0x %08x \t\t = 0x %08x\n"

.section .text
 main: .global  main

	mov     $lista, %rbx		#al hacer gdb -tui lo que ves es a direccion de memoria
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov %eax, media
	mov %edx, resto

    mov   $formato, %rdi
    mov media, %rsi
    mov resto, %rdx
	mov   $0,%eax	# varargin sin xmm  ESTO QU EESEEEES?

    mov media, %ecx      #esto es para que el tercer resultado salga bien 64 bits
    mov resto, %r8d			#el uso de estos registros para imprimir el ultimo asci de hex largo


    call  printf		# == printf(formato, res, res); 20,21,22 argumentos

	ret  			# la suma del terminal sale random DUDAAAAA, ES DIRECCION MEMORIA ALEATORIO

suma:

	push %rbp 	  # guardas el valor de rsi y pop lo vuelves a sacar
	push %rsi
	push %rdi
	mov $0, %edi
	mov $0, %esi
	mov  $0, %eax     #inicializar registros, parte menos significativa al eax
	mov  $0, %rdx
	mov  $0, %ebp

bucle:

	mov  (%rbx,%rbp,4), %eax   #int de 4 bits  %rdx es un indice para meter y en adc incrementas el indice %edx por tanto %rdx
	cdq							#extendemos signo

	add  %eax,%esi
	adc %edx,%edi  				#adc te hace cosas respecto a la linea de arriba y te salta CF o no es como poner $0 o %, respecto a la suma

	inc   %ebp 						#contador
	cmp   %rbp,%rcx					# rsi es como decir en un for ( i = 0 ; i < 10 ) for( i=0;rsi<rcx)
	jne    bucle

	mov %esi, %eax
	mov %edi, %edx

	idiv %ecx					# el resto se almacena obligatoriamente en unos registros y coge la division de unos registros obligatorios

	pop %rbp
	pop %rdi
	pop %rsi
	ret 			# duda sobre esto
