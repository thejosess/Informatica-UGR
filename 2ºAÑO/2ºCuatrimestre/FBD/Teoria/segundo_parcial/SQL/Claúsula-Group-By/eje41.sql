--Edad media de los alumnos por sexo

select sexo, avg(edad) from alumnos group by sexo order by sexo ;


-- Edad media de alumnos varones


select sexo, avg(edad) from alumnos group by sexo having sexo='V' order by sexo ;
