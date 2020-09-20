

//1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <math.h>

int esPrimo(int n){
	int i;
	int limite = sqrt(n);
	int es_primo = 1;
	for (i = 2; i <= limite && es_primo; i++)
		if (n % i == 0)
			es_primo = 0;
	return es_primo;
};

int main(int argc, char *argv[]){
	DIR *directorio;
	struct dirent *entrada;
	struct stat estado;
	char *nombre_fichero;
	int numero_inodo;

	if((directorio = opendir(".")) == NULL){	// Abrir el directorio actual
		perror("Error al intentar abrir el directorio actual\n");
		exit(-1);
	}

	while((entrada = readdir(directorio)) != NULL){	// Guarda en entrada el dirent del directorio
			if(stat(entrada->d_name, &estado) < 0){		// Obtiene los metadatos de entrada y los guarda en estado 
				perror("Error al recuperar información del fichero\n");
				exit(-1);
			}

			if(S_ISDIR(estado.st_mode)){	// Comprueba si es un directorio
				if (strcmp(entrada->d_name, ".") == 0 ){
					numero_inodo = estado.st_ino;	// Cogemos el inodo
					printf("Directorio: %s \nNumero de inodo: %d \n", entrada->d_name ,numero_inodo);
				}
			}
	
	}

	closedir(directorio);		// cierra el directorio


//Apartado 2 y 3
	numero_inodo = numero_inodo % 10000;
	int fd2[2], fd3[2], numeros_leidos, primo;
	pid_t pid;
	char n_inodo[256], n_primo[256];

	sprintf(n_inodo,"%d",numero_inodo);

	if(pipe(fd2) < 0){	// Crear cauce para apartado 2
		perror("Error al crear el cauce\n");
		exit(-1);
	}

	if(pipe(fd3) < 0){	// Crear cauce para apartado 3
		perror("Error al crear el cauce\n");
		exit(-1);
	}

	if((pid = fork()) < 0){		// Crear proceso hijo
		perror("Error al crear el proceso hijo\n");
		exit(-1);
	}
	
	//padre
	if(pid){
		if(close(fd2[0]) < 0){	
			perror("Error al cerrar el cauce de lectura en el padre\n");
			exit(-1);
		}

		if(write(fd2[1], n_inodo, 256) < 0){	// Escribimos / pasamos al hijo
			perror("Error al escribir en el cauce\n");
			exit(-1);
		}
		
		close(fd2[1]);
	}
	//hijo
	else{	

		if(close(fd2[1]) < 0){
			perror("Error al cerrar el cauce de escritura en el hijo\n");
			exit(-1);
		}

		if(read(fd2[0], n_inodo, 256) < 0){	// Leemos / recibimos del padre
			perror("Error al leer del cauce\n");
			exit(-1);
		}

		printf("El hijo ha recibido el i-nodo modulo 10000 --> %s \n", n_inodo);
		close(fd2[0]);

	}

	if(strcmp(argv[1], "2") != 0){	//Apartado 3
		if(pid){//padre
			if(close(fd3[1]) < 0){	
				perror("Error al cerrar el cauce de escritura en el padre\n");
				exit(-1);
			}

			while((numeros_leidos = read(fd3[0],&primo, sizeof(int))) > 0){
				printf("%d ", primo);
			}
			printf("\n");
			close(fd3[0]);
		}
		else{ //hijo
			if(close(fd3[0]) < 0){
				perror("Error al cerrar el cauce de escritura en el hijo\n");
				exit(-1);
			}

			int inicio, fin, i;
			inicio = 1;
			fin = numero_inodo;
			printf("El hijo envia los numeros primos entre %d y %d: \n",inicio, fin);
			for (i = inicio; i <= fin; i++)
				if (esPrimo(i))
					write(fd3[1], &i, sizeof(int));

			close(fd3[1]);
		}
	}
	else{ //Apartado 4

		if(pid){
			if(close(fd2[0]) < 0){	
				perror("Error al cerrar el cauce de lectura en el padre\n");
				exit(-1);
			}

			if(write(fd2[1], n_inodo, 256) < 0){	// Escribimos / pasamos al hijo
				perror("Error al escribir en el cauce\n");
				exit(-1);
			}
		
			close(fd2[1]);
		}
		//hijo
		else{	
			if(close(fd2[1]) < 0){
				perror("Error al cerrar el cauce de escritura en el hijo\n");
				exit(-1);
			}

			if(read(fd2[0], n_inodo, 256) < 0){	// Leemos / recibimos del padre
				perror("Error al leer del cauce\n");
				exit(-1);
			}
			
			int fd4;
			fd4 = open("temporal_primos.txt", O_CREAT|O_TRUNC|O_WRONLY, ​S_IRUSR|S_IWUSR);
			struct flock cerrojo;
			cerrojo.l_type = F_WRLCK;
			cerrojo.l_whence = SEEK_SET;
			cerrojo.l_start = 0;
			cerrojo.l_len = 0;
/* ejercicio programa1-Tarea13-prac6.c resultos sesion6*/			while (fcntl(fd4, F_SETLK, &cerrojo) == -1) { /*si el cerrojo falla, vemos quien lo bloquea*/
				while(fcntl(fd, F_GETLK, &cerrojo) != -1 && cerrojo.l_type != F_UNLCK ) {
					printf(“%s bloqueado por %d desde %d hasta %d para %c”, *argv,
					cerrojo.l_pid, cerrojo.l_start, cerrojo.l_len,
					cerrojo.l_type==F_WRLCK ? 'w':'r'));
					if (!cerrojo.l_len) break;
					cerrojo.l_start +=cerrojo.l_len;
					cerrojo.l_len=0;
				} /*mientras existan cerrojos de otros procesos*/
			} /*mientras el bloqueo no tenga exito */
			/* Ahora el bloqueo tiene exito y podemos procesar el archivo */

			for (i = inicio; i <= fin; i++)
					if (esPrimo(i))
						write(fd4, &i, sizeof(int));

			/* Una vez finalizado el trabajo, desbloqueamos el archivo entero */
			cerrojo.l_type =F_UNLCK;
			cerrojo.l_whence =SEEK_SET;
			cerrojo.l_start =0;
			cerrojo.l_len =0;

			if (fcntl(fd, F_SETLKW, &cerrojo) == -1) perror("Desbloqueo");

				printf("El hijo ha recibido el i-nodo modulo 10000 --> %s \n", n_inodo);
				close(fd2[0]);

			}	
			close(fileDirectory);	
	}

//falta el wait de los procesos hijos
	wait(NULL); //esperando cambio en el hijo
	//ejercicio 4 sesion 3 mios
//ejercicio directorios sesion 2
	return 0;
}

