layout asm
layout regs
#br *main	observas que hay un bucle usando password y metiendo en otra variable
#br *main+67	sale del for y compara strcmp con otra variable que no es password
#br *main+138
#info regs
#p(char*) $rsi	#tenemos la contraseña
#set $rdi="hplaryos"	
#br *main+273	te pide introducir el pin
#br  *main+336	despues del bucle de sumarle a la contraseña
run < <(echo -e hplaryos\\n2809\\n)
