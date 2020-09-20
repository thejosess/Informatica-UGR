

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
	if(argc != 3){
		printf("Error de argumentos\n");
		printf("Sintaxis: %s <numero> <ruta_directorio> \n", argv[0]);
		return (EXIT_FAILURE);
	}else{
		DIR *directorio;
		struct dirent *entrada;
		struct stat atributos;

		if( (directorio = opendir(argv[2]) ) == NULL ){ //Compruebo si se ha podio abrir el directorio
			perror("Error al abrir el directorio\n");
			exit(EXIT_FAILURE);
		}

		char ruta[100];
		while( (entrada = readdir(directorio)) != NULL){ //Leo la estructura del directotio
			sprintf(ruta,"%s/%s", argv[2], entrada->d_name);

			if( strlen(ruta)+1 == atoi(argv[1])){ //strlen + 1, para leer el nulo final
				printf("%s\n", ruta);
			}
	
			//Acceso a los atibutos
			if(stat(ruta, &atributos) < 0){
				perror("Error en abrir los atributos(lstat)\n");
				exit(EXIT_FAILURE);
			}

			mode_t permisos = atributos.st_mode | S_IRWXG;
			//Cambio de permisos
			if(chmod(ruta, permisos) < 0){
				perror("Error en chmod\n");
				exit(EXIT_FAILURE);
			}
		}
		//Una vez terminado cierro el directorio
		closedir(directorio);
	return 0;
	}
}
