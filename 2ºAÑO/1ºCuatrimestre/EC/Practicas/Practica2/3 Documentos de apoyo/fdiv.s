#################################################
# Imprimir la media en coma flotante
# fdiv.s
# gcc -g -m32 -nostartfiles fdiv.s -o fdiv
#################################################

.data
f:      	.string "media = %f\n" # cadena de formato
longlista:	.int 32
resultado:	.quad 0
media:		.double 0

#################################################

.text
        .extern printf
        .globl _start

_start: 

	# Ejemplo: edx:eax = 0xee6b28010 (64 000 000 016)
	# 64 000 000 016 / 32 = 2 000 000 000.5
	mov	$0xe6b28010, %eax	
	mov	$0xe, %edx

	mov	%eax, resultado
	mov	%edx, resultado + 4

	fildl	longlista	# entero 32 bits a coma flotante y apila en st(0)
	fildll	resultado	# entero 64 bits a coma flotante y apila en st(0)
	fdivp	%st,%st(1)	# st(0) / st(1), es decir resultado / longlista
	fstl	media		# media = st(0)

        pushl	media + 4		# media es un double (64 bits)
        pushl	media
        push	$f			# formato
        call	printf
        add	$12, %esp		# restaura pila

        movl	$1, %eax		# exit
        xorl	%ebx, %ebx	# 0
        int	$0x80		# llamada a exit

#################################################
