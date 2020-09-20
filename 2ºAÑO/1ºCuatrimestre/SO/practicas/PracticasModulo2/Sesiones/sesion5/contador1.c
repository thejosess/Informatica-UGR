#include <stdio.h>
#include <signal.h>
static int j;
static int contadores[31];

static void manejadir (int i)
{
	contadores[i]++;
	printf("\n La señal %d , se ha realizado %d veces. " , i ,
	contadores[i]);
}
int main()
{
	struct sigaction sa;
	sa.sa_handler = manejadir; // ignora la señal
	sigemptyset(&sa.sa_mask);
	//Reiniciar las funciones que hayan sido interrumpidas por un manejador
	sa.sa_flags = SA_RESTART;
	int contadores[31];
	for ( j = 1 ; j<=31 ; j++)
	contadores[j] = 0;
	int i;
	for ( i = 1 ; i<=60 ; i++){
	if (sigaction(i, &sa, NULL) == -1)
	{
	printf("error en el manejador");}}while(1);
}
