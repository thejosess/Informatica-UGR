#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main (int argc, char * argv[])
{
    char nada[5];
    struct flock cerrojo;//estructura del cerrojo
    int i,fd;//descriptor de archivo
    for( i=1; i<argc; i++) {

        if ((fd=open(argv[i], O_RDWR)) == -1 ) {//abrimos el archivo para escritura
            perror("open fallo");
            continue;
        }
		//creamos la estructura del cerrojo
        cerrojo.l_type=F_WRLCK;//cerrojo para escritura
        cerrojo.l_whence=SEEK_SET;//
        cerrojo.l_start=0;	  //archivo completo
        cerrojo.l_len=0;	  //

        /* intentamos un bloqueo de escritura del archivo completo */

        if((fcntl (fd, F_SETLKW, &cerrojo) )== -1) {
            if(errno==EDEADLK)
                printf("ha detectado interbloqeo EDEADLK\n");

        }
        printf ("cerrojo puesto sobre el archivo %s\n",argv[i]);
        printf ("pulse cualquier tecla\n");
        scanf("%s",nada);

        sleep(1);//hacemos sleep para ver apreciar con mas detalle.

        /*  no desbloqueamos
         cerrojo.l_type=F_UNLCK;
         cerrojo.l_whence=SEEK_SET;
         cerrojo.l_start=0;
         cerrojo.l_len=0;
         if (fcntl (fd, F_SETLKW, &cerrojo) == -1) perror ("Desbloqueo");
        */
    }
    return 0;
}
