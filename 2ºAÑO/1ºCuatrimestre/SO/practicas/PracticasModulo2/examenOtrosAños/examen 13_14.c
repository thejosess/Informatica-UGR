/*

Parte Obligatoria Mínima (50%):
	Construir un único programa que cree un proceso hijo. Ambos procesos utilizarán un cauce con/sin
	nombre para comunicarse (el tipo de cauce a vuestra elección). Donde el trabajo de cada proceso es:
		- El padre: Lee el directorio actual y para cada archivo regular contenido en el mismo:
			1. obtiene e imprime en pantalla su número de inodo junto con el UID del propietario.
			2. escribe el nombre del archivo en el cauce.
		- El hijo: Lee del cauce el nombre del archivo escrito por el padre, el lo lee entero mediante el
		  mecanismo de proyección de archivos. Tras lo cual, muestra en pantalla su contenido.

Ampliación:
(15%)	El padre se asegura que los archivos cuyo nombre va a pasar al hijo tienen permiso de lectura
		para el proceso, si no fuese así, lo cambia para que los pueda leer el hijo.
(15%)	Establecer un manejador para la señal SIGPIPE en el padre en caso de que el proceso hijo
		finalice inesperadamente de forma que se indique el evento por pantalla.
(20%)	El acceso al archivo por parte del proceso hijo es exclusivo, es decir, bloqueará el archivo
		antes de acceder al mismo y lo bloqueará al finalizar.

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


//EOOO
//Me acabo de dar cuenta que tiene dos cosas mal escritas pero es básicamente que pone setkl en vez de setlk y unlock en vez de unlck


void manejador(int s){
	printf("Mi hijo ha finalizado de forma inesperada:$\n");
}

int main(){
	int fd[2];
	pid_t pid;

	if(pipe(fd) < 0){	// Crear cauce
		perror("Error al crear el cauce\n");
		exit(-1);
	}

	if((pid = fork()) < 0){		// Crear proceso hijo
		perror("Error al crear el proceso hijo\n");
		exit(-1);
	}
	
	//padre
	if(pid){
		DIR *directorio;
		struct dirent *entrada;
		struct stat estado;
		struct sigaction senial;
		senial.sa_handler = manejador;

		if(sigaction(SIGPIPE, &senial, NULL) < 0){
			perror("ERROR\n");
			exit(-1);
		}

		// Cerramos el cauce de lectura en el padre y el de escritura en el hijo
		if(close(fd[0]) < 0){	
			perror("Error al cerrar el cauce de lectura en el padre\n");
			exit(-1);
		}

		if((directorio = opendir(".")) == NULL){	// Abrir el directorio actual
			perror("Error al intentar abrir el directorio actual\n");
			exit(-1);
		}

		while((entrada = readdir(directorio)) != NULL){	// Guarda en entrada el dirent del directorio
			if(stat(entrada->d_name, &estado) < 0){		// Obtiene los metadatos de entrada y los guarda en estado 
				perror("Error al recuperar información del fichero\n");
				exit(-1);
			}

			if(S_ISREG(estado.st_mode)){	// Comprueba si es un archivo regular
				int ino = estado.st_ino;	// Cogemos el inodo
				int dev = estado.st_dev;	// Cogemos el número de dispositivo(filesystem)
				printf("Numero de inodo: %d \tUID: %d\n", ino, dev);

				if(estado.st_mode & S_IROTH != S_IROTH){	// Si other no tiene permiso de lectura
					mode_t permisos = estado.st_mode|S_IROTH;	// Máscara para dar permisos a other

					if(chmod(entrada->d_name, permisos) < 0){	// Aplica la máscara de permisos
						perror("No se le pudieron cambiar los permisos al archivo\n");
						exit(-1);
					}
				}

				if(write(fd[1], entrada->d_name, 256) < 0){	// Escribimos / pasamos al hijo
					perror("Error al escribir en el cauce\n");
					exit(-1);
				}
			}
		}

		// Una vez acabado cerramos tanto el cauce como el directorio
		close(fd[1]);
		closedir(directorio);
	}

	//hijo
	else{
		int leidos1, leidos2;
		char nombre[256];
		int fileDirectory;
		char bloque[256];
		struct flock cerrojo;
		struct stat atributos;
		char *memoria;

		// Cerramos el cauce de escritura para el hijo, sólo va a recibir (leer)
		if(close(fd[1]) < 0){
			perror("Error al cerrar el cauce de escritura en el hijo\n");
			exit(-1);
		}

		while(leidos1=read(fd[0], nombre, 256) < 0){	// Leemos del flujo de lectura
			cerrojo.l_type = F_RDLCK;	// Creamos un cerrojo de lectura
			cerrojo.l_whence = SEEK_SET;	// Desde el principio
			cerrojo.l_start = 0;
			cerrojo.l_len = 0;				// Hasta EOF

			if((fileDirectory=open(nombre, O_RDONLY)) < 0){	// Abrir el archivo nombre solo para lectura
				perror("Error al recuperar información del fichero\n");
				printf("%s\n", nombre);
				exit(-1);
			}	

			if(fcntl(fileDirectory, F_SETKL, &cerrojo) < 0){	// Poner el cerrojo al fileDirectory
				perror("Error al poner el cerrojo");
				exit(-1);
			}

			printf("\nInformación sobre %s: ", nombre);
			memoria = (char *) mmap(0, atributos.st_size, PROT_READ, MAP_SHARED, fileDirectory, 0);

			if(write(STDOUT_FILENO, memoria, atributos.st_size) < 0){
				perror("Error en la escritura\n");
				exit(-1);
			}

			munmap(memoria, atributos.st_size);
			printf("\n");
			cerrojo.l_type = F_UNLOCK;	// Desbloqueamos el cerrojo

			if(fcntl(fileDirectory, F_SETKL, &cerrojo) < 0){	// Quitamos el cerrojo de fileDirectory
				perror("Error al quitar el cerrojo\n");
				exit(-1);
			}
		}

		//Una vez acabado cerramos el directorio y el cauce
		close(fileDirectory);
		close(fd[0]);
		exit(0);
	}

	wait(NULL);	// Esperamos hasta que se produzca un cambio de estado en el hijo

}
