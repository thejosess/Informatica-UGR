# Practica 4, Ejercicio 1: evitar las comprobaciones

# Ahorrarse teclear estas instrucciones cada vez
# que se empieza a depurar el programa bomba


# Debido al nombre de fichero "bomba-gdb.gdb"
# se carga automaticamente al ejecutar "gdb bomba"

layout asm
layout regs
br *0x4007cc
br *0x4007ee
br *0x400847
br *0x40086b
run < <(echo -e hola\\n123\\n)
set  $eax=0
cont
set $eax=0
cont
#< <echo -e 123
set $eax=123
cont
set $eax=0
cont
