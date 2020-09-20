

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>

int main(int argc, char * argv[]){
	if(argc < 3){
		printf("Error de argumentos\n");
		printf("Sintaxis: %s <numero> <ruta_directorio1> <ruta_directorio2> <...> <ruta_directorioN> \n", argv[0]);
		return (EXIT_FAILURE);
	}else{
		struct stat atributos;
		int fd[2];
		pid_t PID;
		int total_argumentos = argc;
		int suma_tamanios_rutas = 0;
		int suma_espacio_desaprovechado = 0;
		int estado;

		pipe(fd); //Llamada al sistema para crear un cauce sin nombre
		
		while(total_argumentos < 2){ // voy decrementando hasta el segundo argumento, para que solo coja la ruta de los directorios
			if( PID = fork() < 0){
				perror("Error en fork");
				exit -1;
			}

			if( PID == 0){ //HIJO
				close(fd[0]); //Cierre del descriptor de lectura en el proceso hijo
				write(fd[1], "lo que quieras enviar", strlen(de eso));

				if( (execl("./lslen", "lslen", argv[1], argv[total_argumentos], NULL) <0)) { //Lanzo los procesos hijos con la ejecucion de lslen
					perror("\nError en el execl");
					exit(-1);
				}
				exit 0;
			}

			char cadena[strlen(argv[total_argumentos] + 1)];
			//sprintf(cadena,"%s", argv[total_argumentos]);
			write(cadena, argv[total_argumentos], strlen(argv[total_argumentos] + 1));

			if(stat(cadena, &atributos) < 0){ //Abro la estructura de datos
				perror("Error en abrir los atributos(lstat)\n");
				exit(EXIT_FAILURE);
			}

			printf("NOMBRE: %s\n", cadena); //Imprimo el nombre
			printf("TAMANIO EN BYTES: %d", atributos.st_size);
			printf("NUMERO DE BLOQUES DE 512 OCUPADOS: %d", atributos.st_blocks); //nº de bloques de 512 ocupados

			suma_tamanios_rutas += atributos.size;
			suma_espacio_desaprovechado += (atributos.st_size - atributos.st_blocks);
			
			
			wait(&estado);
			printf("\nMi hijo %d ha finalizado con el estado %d\n",PID,estado);

			total_argumentos--;
		}
		
		printf("Tamaño de todas las rutas leidas: %d\n", suma_tamanios_rutas);
		printf("Suma del espacio desaprovechado de todas las rutas: %d\n", suma_espacio_desaprovechado);
		
	}
}
