-- Alumnos de edad mínima (Tres soluciones)

select dni from alumnos
  minus
select a1.dni from alumnos a1, alumnos a2 where a1.edad > a2.edad;


select dni from alumnos a1 where not exists (
  select * from alumnos a2 where a1.edad > a2.edad);
  
select dni from alumnos  where edad = (select min(edad) from alumnos);
  
