--Alumnos matriculados de alguna asignatura optativa ordenados por apellidos y nombre (Dos soluciones)

select distinct alumnos.dni,ape1,ape2,nombre from matricula,alumnos
where alumnos.dni=matricula.dni 
      and codasi# in (select asi# from asigna where caracter='op') 
order by ape1,ape2,nombre;


