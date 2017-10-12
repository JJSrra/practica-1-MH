#include <iostream>
#include <utilidadesBD.h>
#include <vector>
#include <algoritmos.h>
#include <random>
#include <geneticos.h>
#include <memeticos.h>

using namespace std;

int main(){
  vector<vector<double> > datos;
  bool primeraVez;
  long int semilla;
  bool knn=false, relief=false, localsearch=false, aggblx=false, ageblx=false, aggca=false, ageca=false, amtotal=false, am10=false, ammejor=false;
  char opcion, opcionPrimeraVez;

  cout << "Para las siguientes opciones ->" << endl
       << "\t0-KNN" << endl
       << "\t1-RELIEF" << endl
       << "\t2-Local Search" << endl
       << "\t3-AGGBLX" << endl
       << "\t4-AGGCA" << endl
       << "\t5-AGEBLX" << endl
       << "\t6-AGECA" << endl
       << "\t7-AM 10-1" << endl
       << "\t8-AM 10-0.1" << endl
       << "\t9-AM 10-0.1mejor" << endl
       << "\tt-Ejecutar todos los algoritmos" << endl
       << "Seleccione cuál debe realizar el programa: ";
  cin >> opcion;
  cout << endl;

  cout << "¿Es la primera vez que ejecuta este programa? Si es así, o quiere volver a restablecer las particiones, indíquelo (s/n): ";
  cin >> opcionPrimeraVez;
  cout << endl;

  if (opcionPrimeraVez == 's' || opcionPrimeraVez == 'S')
    primeraVez = true;

  cout << "Por último, inicialice el valor de la semilla para generar números aleatorios: ";
  cin >> semilla;
  cout << endl << endl;

  srand(semilla);
  default_random_engine generador;
  normal_distribution<double> distribucion_normal(0.0,0.09);

  if (primeraVez){
    normalizarBD(1);
    normalizarBD(2);
    normalizarBD(3);
    particionarBD(1,5);
    particionarBD(2,5);
    particionarBD(3,5);
  }

  switch (opcion){
    case '0':
      knn = true;
      break;

    case '1':
      relief = true;
      break;

    case '2':
      localsearch = true;
      break;

    case '3':
      aggblx = true;
      break;

    case '4':
      aggca = true;
      break;

    case '5':
      ageblx = true;
      break;

    case '6':
      ageca = true;
      break;

    case '7':
      amtotal = true;
      break;

    case '8':
      am10 = true;
      break;

    case '9':
      ammejor = true;
      break;

    case 't':
      knn = true;
      relief = true;
      localsearch = true;
      aggblx = true;
      aggca = true;
      ageblx = true;
      ageca = true;
      amtotal = true;
      am10 = true;
      ammejor = true;
      break;
  }

  if (knn)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarkNN(i,j);

  if (relief)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarRELIEF(i,j);

  if (localsearch)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarLocalSearch(i,j,distribucion_normal,generador);

  if (aggblx)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAGGBLX(i,j,distribucion_normal,generador);

  if (aggca)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAGGCA(i,j,distribucion_normal,generador);

  if (ageblx)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAGEBLX(i,j,distribucion_normal,generador);

  if (ageca)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAGECA(i,j,distribucion_normal,generador);

  if (amtotal)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAMtotal(i,j,distribucion_normal,generador);

  if (am10)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAM10(i,j,distribucion_normal,generador);

  if (ammejor)
  for (int i=1; i < 4; ++i)
    for (int j=1; j < 6; ++j)
      evaluarAMmejor(i,j,distribucion_normal,generador);

}
