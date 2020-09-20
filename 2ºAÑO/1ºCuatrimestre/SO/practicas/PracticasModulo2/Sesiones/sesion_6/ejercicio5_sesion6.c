#include<sys/types.h>  	//Primitive system data types for abstraction of implementation-dependent data types.
//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    struct stat atributos;//estructura de los atributos de archivos
    int fd1;//descriptor de archivo del primer archivo
    int fd2;//descriptor de archivo del segundo archivo
    int tama;//ambos archivos tiene el mismo tamaño
    char *memoria1,*memoria2;
    umask(0);
    if (argc<3) {//controlamos los argumentos
        printf("Falta de argumentos\n");
    }

    if ((fd1=open(argv[1],O_RDONLY, S_IRWXU))<0) {//abierto solo para lectura
        printf("\nError %d en open",errno);
        perror("\nError en open");
        exit(-1);
    }

    umask(0);

    if ((fd2=open(argv[2],O_CREAT|O_RDWR,S_IRWXU))<0) {//abierto para escritura.
        printf("\nError %d en open",errno);
        perror("\nError en open");
        exit(-1);
    }
    if (stat(argv[1],&atributos) < 0) {//tomamos los atributos del archivo pasado como primer argumento
        printf("\nError al intentar acceder a los atributos de %s",argv[1]);
        perror("\nError en lstat");
    }
    tama=atributos.st_size;//igualamos tama al tamaño del archivo abierto para lectura

	//gestionamos la memoria para el segundo archivo abierto para escritura
    printf ("Ajustando el tamano archivo %s a %d \n",argv[2],tama);
    ftruncate(fd2, tama);//trunca el tamaño de fd a i, si i es mayor que tamaño del archivo se rellena con NULL


	//abrimos la proyeccion del primer archivo para lectura, de forma compartida
    memoria1 = (char *)mmap(0, tama, PROT_READ, MAP_SHARED, fd1, 0);
    if (memoria1 == MAP_FAILED) {//retorna en memoria la direccion principal de la proyeccion
        perror("Fallo la proyeccion1");//si fallo devuelve MAP_FAILED
        exit(-1);
    }

	//abrimos la proyeccion del segundo archivo para escritura, de forma compartida
    memoria2 = (char *)mmap(0, tama,PROT_WRITE, MAP_SHARED, fd2, 0);
    if (memoria2 == MAP_FAILED) {//retorna en memoria la direccion principal de la proyeccion
        perror("Fallo la proyeccion2");//si fallo devuelve MAP_FAILED
        exit(-1);
    }

	//copiamos los archivos a traves de memoria
    printf ("Copiando del archivo %s al archivo %s\n",argv[1],argv[2]);
    memcpy(memoria2,memoria1,tama);

    if (munmap (memoria1, tama) == -1) {//cerrar la proyeccion.
        printf("Error al cerrar la proyeccion \n");
        exit(-1);
    }
    if (munmap (memoria2, tama) == -1) {//cerrar la proyeccion.
        printf("Error al cerrar la proyeccion \n");
        exit(-1);
    }
     return 0;

}
