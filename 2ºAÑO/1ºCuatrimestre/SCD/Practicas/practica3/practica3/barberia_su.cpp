 /* Problema Barberia y cliente

  Realizado por: Jose Santos Salvador
  Grupo: B3

*/

/*g++ -std=c++11 -pthread -Wfatal-errors  -o barberia_su_exe barberia_su.cpp HoareMonitor.cpp Semaphore.cpp*/
#include <iostream>
#include <iomanip>
#include <random>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM;

constexpr int numClientes = 3;    // constante número de clientes de la barbería

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

// -----------------------------------------------------------------------------

void EsperarFueraBarberia( int num_cliente )
{
   chrono::milliseconds duracion_esperar_fuera( aleatorio<20,200>() );

   cout << "\tCliente " << num_cliente << ": espera fuera de la barberia (" 
        << duracion_esperar_fuera.count() << " milisegundos)" << endl;  

   this_thread::sleep_for( duracion_esperar_fuera );

   cout << "\tCliente " << num_cliente << ": ha terminado de esperar y se marcha." << endl;
}

void CortarPeloACliente(){

   chrono::milliseconds duracion_cortar( aleatorio<20,200>() );

   this_thread::sleep_for( duracion_cortar );
}

class Barberia : public HoareMonitor
{

  private:
    int cliente;

    CondVar barbero, sala_espera, cliente_en_silla;

  public:
    Barberia();
    void finCliente();  
    void cortarPelo(int num_cliente);
    void siguienteCliente();
};

Barberia::Barberia()
{
    sala_espera = newCondVar();
    cliente_en_silla = newCondVar();
    barbero = newCondVar();

}

void Barberia::cortarPelo(int num_cliente)
{
  if(barbero.get_nwt() == 0)
    sala_espera.wait();
  else
  {
    cout<<"\nEl cliente numero " << num_cliente << " despierta al babero" << endl;
    barbero.signal();
  }

  cout << "El babero le está cortando el pelo al cliente numero " << num_cliente << endl;
  cliente = num_cliente;
  cliente_en_silla.wait();
}

void Barberia::siguienteCliente()
{
  if(sala_espera.get_nwt() == 0)
  {
    cout << "No hay clientes en la sala de espera" << endl;
    barbero.wait();    
  }
  else
  {
    cout << "Pasa un nuevo cliente" <<endl;
    sala_espera.signal();
  }
}

void Barberia::finCliente()
{
  cout << "El cliente " << cliente << " ha finalizado su corte de pelo" << endl;
  cliente_en_silla.signal();
}

void funcion_hebra_cliente( MRef<Barberia> monitor, int num_cliente )
{

  while(true)
  { 
    monitor->cortarPelo(num_cliente);
    EsperarFueraBarberia(num_cliente);
  }

}
// -----------------------------------------------------------------------------

void funcion_hebra_barbero( MRef<Barberia> monitor )
{

  while(true)
  {
    monitor->siguienteCliente();
    CortarPeloACliente();
    monitor->finCliente();
  }

}

int main()
{

   cout << "--------------------------------------------------------" << endl 
        << "PROBLEMA DEL BARBERO Y CLIENTE CON MONITOR" << endl
        << "--------------------------------------------------------" << endl;

   MRef<Barberia> monitor = Create<Barberia>();

  thread barbero(funcion_hebra_barbero, monitor);
  thread clientes[numClientes];

  for (int i = 0; i < numClientes; i++)
    clientes[i] = thread (funcion_hebra_cliente, monitor, i);

  barbero.join() ;

  for (int i = 0; i < numClientes; i++)
    clientes[i].join();

  clientes[numClientes].join();
}