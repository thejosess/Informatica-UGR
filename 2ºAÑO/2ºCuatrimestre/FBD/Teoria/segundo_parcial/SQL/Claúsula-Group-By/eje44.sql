-- Encontrar los nombres y lo códigos de las asignaturas que se han impartido en el curso 2014-2015 junto con el número de alumnos matriculados en ellas 


select nombreas,asigna.asi#, count(*) from asigna, matricula where asigna.asi#=matricula.codasi# and 
curso_academico='2014-2015' group by nombreas, asigna.asi#;



-- Encontrar las asignaturas que tienen mayor número de alumnos en el 2014-2015


select codasi#, count(*) from matricula 
where curso_academico='2014-2015' 
group by codasi# 
having count(*)>=all(select count(*) from matricula ma 
where ma.curso_academico='2014-2015' group by ma.codasi#);



