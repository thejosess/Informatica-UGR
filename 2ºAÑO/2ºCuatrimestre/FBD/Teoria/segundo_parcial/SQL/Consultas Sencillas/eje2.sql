-- Alumnos menores de 25 años ordenados por edad (descendente) y por apellidos y nombre

select nombre,ape1,ape2 from alumnos 
where edad <=25 order by edad desc, ape1,ape2,nombre;

--Cálculo WinRDBI: Alumnos menores de 25 años
query:= { A.nombre,A.ape1,A.ape2,A.edad |  alumnos(A) and A.edad<25};

