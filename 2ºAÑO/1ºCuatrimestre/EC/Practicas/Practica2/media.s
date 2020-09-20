# gcc media.s -o media -no-pie ; ./media

/*
for i in $(seq 1 9); do
 rm media
gcc -x assembler-with-cpp -D TEST=$i -no-pie media.s -o media
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./media 
done
*/

/*for i in $(seq 1 9); do rm media; gcc -x assembler-with-cpp -D TEST=$i -no-pie media.s -o media; printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./media; done
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
				linea		# escribir a la linea 4 veces y asi ocupa linea*4
							# asi escribes 4 numeros repetidos por 4 y es 16
		.endr

longlista:	.int   (.-lista)/4
resultado:	.quad  0    		
formato:.ascii "resultado \t =   %18ld (uns)\n" 
		.ascii  "\t\t = 0x%18lx (hex)\n" 
		.asciz "\t\t = 0x %08x %08x \n"

.section .text
 main: .global  main


	call trabajar	# subrutina de usuario
	call imprim_C	# printf()  de libC
	call acabar_L	# exit()   del kernel Linux
	call acabar_C	# exit()    de libC
	ret

trabajar:
	mov     $lista, %rbx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov  %eax, resultado
	mov  %edx, resultado + 4
	ret

suma:
	push     %rsi
	mov  $0, %eax
	mov  $0, %rsi
	mov  $0, %r8d
	mov  $0, %r9d
	mov  $0, %edx
bucle:
	mov (%rbx,%rsi,4), %eax
	cdq
	add %eax, %r8d
	adc %edx, %r9d
	inc   %rsi
	cmp   %rsi,%rcx
	jne    bucle

	mov   %r8d, %eax
	mov	  %r9d, %edx
	pop   %rsi
	ret

imprim_C:			# requiere libC
	mov   $formato, %rdi
	mov   resultado,%r8d
	mov   resultado,%r9d
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);
	ret

acabar_L:
	mov        $60, %rax
	mov  resultado, %edi
	syscall			# == _exit(resultado)
	ret

acabar_C:			# requiere libC
	mov  resultado, %edi
	call _exit		# ==  exit(resultado)
	ret
