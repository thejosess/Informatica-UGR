--Asignaturas con mayor número de créditos

select asi#,nombreas,credt+credpr creditos from asigna where
 (credt+credpr)=(select max(credt+credpr) from asigna);
 


