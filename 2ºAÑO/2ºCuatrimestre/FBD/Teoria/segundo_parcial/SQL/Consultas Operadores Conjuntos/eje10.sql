-- Asignaturas de  m�s de 6 cr�ditos y que han tenido alumnos en el curso 2014-2015

select asi# from asigna where credt+credpr >6
    intersect
select codasi# from matricula where curso_academico='2014-2015';

