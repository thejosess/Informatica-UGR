# gcc media.s -o media -no-pie ; ./media
.section .data

lista:		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff #si sumas dos veces de estos #numeroes te sale 0x1ffffff si sumes otro pues 0x2ffffff 
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff

longlista:	.int   (.-lista)/4
resultado:	.quad  0    				#resultado son dos de 32 es decir 64 quad
  formato: 	.asciz	"suma = %lu = 0x%lx hex\n"

.section .text
 main: .global  main

	mov     $lista, %rbx		#al hacer gdb -tui lo que ves es a direccion de memoria
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);

	mov %edx, resultado+4   	#mueve a resultado el contenido de edx, DUDA?
	mov %eax, resultado

    mov   $formato, %rdi
    mov   resultado+4, %rsi
    mov resultado, %rdx			#esto estaria bien?

	mov          $0,%eax	# varargin sin xmm  ESTO QU EESEEEES?
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
	add  (%rbx,%rdx,4), %eax   #int de 4 bits 
	jnc no_acarreo 		   # es como un if, 
	inc %edx 		   # %edx es 32 bits el registro %rdx, guardas +significativa acarreo

no_acarreo:			  # entras si no hay acarreo, pero entra si o si solo la difere es inc 
			          # inc %edx donde metes el acarreo con el codigo no_acarreo que es 					  # necesario para el for 

	inc   %rsi 		#contador
	cmp   %rsi,%rcx		# rsi es como decir en un for ( i = 0 ; i < 10 ) for( i=0;rsi<rcx)
	jne    bucle

	pop %rsi
	ret 			# duda sobre esto


