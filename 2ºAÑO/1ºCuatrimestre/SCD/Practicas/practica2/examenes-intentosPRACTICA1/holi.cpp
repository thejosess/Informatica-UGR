#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include "Semaphore.h"
using namespace std;
using namespace SEM;
//*******************************************************************
const int
num_terminos = 40;
Semaphore
s1= 1, s2= 1;
mutex
mtx;
int
suma= 0;
//-------------------------------------------------------------------
template<int min, int max> int aleatorio(){
static default_random_engine generador( (random_device())());
static uniform_int_distribution<int> distribucion_uniforme(min,max);
return distribucion_uniforme( generador);
}
//--------------------------------------------------------------------
int escribir_termino(unsigned t1, unsigned t2){
this_thread::sleep_for(chrono::milliseconds( aleatorio<20,100>()));
mtx.lock();
cout<<"nuevo termino: "<<t1+t2<<endl<<flush;
mtx.unlock();
return t1+t2;
}
//--------------------------------------------------------------------
void escribir_termino(unsigned t){
this_thread::sleep_for(chrono::milliseconds( aleatorio<20,100>()));
mtx.lock();
cout<<"nuevo termino: "<<t<<endl<<flush;
mtx.unlock();
}
//--------------------------------------------------------------------
void escribir_suma(unsigned suma){
this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>()));
mtx.lock();
cout << "termino suma: "<<suma<<endl;
mtx.unlock();
}
//--------------------------------------------------------------------
void sucesion_funcion(){
static unsigned s_0= 0,
s_1 = 1;
escribir_termino(s_0);
escribir_termino(s_1);
for( unsigned i=0 ; i < num_terminos ; i++ ){
sem_wait( s1 );
suma = escribir_termino(s_0,s_1);
sem_signal( s2 );
s_0= s_1;
s_1= suma;
}
}
//--------------------------------------------------------------------
void suma_funcion(){
static unsigned suma_termino = 0;
for ( unsigned i=0 ; i < num_terminos/2 ; i++ ){
sem_wait( s2 );

suma_termino = suma_termino + suma;
sem_signal( s1 );

escribir_suma( suma_termino );
}
}
//*********************************************************************
int main(){
cout << "--------------------------------------------------" << endl
<< "Problema del examen de la primera práctica (B1)--." << endl
<< "--------------------------------------------------" << endl
<< flush;
thread hebra_sucesion ( sucesion_funcion ),
hebra_suma ( suma_funcion );
hebra_sucesion.join();
hebra_suma.join();
}