--Alumnos matriculados en asignaturas del �ltimo curso (Dos soluciones)



select distinct dni from matricula where 
codasi# in (select asi# from asigna where curso >=all (select asi.curso from asigna asi));




