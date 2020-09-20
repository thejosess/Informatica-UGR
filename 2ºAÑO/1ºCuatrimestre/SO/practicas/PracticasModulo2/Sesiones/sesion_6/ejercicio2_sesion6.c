/*
tarea8.c
Programa ilustrativo del uso de pipes y la redirección de entrada y
salida estándar: "ls | sort", utilizando la llamada dup2.
*/

#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{
int fd[2];
pid_t PID;

if(strcmp(argv[2] , "|") != 0)
{
	printf("Error en la sintaxis: ./mi_programa2 ls “|” sort\n");
	return 1;
}

pipe(fd); // Llamada al sistema para crear un pipe

if ( (PID= fork())<0) {
	perror("\Error en fork");
	exit(EXIT_FAILURE);
}

if (PID == 0) { // ls

	close(fd[0]);
	close(1);

	fcntl(fd[1],F_DUPFD, 1);			//escritura
	execlp(argv[1],argv[1],NULL);
}
else { //sort

	close(fd[1]);
	close(0);

	fcntl(fd[0],F_DUPFD, 0);			//lectura
	execlp(argv[3],argv[3],NULL);
}

return EXIT_SUCCESS;
}



