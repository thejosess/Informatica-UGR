-- Asignaturas que tienen alumnos matriculados en todos los cursos académicos (Dos alternativas de solución)

Select asi#,nombreas from asigna a where not exists
      (select * from matricula m1 where 
          not exists (select * from matricula m2 where a.asi#=m2.codasi# and m1.curso_academico=m2.curso_academico));
          
Select asi#,nombreas from asigna a where not exists
      (select m1.curso_academico from matricula m1 
        minus
       select m2.curso_academico from matricula m2 where a.asi#=m2.codasi#);

