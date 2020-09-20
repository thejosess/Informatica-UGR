#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define tamano 1024
#define longnombre 50

void proxy(int pid)
{
	char *nombre
	int fd;

	sprintf(nombre, "/tmp/fifo.%d",pid);
	
	mkfifo(nombre,0777);


}	

