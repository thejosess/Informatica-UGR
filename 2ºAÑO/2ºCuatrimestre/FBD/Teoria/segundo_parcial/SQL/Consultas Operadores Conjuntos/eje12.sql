--Asignaturas que están en el último curso (Tres soluciones)

select asi# from asigna where curso>= all(select curso from asigna);

select asi# from asigna where curso= (select max(curso) from asigna);

select asi# from asigna as1 where not exists (
   select * from asigna as2 where as2.curso>as1.curso
);


