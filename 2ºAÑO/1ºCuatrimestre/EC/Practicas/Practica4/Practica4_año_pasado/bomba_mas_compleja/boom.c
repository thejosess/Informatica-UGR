// gcc -Og boom.c -o boom -no-pie -fno-guess-branch-probability
char password[]="patadecabra\n";	// contraseña
int  passcode  = 101010;			// pin

void defused(void){
	printf(	"\n"
		"***************\n"
		"*** BOOM!!! ***\n"
		"***************\n"
		"\n");
	exit(-1);
}

void boom(void){
	printf(	"\n"
		"·························\n"
		"··· bomba desactivada ···\n"
		"·························\n"
		"\n");
	exit(0);
}

_Bool comprobar(char pw[SIZE])
{
	return strncmp(pw,password,sizeof(password));
}

_Bool comprobar1(int n)
{
	return n!=1 ;
}

_Bool comprobar2(int pc)
{
	return pc != passcode;
}

int main(){
	char pw[SIZE];
	int  pc, n;

	struct timeval tv1,tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1,NULL);

	do	printf("\nIntroduce la contraseña: ");
	while (	fgets(pw, SIZE, stdin) == NULL );
	if    (comprobar(pw))
	    defused();

	gettimeofday(&tv2,NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM )
	    defused();

	do  {	printf("\nIntroduce el pin: ");
	 if ((n=scanf("%i",&pc))==0)
		scanf("%*s")    ==1;         }
	while (	comprobar1(n) );
	if    (	comprobar2(pc)
	    defused();

	gettimeofday(&tv1,NULL);
	if    ( tv1.tv_sec - tv2.tv_sec > TLIM )
	    defused();

	boom();
}
