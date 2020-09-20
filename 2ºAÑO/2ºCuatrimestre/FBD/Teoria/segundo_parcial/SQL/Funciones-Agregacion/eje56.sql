-- Alumnos con nota de entrada menor o igual que la media de las notas de entrada

select ape1,ape2,nombre,nota from alumnos where nota<=(select avg(nota) from alumnos);

