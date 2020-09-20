#La contraseña de la bomba es = patadecabra
#El pin de la bomba es = 101010

layout asm
layout regs
br *0x4007df
br *0x400801
br *0x40085a
br *0x40087e
run < <(echo -e hola\\n123\\n)
set $eax=0
cont
set $eax=0
cont
set $eax=123
cont
set $eax=0
cont
