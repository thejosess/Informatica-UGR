-- Obtiene la media de las notas cada asignatura por curso académico y asignatura. Se obtiene con dos decimales

-- Observar el uso de la función round y el uso de alias en el nombre de la salida



Select curso_academico, nombreas, round(avg(notas),2) nota_media from matricula,asigna  
where codasi#=asi# 

group by curso_academico, nombreas;



-- Obtiene la media de las notas cada asignatura por curso académico y asignatura (Se obtiene con dos decimales)

-- para aquellos cursos en los que hay más de 50 alumnos y se ordena por nota media



Select curso_academico, nombreas, round(avg(notas),2) nota_media from matricula,asigna  
where codasi#=asi# and  
50<=(Select count(*) from matricula ma where ma.curso_academico=matricula.curso_academico) 

group by curso_academico, nombreas order by curso_academico,avg(notas);



-- Obtiene la media de las notas cada asignatura por curso académico y asignatura (Se obtiene con dos decimales)

-- para aquellos cursos en los que hay más de 50 alumnos y cursos/asignaturas con nota media mayor que cinco,

---se ordena por nota media. Notese la diferencia entre selección y having.



Select curso_academico, nombreas, round(avg(notas),2) nota_media from matricula,asigna  
where codasi#=asi# and  
50<=any(Select count(*) from matricula ma where ma.curso_academico=matricula.curso_academico) 

group by curso_academico, nombreas having avg(notas)>5 order by curso_academico,avg(notas);