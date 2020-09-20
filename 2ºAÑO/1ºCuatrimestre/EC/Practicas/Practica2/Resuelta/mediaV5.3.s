# gcc media.s -o media -no-pie ; ./media

/*
for i in $(seq 1 19); do
 rm media
gcc -x assembler-with-cpp -D TEST=$i -no-pie media.s -o media
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./media 
done
*/
.section .data
#ifndef TEST
#define TEST 20
#endif
	.macro linea
  #if	TEST==1
		.int -1,-1,-1,-1
#elif	TEST==2
		.int 0x04000000,0x04000000,0x04000000,0x04000000
#elif	TEST==3
		.int 0x08000000,0x08000000,0x08000000,0x08000000
#elif	TEST==4
		.int 0x10000000,0x10000000,0x10000000,0x10000000
#elif	TEST==5
		.int 0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff
#elif	TEST==6
		.int 0x80000000,0x80000000,0x80000000,0x80000000
#elif	TEST==7
		.int 0xf0000000,0xf0000000,0xf0000000,0xf0000000
#elif	TEST==8
		.int 0xf8000000,0xf8000000,0xf8000000,0xf8000000
#elif	TEST==9
		.int 0xf7ffffff,0xf7ffffff,0xf7ffffff,0xf7ffffff
#elif	TEST==10
		.int 100000000,100000000,100000000,100000000
#elif	TEST==11
		.int 200000000,200000000,200000000,200000000
#elif	TEST==12
		.int 300000000,300000000,300000000,300000000
#elif	TEST==13
		.int 2000000000,2000000000,2000000000,2000000000
#elif	TEST==14
		.int 3000000000,3000000000,3000000000,3000000000
#elif	TEST==15
		.int -100000000,-100000000,-100000000,-100000000
#elif	TEST==16
		.int -200000000,-200000000,-200000000,-200000000
#elif	TEST==17
		.int -300000000,-300000000,-300000000,-300000000
#elif	TEST==18
		.int -200000000,-200000000,-200000000,-200000000
#elif	TEST==19
		.int -3000000000,-3000000000,-3000000000,-3000000000
#else
	.error "Definir TEST entre 1..19"
#endif
	.endm
lista: .irpc i,1234
		linea
	.endr

longlista:	.int   (.-lista)/4
resultado:	.quad  0    		
formato:.ascii "resultado \t =   %18ld (signs)\n" 
		.ascii  "\t\t = 0x%18lx (hex)\n" 
		.asciz "\t\t = 0x %08x %08x \n"

.section .text
 main: .global  main


	mov     $lista, %rbx		# al hacer gdb -tui lo que ves es a direccion de memoria
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov %edx, resultado+4   	# mueve a resultado el contenido de edx, DUDA?
	mov %eax, resultado

    mov   $formato, %rdi
    mov   resultado, %rsi
    mov resultado, %rdx			# esto estaria bien?
	mov          $0,%eax	# varargin sin xmm  ESTO QU EESEEEES?

    mov resultado+4, %ecx      # esto es para que el tercer resultado salga bien 64 bits
    mov resultado, %r8d			# el uso de estos registros para imprimir el ultimo asci de hex largo


    call  printf		# == printf(formato, res, res); 20,21,22 argumentos

	mov  $0, %edi		# si pones mov resultado, %edi  te sale 240 y queremos 0 sin error en 					# echo $?
	call _exit		# ==  exit(resultado)
	ret  			# la suma del terminal sale random DUDAAAAA, ES DIRECCION MEMORIA ALEATORIO

suma:

	push %rsi 	  # guardas el valor de rsi y pop lo vuelves a sacar
	push %rbp
	push %rdi
	mov $0, %rbp
	mov $0, %rdi
	mov  $0, %eax     # inicializar registros, parte menos significativa al eax
	mov  $0, %rdx
	mov  $0, %rsi

bucle:

	mov  (%rbx,%rbp,4), %eax   # int de 4 bits  %rdx es un indice para meter y en adc incrementas el indice %edx por tanto %rdx
	cdq							# extendemos signo

	add  %eax,%esi
	adc %edx,%edi  				# adc te hace cosas respecto a la linea de arriba y te salta CF o no es como poner $0 o %, respecto a la suma

	inc   %rbp 						# contador
	cmp   %rbp,%rcx					# rsi es como decir en un for ( i = 0 ; i < 10 ) for( i=0;rsi<rcx)
	jne    bucle

	mov %edi, %edx
	mov %esi, %eax

	pop %rsi
	pop %rbp
	pop %rdi
	ret 			# duda sobre esto
