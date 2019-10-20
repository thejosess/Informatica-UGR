#include <iostream>
#include <cmath>
#include "mpi.h"

using namespace std;

// Atributos
#define Productor  1 // Ojo, no es el numero del proceso, sino la etiqueta
#define Consumidor 2 // Idem que la anterior
#define Buffer     5 // Numero del proceso

#define ITERS 20

#define TAM 5

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
void productor(int rank)
{
    // Cada productor produce 4 valores (que por 5 productores serán 20 elementos producidos)
    for(unsigned int i = 0; i < 4; i++)
    {
        // Producimos un valor
        cout << BLUE << "Productor " << rank << " produce valor " << i << endl << BLACK << flush;
        MPI_Ssend(&i, 1, MPI_INT, Buffer, Productor, MPI_COMM_WORLD); // La etiqueta del productor es 1
    }
}

void consumidor(int rank)
{
    int value, peticion=1;
    float raiz;
    MPI_Status status;

    // Cada consumidor consume 5 valores, que por 4 consumidores serán 20 elementos consumidos
    for(unsigned int i = 0; i < 5; i++)
    {

        // De entrada el consumidor envia peticion para recibir datos
        MPI_Ssend(&peticion, 1, MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD);        // La etiqueta de envio a consumidor es 2

        // Una vez aceptada la petición por el buffer le pedimos al mismo que nos mande un valor producido
        MPI_Recv (&value, 1, MPI_INT, Buffer, 0, MPI_COMM_WORLD, &status);  // La etiquete de envio de buffer a consumidor es 0
        cout << RED << "Consumidor " << rank << " recibe valor " << value << " de Buffer " << endl << BLACK << flush;
        raiz = sqrt(value);
        cout << raiz << endl;
    }
}

void buffer()
{
    int value[TAM], peticion, pos=0, rama;
    MPI_Status status;

    for(unsigned int i = 0; i < 40; i++)
    {

        if (pos==0)         // el consumidor no puede consumir, se debe producir
            rama=0;
        else if (pos==TAM)  // el productor no puede producir, se debe consumir
            rama=1;
        else                // en caso contrario...
        {
            // ...se puede consumir o producir
            MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            //if (status.MPI_SOURCE < Buffer) // Se produce
            if (status.MPI_TAG == Productor) //segun la etiqeta que tenga sera un rama o otra.
                rama = 0;
            else
                rama = 1;
        }

        switch(rama)
        {
            case 0 : // Recibe del productor
            {
                // Recibe de cualquiera de los productores (etiqueta 1)
                MPI_Recv(&value[pos], 1, MPI_INT, MPI_ANY_SOURCE, Productor, MPI_COMM_WORLD, &status);
                cout << GREEN << "Buffer recibe " << value[pos] << " de Prod. " << status.MPI_SOURCE << endl << BLACK << flush;
                pos++;
                break;
            }
            case 1 : // Envia al consumidor
            {
                // Recibe de cualquiera de los consumidores (etiqueta 2)
                MPI_Recv(&peticion, 1, MPI_INT, MPI_ANY_SOURCE, Consumidor, MPI_COMM_WORLD, &status);

                // Devuelve al consumidor que le envió la peticion con etiquete 0
                MPI_Ssend(&value[pos-1], 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
                cout << GREEN << "Buffer envia " << value[pos-1] << " a Cons. " << status.MPI_SOURCE << endl << BLACK << flush;
                pos--;
                break;
            }
        }
    }
}

// Punto de entrada al programa
int main(int argc, char *argv[])
{
    // Inicialización de open-mpi
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Controlamos que estemos llamando correctamente al programa
    if(size!=10)
    {
        if (rank == 0) // Solo mostramos el mensaje 1 vez
            cout << "Uso: mpirun -np 10 " << argv[0] << endl;
    }
    else
    {
        // Llamamos a los metodos dependiendo de cual sea su numero "rank"
        if (rank < Buffer)
            productor(rank);
        else if (rank == Buffer)
            buffer();
        else
            consumidor(rank);
    }

    //cout << "Finalizado el proceso " << rank << endl << flush;

    // Finalización de open-mpi
    MPI_Finalize();

    // Fin del programa
    return 0;

}
