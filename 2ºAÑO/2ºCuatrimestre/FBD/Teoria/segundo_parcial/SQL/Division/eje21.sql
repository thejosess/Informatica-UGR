-- Asignaturas que tienen o han tenido  matriculados a todos los alumnos de Almería (Dos alternativas de solución)

Select asi#,nombreas from asigna a where 
   not exists(select dni from alumnos  where provincia='Almeria'
               minus
              select m.dni from matricula m where m.codasi#=a.asi#);


Select asi#,nombreas from asigna a where 
   not exists(select * from alumnos al where al.provincia='Almeria' and 
       not exists (select * from matricula m where m.codasi#=a.asi# and m.dni=al.dni));
	   
