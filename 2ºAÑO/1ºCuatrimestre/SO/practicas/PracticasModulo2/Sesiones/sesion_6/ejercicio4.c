#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int main (int argc, char * argv[])
{
    struct flock cerrojo;//estructura del cerrojo
    int i,fd;//descriptor de archivo
    //bool infinito = true;

    int pid = getpid();

if( (fd=open("ejercicio4.pid",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR))<0) 
{
	printf("\nError %d en open",errno);
	perror("\nError en open");
	exit(-1);
}

if(write(fd,pid,sizeof(int)) != 10) 
{
	perror("\nError en write");
	exit(-1);
}

//close(fd);

        cerrojo.l_type=F_WRLCK;//cerrojo para escritura
        cerrojo.l_whence=SEEK_SET;
        cerrojo.l_start=0;	  
        cerrojo.l_len=0;	  

        if((fcntl (fd, F_SETLKW, &cerrojo) )== -1) 
	{
            printf("Error al hacer un bloqueo de escritura\n");
        }

        /*while(infinito)
	{
		printf("Esperando\n");
	}*/

	// o hacemos sleep??		


        cerrojo.l_type=F_UNLCK;
        cerrojo.l_whence=SEEK_SET;
        cerrojo.l_start=0;
        cerrojo.l_len=0;
        if (fcntl (fd, F_SETLKW, &cerrojo) == -1) perror ("Desbloqueo");

    return 0;
}
