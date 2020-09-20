-- Alumnos que han aprobado todas las asignaturas del grado en Informática (Dos alternativas de solución)

 
Select ape1,ape2,nombre from alumnos al where
      
not exists (select a.asi# from asigna a where curriculum='Grado Informatica'  
                   
minus
                  
select m.codasi# from matricula m where al.dni=m.dni and calificacion >= 5));
  
 


