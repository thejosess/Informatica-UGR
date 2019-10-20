#include<stdio.h>



void imprimir_asteriscos_superiores(int n)

{

 int i;

 for(i=1;i<=2*n-1;i++)

 {

  printf(" ");

 }

}

void imprimir_asteriscos_inferiores(int n)

{

  int i;

 for(i=2*n-1;i>=1;i--)

 {

  printf(" ");

 }

}

void ordenar_asteriscos_superiores(int A)

{

 int i,j,k;

 for(i=1;i<=A;i++)

 {

     for(j=1;j<=A-i;j++)

  {

  printf("*");

        }

  imprimir_asteriscos_superiores(i);



  for(k=1;k<=A-i;k++)



  {

   printf("*");

  }

  printf("\n");



 }

}



void ordenar_asteriscos_inferiores(int A) // función que ordena los asteriscos inferiores



{

    int i,j,k;

 for(i=1;i<A;i++)

 {

     for(j=A-1;j>=A-i;j--)

  {

  printf("*");

        }

  imprimir_asteriscos_inferiores(A-i);

  for(k=A-1;k>=A-i;k--)

  {

   printf("*");

  }

  printf("\n");

 } 

}

int main()

{

 int A;

 printf("ingresar n: ");

 scanf("%d",&A);

 printf("\n\n");

// llamando a las funciones

 ordenar_asteriscos_superiores(A+1);

 ordenar_asteriscos_inferiores(A+1);

 return 0;



}
