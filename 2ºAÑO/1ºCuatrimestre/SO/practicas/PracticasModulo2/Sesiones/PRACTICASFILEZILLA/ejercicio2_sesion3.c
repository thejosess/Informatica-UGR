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
	int pid;

	if(argc != 2)
	{
		perror("sintaxis incorrecta -> ./exe numero\n");
		return 1;
	}
	else
	{
		int i =  atoi(argv[1]) ;
		printf(" El numero es :  %i \n ",i);

		pid = fork();

		if(pid == 0)
		{
			if(i % 2 == 1)
			{
				printf("El numero es impar\n");
			}
			else
			{
				printf("El numero es par\n");
			}
		}
		else
		{
			if(i % 4 == 0)
			{
				printf("El numero es divisible entre 4\n");
			}
			else
				printf("El numero no es divisible entre 4\n");
		}
		return 0;	
	}
}
