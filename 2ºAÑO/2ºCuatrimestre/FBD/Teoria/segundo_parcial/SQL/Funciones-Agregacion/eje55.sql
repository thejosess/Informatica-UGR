-- Alumnos de edad mínima (compara con el ejercicio eje17)

select ape1,ape2,nombre,edad from alumnos where
 edad=(select min(edad) from alumnos);
 
-- Cálculo WIRDBI:
query:={ A | alumnos(A) and not (exists A1)(alumnos(A1) and A1.edad<A.edad)};


