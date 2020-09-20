#include<sys/types.h> //Primitive system data types for abstraction of implementation-dependent data types.
//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>    //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

	int nprocs = 20, pid, childpid, i;

	if(argv[1] == 1)
	{

		/*
		Jerarquía de procesos tipo 1
		*/
		for (i=1; i < nprocs; i++) 
		{
			if ((childpid= fork()) == -1) {
			fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
			exit(-1);
			}
		}

		if (childpid)		//duda de esto
			break;

			printf("Mi pid es :  %i\n", getpid());
			printf(" el de mi padre es :  %i\n", getppid());

	}


	if(argv[1] == 2)
	{
		/*
		Jerarquía de procesos tipo 2
		*/
		for (i=1; i < nprocs; i++) 
		{
			if ((childpid= fork()) == -1) 
			{
				fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
				exit(-1);
			}
		}

		if (!childpid)
			break;
			printf("Mi pid es :  %i\n", getpid());
			printf(" el de mi padre es :  %i\n", getppid());
	}
}
