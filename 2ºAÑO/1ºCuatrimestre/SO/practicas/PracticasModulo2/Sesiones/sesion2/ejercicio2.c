#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	DIR *direct;
	unsigned int permisos;
	char *pathname;
	struct stat atributos;
	struct dirent *ed;
	char cadena[100];
	char cadena2[100];
	extern int errno;

	if (argc==3)
	{
		pathname=argv[1];
		direct=opendir(pathname);
		permisos=strtol(argv[2],NULL,8);
	}
	else
	{
		printf("Uso: ejercicio2.c <pathname> <permisos>\n");
		exit(-1);
	}

	readdir(direct);

	while((ed=readdir(direct))!=NULL)
	{
		sprintf(cadena,"%s/%s",pathname,ed->d_name);

		if(stat(cadena,&atributos) < 0) 
		{
		printf("\nError al intentar acceder a los atributos de archivo");
		perror("\nError en lstat");
		exit(-1);
		}

		if(S_ISREG(atributos.st_mode))
		{
			sprintf(cadena2,"%s",ed->d_name);
			printf("%s: %o ",cadena2,atributos.st_mode);
			chmod(cadena,permisos);
			if(chmod(cadena,permisos) < 0) 
			{
				printf("Error: %s\n",strerror(errno));
			}
			else
			{
				stat(cadena,&atributos);
				printf("%o \n",atributos.st_mode);
			}
		}
	}
	closedir(direct);
	return 0;
}
