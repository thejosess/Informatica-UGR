-- Mostrar los datos del alumno con dni 242856'
select ape1,ape2,nombre,edad from alumnos where dni='242856';

--Cálculo WinRDBI:
query:= { A.nombre,A.ape1,A.ape2,A.edad |  alumnos(A) and A.dni='242856'};
