-- DNI nombre y apellidos de alumnos matriculados de la asignatura 'mabd1'

select dni,ape1,ape2,nombre from alumnos
   where exists (select * from matricula  where codasi#='mab1' and alumnos.dni=matricula.dni);
   
select distinct dni,ape1,ape2,nombre 
from alumnos natural join (select dni from matricula where codasi#='mab1');



-- DNI nombre y apellidos de alumnos no matriculados de la asignatura 'mabd1'

select dni,ape1,ape2,nombre from alumnos
   where not exists (select * from matricula  where codasi#='mab1' and alumnos.dni=matricula.dni);
   
   


