#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fentrada, fdsalida , terminar;
	int contador = 1 ;
	int num_caracteres = 1 ;
	char caracter[80] ;
	char bloque[50] ;

	if (argc==2)
	{
		fentrada=open(argv[1], O_RDONLY);
	}
	else
	{
		fentrada=STDIN_FILENO; // es para la salida estandar
	}

	fdsalida=open("archivo_bloque80", O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR);
	
	if (fdsalida < 0)
	{
		printf("El fichero de salida no se pudo abrir correctamente\n");
		perror("\nEl fichero de salida no se pudo abrir correctamente");
		exit(-1);
	}

	while((terminar=read(fentrada,caracter,80)) != 0)
	{
		sprintf(bloque,"%s%d\n", "Bloque ", contador) ;
		write(fdsalida,bloque, strlen(bloque)) ;
		write(fdsalida, "\n", strlen("\n"));
		write(fdsalida,caracter,strlen(caracter)) ;
		contador ++ ;
	}


	sprintf(bloque, "El numero de bloques es <%d>\n", contador);
	lseek(fdsalida,0,SEEK_SET);
	write(fdsalida, bloque, strlen(bloque));

	close(fdsalida);
	close(fentrada);
	return 0;
}