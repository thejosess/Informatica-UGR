---Alumnos entre 20 y 30 años procedentes de las provincias de Granada, Jaen o Almería
-- ordenados por apellidos y nombre.

select dni,nombre,ape1,ape2 from alumnos
    where edad between 20 and 30 and   
     provincia in  ('Jaen','Granada','Almeria') order by ape1,ape2,nombre;
	 
--Cálculo WinRDBI: Alumnos menores de 25 años
query:= { A.nombre,A.ape1,A.ape2,A.edad |  alumnos(A) and A.edad>=20 and A.edad<=30
and ( A.provincia='Jaen' or A.provincia='Granada' or A.provincia='Almeria')};

