-- Mostrar los nombres de la asignaturas optativas con más de 4.5 créditos totales
-- en las que está o ha estado matriculado el alumno Luis Perez Jimenez
-- ordenadas por nombre de asignatura.

select  distinct nombreas from alumnos, asigna, matricula
where caracter='op' and credt+credpr>4.5 and 
      nombre='Luis' and ape1='Perez' and ape2='Jimenez' and
      alumnos.dni=matricula.dni and codasi#=asi#
order by nombreas;


--Cálculo WinRDBI: Mostrar los nombres de la asignaturas optativas con más de 4.5 créditos teóricos
--en las que está o ha estado matriculado el alumno Luis Perez Jimenez

query:= { A | asigna(A) and  A.credt>4.5 and A.caracter='op' and (exists Al,M)(alumnos(Al) and matricula(M) and Al.nombre='Luis' and Al.ape1='Perez'
 and Al.ape2='Jimenez' and M.codasi=A.asi and M.dni=Al.dni)};


