#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    char *  lockfile = "some_name.lock";

    if ( access( lockfile, F_OK ) != -1 ) {
        puts("Ya se esta ejecutando");
        return 1;
    } else {
        int fd = open(lockfile, O_RDWR|O_CREAT);
        puts("Pulsa ENTER para continuar");
        getchar();    
        remove(lockfile);
        return 0;
    } 

}
