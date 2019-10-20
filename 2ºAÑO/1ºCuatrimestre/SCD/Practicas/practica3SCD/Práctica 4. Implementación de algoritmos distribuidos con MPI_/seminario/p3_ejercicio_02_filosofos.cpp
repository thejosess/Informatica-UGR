/******************************************************************************
 *
 * SCD - Sistemas Concurrentes y Distribuidos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  El problema de los filosofos con paso de mensajes Open-MPI
 *
 *  Más información en:
 *  https://es.wikipedia.org/wiki/Problema_de_la_cena_de_los_fil%C3%B3sofos
 *
 ******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h> // Funciones para poder llamar sleep()
#include "mpi.h"

using namespace std;

// Atributos
#define soltar     0
#define coger      1

// Colores ansi para la consola
#define BLACK    "\033[0m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE     "\033[34m"
#define MAGENTA  "\033[35m"
#define CYAN     "\033[36m"
#define WHITE    "\033[37m"

// Metodos
void Filosofo(int id, int nprocesos); // Codigo proc. Filosofo
void Tenedor (int id, int nprocesos); // Codigo proc. Tenedor

// Punto de entrada al programa
int main(int argc, char** argv)
{
    // Inicialización de open-mpi
    int rank,size;
    srand(time(0));
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Controlamos que estemos llamando correctamente al programa
    if (size != 10)
    {
        if (rank == 0) // Solo mostramos el mensaje 1 vez
            cout << "El numero de procesos debe ser 10" << endl;
        MPI_Finalize();
        return 0;
    }

    if (rank%2 == 0)
        Filosofo(rank,size); // los pares son filosofos
    else
        Tenedor(rank,size); // los impares son tenedores


    // Finalización de open-mpi
    MPI_Finalize();

    // Fin del programa
    return 0;
}

void Filosofo(int id, int nprocesos)
{
    int izq = (id+1) % nprocesos;
    int der = (id+nprocesos-1) % nprocesos;
    while (true)
    {
        // El primer filosofo deberá de coger los tenedores al revés para que no haya interbloqueo
        if (id == 0)
        {
            // solicita tenedor derecho
            cout << GREEN << "Filosofo " << id << " coge tenedor der. " << der << BLACK << endl;
            MPI_Ssend(NULL, 0, MPI_INT, der, coger, MPI_COMM_WORLD);

            // solicita tenedor izquierdo
            cout << RED << "Filosofo " << id << " solicita tenedor izq. " << izq << BLACK << endl;
            MPI_Ssend(NULL, 0, MPI_INT, izq, coger, MPI_COMM_WORLD);
        }
        else
        {
            // solicita tenedor izquierdo
            cout << RED << "Filosofo " << id << " solicita tenedor izq. " << izq << BLACK << endl;
            MPI_Ssend(NULL, 0, MPI_INT, izq, coger, MPI_COMM_WORLD);

            // solicita tenedor derecho
            cout << GREEN << "Filosofo " << id << " coge tenedor der. " << der << BLACK << endl;
            MPI_Ssend(NULL, 0, MPI_INT, der, coger, MPI_COMM_WORLD);
        }


        cout << "Filosofo " << id << " COMIENDO" << BLACK << endl;
        sleep((rand()%3)+1); // comiendo

        // suelta el tenedor izquierdo
        cout << RED << "Filosofo "<<id<< " suelta tenedor izq. " << izq << BLACK << endl;
        MPI_Ssend(NULL, 0, MPI_INT, izq, soltar, MPI_COMM_WORLD);


        // suelta el tenedor derecho
        cout << GREEN << "Filosofo " << id << " suelta tenedor der. " << der << BLACK << endl;
        MPI_Ssend(NULL, 0, MPI_INT, der, soltar, MPI_COMM_WORLD);


        cout << "Filosofo " << id << " PENSANDO" << BLACK << endl;
        sleep((rand()%3)+1); // pensando
    }
}

void Tenedor(int id, int nprocesos)
{
    int buf, Filo;
    MPI_Status status;
    while (true)
    {
        // Espera un peticion desde cualquier filosofo vecino ...
        MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, coger, MPI_COMM_WORLD, &status);

        // Recibe la peticion del filosofo ...
        Filo=status.MPI_SOURCE; // Obtiene el rank del filosofo
        cout << BLUE << "Ten. " << id << " recibe petic. de " << Filo << BLACK << endl;

        // Espera a que el filosofo suelte el tenedor...
        MPI_Recv(&Filo, 1, MPI_INT, Filo, soltar, MPI_COMM_WORLD, &status);
        cout << BLUE << "Ten. " << id << " recibe liberac. de " << Filo << BLACK << endl;
    }
}

