--Número de alumnos en cada asignatura en cada curso académico 

select curso_academico,codasi#,count(*)  from matricula group by curso_academico,codasi# order by curso_academico,codasi# ;

--Número de alumnos en cada asignatura en cada curso académico para aquellos cursos/asignaturas con más de 10 alumnos
select curso_academico,codasi#,count(*)  from matricula group by curso_academico,codasi# having count(*)>=10
order by curso_academico,codasi# ;

