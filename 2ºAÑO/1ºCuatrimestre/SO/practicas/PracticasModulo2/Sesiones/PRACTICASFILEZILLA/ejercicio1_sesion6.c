
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

//ejercicio 8 sesion 4

int main(int argc, char *argv[])
{
	int fentrada;

	if(argc != 4)
	{
		printf("Sintaxis incorrecta: ./exe sort < o > archivo\n");
		return 1;
	}

	if(argv[2] == ">")//funciones comparacion de string de la libreria
	{
		fentrada=open("hola.txt", O_WRONLY);
		close(1);	//cerramos salida estandar

		if(fcntl(fentrada,F_DUPFD, 1) == -1) perror("Fallo en fcntl");
		{
			execlp("sort","sort","sort.txt",NULL);
			//en vez de NULL se pasa los argumentos que se desee
		}
	}
	return 0;

//MIRAR LAS COMPROBACIONES DE LOS IF Y NO ENTRA EN EL OPEN
// strace y la ejecucion
}
