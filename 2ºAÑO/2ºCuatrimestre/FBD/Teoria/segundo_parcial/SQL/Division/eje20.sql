-- Alumnos matriculados de todas las asignaturas optativas (Dos alternativas de solución)

Select ape1,ape2,nombre from alumnos a where
not exists (
    select asi# from asigna where caracter='op'
       minus
    select m.codasi# from matricula m where m.dni=a.dni
);


Select ape1,ape2,nombre from alumnos where
not exists (select asi# from asigna where caracter='op'
    and not exists(select * from matricula where matricula.dni=alumnos.dni and codasi#=asi#));
	
