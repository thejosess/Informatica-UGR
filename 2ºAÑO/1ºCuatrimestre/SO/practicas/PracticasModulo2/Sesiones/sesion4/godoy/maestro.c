#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
int fd1[2];
int fd2[2];
int bytesLeidos, bytesLeidos2, val1, val2;
pid_t esclavo1, esclavo2;
int intervalos[6];
char ini[10];
char fin[10];
if (argc < 3){
perror("Uso: ./maestro <inicio> <fin>\n");
exit(-1);
}
// División de intervalos:
intervalos[0] = atoi(argv[1]);
// Maestro ini.
intervalos[1] = atoi(argv[2]);
// Maestro fin.
intervalos[2] = intervalos[0];
// Esclavo1 ini.
intervalos[3] = ((intervalos[1]+intervalos[0]) / 2) - 1; // Esclavo1 fin.
intervalos[4] = intervalos[3] + 1; // Esclavo2 ini.
intervalos[5] = intervalos[1];
// Esclavo2 fin.
// Se crean dos cauces.
pipe(fd1);
pipe(fd2);
printf("\nNúmeros primos en el intervalo [%d,%d]:\n", intervalos[0],
intervalos[1]);
// Primer esclavo
esclavo1 = fork();
sprintf(ini, "%d", intervalos[2]);
sprintf(fin, "%d", intervalos[3]);
if (esclavo1 == 0){ // Proceso hijo1.
close(fd1[0]); //Cierro descriptor de lectura
dup2(fd1[1],STDOUT_FILENO);
if(execl("./esclavo", "esclavo", ini, fin, NULL) < 0) {
perror("\nError en el execl");
exit(-1);
}
}else{ // Proceso padre.
close(fd1[1]); // Se cierra el descriptor de escritura
while((bytesLeidos = read(fd1[0],&val1, sizeof(int))) > 0){
printf("%d ", val1);
}
close(fd1[0]);
printf("\n");
}
// Segundo esclavo
esclavo2 = fork();
sprintf(ini, "%d", intervalos[4]);
sprintf(fin, "%d", intervalos[5]);
if (esclavo2 == 0){
close(fd2[0]); //Cierro descriptor de lectura
dup2(fd2[1],STDOUT_FILENO);
if(execl("./esclavo", "esclavo", ini, fin, NULL) < 0) {
perror("\nError en el execl");
exit(-1);
}
}else{ // Proceso padre.
close(fd2[1]);
// Se cierra el descriptor de escritura.
while((bytesLeidos2 = read(fd2[0],&val2, sizeof(int))) > 0){
printf("%d ", val2);
}
close(fd2[0]);
printf("\n");
}
return 0;
}
