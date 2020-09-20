#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

//Constantes
#define tamano 1024
#define longnombre 50
#define BLOCK_FILE "blockfile"

void bloqueodesbloqueo (int dbloqueo, int orden) {
struct flock cerrojo;
// Inicializamos el cerrojo para bloquear todo
cerrojo.l_type= orden;
cerrojo.l_whence= SEEK_SET;
cerrojo.l_start= 0;
cerrojo.l_len = 0;
//Si vamos a bloquearlo y ya lo esta, entonces
if (fcntl(dbloqueo, F_SETLKW, &cerrojo) == -1)
perror ("Proxy: problemas al bloquear para
exit(1);
}
}
el archivo
el proceso duerme
{
impresion");
int main(int argc, char *argv[]){
char buffer[1024];
int nbytes, dbloqueo;
FILE *tmp = tmpfile();
char fifoproxy[256];
// Leer bloques de 1024 bytes y escribirlos en archivo temporal.
while((nbytes = read(STDIN_FILENO, buffer, 1024)) > 0){
fwrite(buffer, sizeof(char), nbytes, tmp);
}
// Abrir archivo "cerrojo".
if ((dbloqueo = open(BLOCK_FILE, O_RDWR)) == -1)
printf("Error al abrir blockfile\n");
// Bloquar cerrojo.
bloqueodesbloqueo(dbloqueo, F_WRLCK);
// Inicio de E.M.
// Leer fichero temporal hasta fin de archivo.
while(!feof(tmp)){
fread(buffer, sizeof(char), 1024, tmp);
// Escribir en la salida estandar.
write(STDOUT_FILENO, buffer, 1024);
}
// Fin de E.M.
// Desbloquear cerrojo.
bloqueodesbloqueo(dbloqueo, F_UNLCK);
// Eliminar su fifo antes de terminar.
sprintf(fifoproxy,"fifo.%d", getpid());
unlink(fifoproxy);
exit(0);
}
