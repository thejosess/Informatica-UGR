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
		# doble macro: lista definida por una linea0 y 3 lineas normales
		# mayoria ejemplos linea0 = linea => lista tiene 4 lineas normales

	.macro linea 						# Media / resto - Comentario
  #if	TEST==1							// 1 / 8
		.int 1,2,1,2					
#elif	TEST==2							// -1 / 8
		.int -1,-2,-1,-2
#elif	TEST==3
		.int 0x7FFFFFFF,0x7FFFFFFF,0x7FFFFFFF,0x7FFFFFFF
#elif	TEST==4
		.int 0x80000000,0x80000000,0x80000000,0x80000000
#elif	TEST==5
		.int 0xffffffff,0xffffffff,0xffffffff,0xffffffff
#elif	TEST==6
		.int 2000000000,2000000000,2000000000,2000000000
#elif	TEST==7
		.int 3000000000,3000000000,3000000000,3000000000
#elif	TEST==8
		.int -2000000000,-2000000000,-2000000000,-2000000000
#elif	TEST==9
		.int -3000000000,-3000000000,-3000000000,-3000000000
#elif TEST>=10 && TEST<=14 
		.int  1, 1, 1, 1             # linea0 + 3lineas, casi todo a 1
#elif  TEST>=15 && TEST<=19 
		.int -1,-1,-1,-1			# linea0 + 3lineas, casi todo  -1
#else 
		.error "Definir TEST entre 1..19" 
#endif 
		.endm 

		# mayorÃƒÆ’Ã‚Â­a ejemplos linea0 = linea => lista tiene 4 lineas normales 
		
		.macro linea0  			# Media / Resto - Comentario 
#if TEST>=1 && TEST<=9 
		linea 					# casi siempre 4 lineas iguales
#elif TEST==10 					//   1 / 0  - equiv toda lista 1 
		.int   0, 2, 1, 1 
#elif TEST==11 					
		.int   1, 2, 1, 1 
#elif TEST==12 					
		.int   8, 2, 1, 1
#elif TEST==13 					
		.int   15, 2, 1, 1
#elif TEST==14 					
		.int   16, 2, 1, 1
#elif TEST==15 			//  -1 / 0  - equiv TEST05 
		.int   0,-2,-1,-1 
#elif TEST==16 			
		.int   -1,-2,-1,-1 
#elif TEST==17 			
		.int   -8,-2,-1,-1 
#elif TEST==18 			
		.int   -15,-2,-1,-1 
#elif TEST==19 		//    ? / ? 
		.int -16,-2,-1,-1
#else
	.error "Definir TEST entre 1..19"
#endif
	.endm
lista: 	linea0
	.irpc i,123
		linea
	.endr

longlista:	.int   (.-lista)/4
media: .int 0
resto: .int 0		
formato:.ascii "media \t = %11d \t resto \t = %11d \n"
		.asciz		  "\t = 0x %08x \t\t = 0x %08x\n"

.section .text
 main: .global  main

	mov     $lista, %rbx		#al hacer gdb -tui lo que ves es a direccion de memoria
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov %eax, media
	mov %edx, resto

    mov   $formato, %rdi
    mov media, %rsi
    mov resto, %rdx
	mov   $0,%eax	

    mov media, %ecx      #esto es para que el tercer resultado salga bien 64 bits
    mov resto, %r8d			#el uso de estos registros para imprimir el ultimo asci de hex largo


    call  printf		# == printf(formato, res, res); 20,21,22 argumentos

	ret  			# la suma del terminal sale random DUDAAAAA, ES DIRECCION MEMORIA ALEATORIO

suma:

	push %rbp 	  # guardas el valor de rsi y pop lo vuelves a sacar
	push %rsi
	push %rdi
	mov $0, %edi
	mov $0, %esi
	mov  $0, %eax     #inicializar registros, parte menos significativa al eax
	mov  $0, %rdx
	mov  $0, %ebp

bucle:

	mov  (%rbx,%rbp,4), %eax   #int de 4 bits  %rdx es un indice para meter y en adc incrementas el indice %edx por tanto %rdx
	cdq							#extendemos signo

	add  %eax,%esi
	adc %edx,%edi  				#adc te hace cosas respecto a la linea de arriba y te salta CF o no es como poner $0 o %, respecto a la suma

	inc   %ebp 						#contador
	cmp   %rbp,%rcx					# rsi es como decir en un for ( i = 0 ; i < 10 ) for( i=0;rsi<rcx)
	jne    bucle

	mov %esi, %eax
	mov %edi, %edx

	idiv %ecx					# el resto se almacena obligatoriamente en unos registros y coge la division de unos registros obligatorios

	pop %rbp
	pop %rdi
	pop %rsi
	ret 			# duda sobre esto

