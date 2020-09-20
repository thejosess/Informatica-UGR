#La contraseña de la bomba es = patadecabra
#El pin de la bomba es = 101010

layout asm
layout regs
br *0x4007d0	#break para comprobar si has introducido la contraseña bien 
br *0x4007df	#break para comprobar si has introducido la contraseña bien funcion comprobar
br *0x400801	#break para poner el tiempo que tardas en escribir a 0
br *0x40083a	#break para comprobar si has introducido el pin bien
br *0x40084f	#break para comprobar si has introducido el pin bien funcion comprobar2
br *0x40085a	#break para poner el tiempo que tardas en escribir a 0	
br *0x40087e	#break para poner el tiempo que tardas en escribir a 0	
run < <(echo -e hola\\n123\\n)	#haces run introduciendo la contraseña como hola y el pin como 123
set $eax=0	#cambiar el valor de eax a 0 para que salte la comprobacion de la contraseña
cont
set $eax=0	#cambiar el valor de eax a 0 para que salte la comprobacion de la contraseña funcion 			#comprobar
cont
set $eax=0	#cambias el valor de eax a 0 para que salte la comprobacion del tiempo
cont
set $eax=0	#cambias el valor de eax a 0 para que salte la comprobacion del tiempo comprobar2
cont
set $eax=0	#cambias el valor de eax a 0 para que salte la comprobacion del pin 
cont
set $eax=123	#cambiar el valor de eax a 123 para la introduccion del pin
cont 
set $eax=0	#cambiar el valor de eax a 0 para que salte la comprobracion del tiempo
cont
