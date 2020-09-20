#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/stat.h>

#include<fcntl.h>
#include<errno.h>

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main(int argc, char *argv[])
{

int fd ;

fd = open(home/santossalvador/Escritorio/Home/SO/SO-P-Todos_MaterialModulo2/Sesion1/prueba.txt, O_CREAT, S_IROTH) ;

return 0 ;
}
