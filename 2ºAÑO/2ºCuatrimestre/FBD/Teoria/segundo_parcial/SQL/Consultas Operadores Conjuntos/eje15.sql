--código y nombre de asignaturas en las que no hay ningún alumno matriculado

select asi#,nombreas from asigna where not exists (select * from matricula where asi#=codasi#);



select asi#,nombreas from asigna
  minus
select asi#,nombreas from asigna,matricula where asi#=codasi#;

