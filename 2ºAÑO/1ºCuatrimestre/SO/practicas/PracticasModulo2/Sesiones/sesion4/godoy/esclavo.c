#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<math.h> // gcc esclavo.c -o esclavo -lm
#include<sys/types.h>

int esPrimo(int n)
{
	int i;
	int limite = sqrt(n);
	int es_primo = 1;

	for (i = 2; i <= limite && es_primo; i++)
		if (n % i == 0)
		es_primo = 0;
		return es_primo;
};
int main(int argc, char *argv[]){
int inicio, fin, i;

inicio = atoi(argv[1]);
fin = atoi(argv[2]);

for (i = inicio; i < fin; i++)
	if (esPrimo(i))
	write(STDOUT_FILENO, &i, sizeof(int));
return 0;

}
