// gcc -Og bomba_JoseSantosSalvador.c -o bomba_JoseSantosSalvador -no-pie -fno-guess-branch-probability


#include <stdio.h>	// para printf(), fgets(), scanf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()
#include <sys/time.h>	// para gettimeofday(), struct timeval
#include <stdbool.h>

#define SIZE 100
#define TLIM 5

char password[]="soyralph\n";	// contraseña
int  passcode  = 2799;			// pin

void boom(void){
	printf(	"\n"
		"***************\n"
		"*** BOOM!!! ***\n"
		"***************\n"
		"\n");
	exit(-1);
}

void defused(void){
	printf(	"\n"
		"·························\n"
		"··· bomba desactivada ···\n"
		"·························\n"
		"\n");
	exit(0);
}

int main(){
	char pw[SIZE];
	int  pc, n;
	bool contrasenaF=true;
	char password1[10] ;
	int final=sizeof(password)-3;
	int i=0;

	while(contrasenaF){
		password1[i]=password[final];
		i++;
		final--;
		if(final<0)
			contrasenaF=false;
	}

	password1[8]='\n';

	struct timeval tv1,tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1,NULL);

	do	printf("\nIntroduce la contraseña: ");
	while (	fgets(pw, SIZE, stdin) == NULL );
	if    (	strncmp(pw,password1,sizeof(password1))!=0 )
	    boom();


	gettimeofday(&tv2,NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM )
	    boom();

	do  {	printf("\nIntroduce el pin: ");
	 if ((n=scanf("%i",&pc))==0)
		scanf("%*s")    ==1;    
			     }		
	while (	n!=1 );

	for(int j=0; j<5;j++){
		pc+=j;
	}
	if    (	pc != passcode )
	    boom();

	gettimeofday(&tv1,NULL);
	if    ( tv1.tv_sec - tv2.tv_sec > TLIM )
	    boom();

	defused();
}
