#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = desc
set salida = tiempos_desc.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 1` >> $salida
  @ i += $incremento
end
