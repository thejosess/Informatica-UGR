.data
msg:    .ascii "¡hola, mundo!\n"
tam:    .quad . - msg

.text
        .global _start

write:  mov   $1, %rax    # write
        mov   $1, %rdi    # stdout
        mov   $msg, %rsi  # texto
	#mov $msg, %rsi #texto
        mov   tam,  %rdx  # tamaño	#tendrias que poner la de arriba y la de abajo pero compi lo hace por nosotros y no tenemos que calcularlo
	#mov tam, %rdx	#tamaño
        syscall           # llamada a write
        ret

exit:   mov   $60,  %rax  # exit
        xor   %rdi, %rdi  # 0
        syscall           # llamada a exit
        ret

_start: call  write       # llamada a función
        call  exit        # llamada a función

