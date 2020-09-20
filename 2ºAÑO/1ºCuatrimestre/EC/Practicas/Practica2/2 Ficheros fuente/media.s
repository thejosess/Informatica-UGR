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
		
_start: .global _start
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
	mov  %eax, resultado+4
	ret

suma:
	push     %rdi
	mov  $0, %eax
	mov  $0, %rdi

bucle:
	add  (%rbx,%rdi,4), %eax
	jnc no_acarreo
	inc %edx				# sumar acarreo a los 32
	adc # op1, op2 + CF

	adc $0, %edx # +CF

no_acarreo:
	inc   %rdi
	cmp   %rdi,%rcx
	jne    bucle

	pop   %rdi
	ret

imprim_C:			# requiere libC
	mov   $formato, %rdi
	mov   resultado,%esi
	mov   resultado,%edx
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
