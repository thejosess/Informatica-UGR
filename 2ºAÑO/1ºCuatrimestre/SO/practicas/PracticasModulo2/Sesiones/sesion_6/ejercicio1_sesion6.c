
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

//ejercicio 8 sesion 4 similar

int main(int argc, char *argv[])
{
	int fentrada;

	if(argc != 4)
	{
		printf("Sintaxis incorrecta: ./exe sort < o > archivo\n");
		return 1;
	}

// ./exe6 sort ">" hola.txt

	if(strcmp(argv[2],">")==0)//funciones comparacion de string de la libreria
	{
		fentrada=open("hola.txt", O_WRONLY);
		close(1);	//cerramos salida estandar

		if(fcntl(fentrada,F_DUPFD, 1) == -1) perror("Fallo en fcntl");
		{
			execlp("sort","sort","sort.txt",NULL); //usa la salia de fichero
			//en vez de NULL se pasa los argumentos que se desee
		}
	}

//./exe6 sort "<" hola.txt

	if(strcmp(argv[2],"<")==0)
	{
		fentrada=open("hola.txt",O_RDONLY);
		close(0);	//cerramos entrada estandar

		if(fcntl(fentrada,F_DUPFD, 0) == -1) perror("Fallo en fcntl");
		{
			execlp("sort","sort",NULL);	//usa la entrada del fichero para ejecu	
			//en vez de NULL se pasa los argumentos que se desee
		}			


	}
	return 0;

//MIRAR LAS COMPROBACIONES DE LOS IF Y NO ENTRA EN EL OPEN
// strace y la ejecucion
}
