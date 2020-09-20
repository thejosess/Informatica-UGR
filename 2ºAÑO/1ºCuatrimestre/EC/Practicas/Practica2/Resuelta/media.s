# gcc media.s -o media -no-pie ; ./media

/*
for i in $(seq 1 9); do
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

lista:	.irpc	i,1234
				linea
		.endr

longlista:	.int   (.-lista)/4
resultado:	.quad  0    		
formato:.ascii "resultado \t =   %18lu (uns)\n" 
		.ascii  "\t\t = 0x%18lx (hex)\n" 
		.asciz "\t\t = 0x %08x %08x \n"

.section .text
 main: .global  main

	mov     $lista, %rbx		#al hacer gdb -tui lo que ves es a direccion de memoria
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov %edx, resultado+4   	#mueve a resultado el contenido de edx, DUDA?
	mov %eax, resultado

    mov   $formato, %rdi
    mov   resultado, %rsi
    mov resultado, %rdx			#esto estaria bien?
    mov          $0,%eax	# varargin sin xmm  ESTO QU EESEEEES?

    mov resultado+4, %ecx      #esto es para que el tercer resultado salga bien 64 bits
    mov resultado, %r8d

    call  printf		# == printf(formato, res, res); 20,21,22 argumentos

	mov  $0, %edi		# si pones mov resultado, %edi  te sale 240 y queremos 0 sin error en 					# echo $?
	call _exit		# ==  exit(resultado)
	ret  			# la suma del terminal sale random DUDAAAAA, ES DIRECCION MEMORIA ALEATORIO

suma:

	mov  $0, %eax     #inicializar registros, parte menos significativa al eax
	mov  $0, %rdx
	push %rsi 	  # guardas el valor de rsi y pop lo vuelves a sacar
	mov  $0, %rsi

bucle:
	add  (%rbx,%rdx,4), %eax   #int de 4 bits # %rdx es un indice y el adc %edx te lo suma(?)

	adc $0,%edx		#si hay acarreo en la instruccion de add de arriba te mete el acarreo en edx (CF el $0)

	inc   %rsi 		#contador
	cmp   %rsi,%rcx		# rsi es como decir en un for ( i = 0 ; i < 10 ) for( i=0;rsi<rcx)

    jne    bucle

	pop %rsi
	ret 			# duda sobre esto
