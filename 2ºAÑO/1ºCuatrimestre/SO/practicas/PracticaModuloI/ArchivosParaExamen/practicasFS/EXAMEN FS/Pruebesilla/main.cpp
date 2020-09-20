#include <stdio.h>
#include "funciones.h"

/* programa que genera una secuencia de numeros que es, para cada uno de los 
numeros comprendidos entre los dos dados por teclado, ambos incluidos, la suma con el anterior.
 Si num1=2 y num2=6,  genera 2,5,9,14,20. A continuación, genera la misma serie en orden inverso, 
es decir, 20,14,9,5,2 */

int main ()
{
 int serie;
 int serie2;
 int num1;
 int num2;
 printf("Primer elemento: ");
 scanf("%d",&num1);  /* leo el primer numero desde el terminal*/
 serie = num1;
 serie2 = num1;
 printf("Ultimo elemento: "); /* leo el segundo numero desde el terminal*/
 scanf("%d",&num2); 
 while(num1<=num2)
 {
  printf("%d,",serie);
  num1=suma(num1,1);
  serie=suma(serie,num1);
 }
printf("\nFin de la serie\n");
serie=resta(serie,num2)-1; //break
 while(serie>=serie2)
 { //break
 printf("%d,",serie);
 serie=resta(serie,num2);
 num2=resta(num2,1);
 } //break
printf("\nFin de la serie al revés\n");
}
