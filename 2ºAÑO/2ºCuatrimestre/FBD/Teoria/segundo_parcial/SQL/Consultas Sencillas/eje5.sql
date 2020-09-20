-- DNI nombre, apellidos y curso académico de los alumnos mayores de 25 matriculados de la asignatura tec1 
-- ordenados por curso académico y apellidos y nombre (Dos soluciones alternativas)
select curso_academico, al.dni,nombre,ape1,ape2 from alumnos al, matricula ma 
where edad >25 and ma.codasi#='tec1' and al.dni=ma.dni 
order by  curso_academico,ape1,ape2,nombre;

select distinct curso_academico, dni,nombre,ape1,ape2 
from alumnos  natural join matricula 
where edad >25 and codasi#='tec1' 
order by  curso_academico,ape1,ape2,nombre;


--Cálculo WinRDBI: DNI nombre, apellidos y curso académico de los alumnos mayores de 25 matriculados de la asignatura tec1 
query:= { M.curso_academico, A.dni,A.nombre,A.ape1,A.ape2 | alumnos(A) and matricula(M) and A.edad>25 
and M.codasi='tec1' and M.dni=A.dni};




