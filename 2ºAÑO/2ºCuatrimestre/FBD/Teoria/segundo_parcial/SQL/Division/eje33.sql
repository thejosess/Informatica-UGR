--Alumnos becarios matriculados de todas las asignaturas de más de seis créditos (Dos alternativas de solución)

select ape1,ape2,nombre from alumnos al where beca='si' and not exists
      (select * from asigna  a where credt+credpr>6 and 
            not exists (select * from matricula m where al.dni=m.dni and a.asi#=m.codasi#));
            
select ape1,ape2,nombre from alumnos al where beca='si' and not exists
      (select a.asi# from asigna  a where credt+credpr>6 
         minus
       select m.codasi# from matricula m where al.dni=m.dni);

