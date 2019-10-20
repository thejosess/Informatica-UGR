/*
	¿Bajo qué condiciones puede un árbol ser parcialmente ordenado y binario de 
	búsqueda simultáneamente? Razona la respuesta.
*/

//Un montículo o heap es un árbol binario completo, y parcialmente ordenado. 
//Un árbol parcialmente ordenado, no es mas que aquel que tiene absolutamente 
//todas sus ramas, las cuales se consideran listas y ordenadas, ya sea de manera 
//creciente o decreciente, con lo cual se puede dar lugar a una definición, 
//incluso mas natural de heap, es decir, un heap es un heap es un árbol binario 
//completo, y el valor de su raíz siempre será mayor o igual que las raíces de 
//sus hijos, y cada hijo es un heap también
