#include <vector>
#include <iostream>
#include <math.h>
#include <utilidadesBD.h>
#include <ctime>
#include <chrono>

using namespace std;

// Cálculo de distancia euclídea entre dos vectores
double distanciaEuclidea(vector<double>& v1, vector<double>& v2, vector<double>& pesos);

// Cálculo del porcentaje de etiquetas correctas
double porcentajeEtiquetas(vector<int>& etiquetas, vector<int>& etiquetas_calculadas);

// Algoritmo k-NN
void kNN(vector<vector<double> >& train, vector<int>& etiquetas_train, vector<vector<double> >& test, vector<double>& pesos, vector<int>& etiquetas_calculadas, bool leave_one_out);

// Función que realiza los cálculos pertinentes con kNN y muestra por pantalla los porcentajes
void evaluarkNN(int bd_elegida, int particion);

// Algoritmo RELIEF
void RELIEF(vector<vector<double> >& train, vector<int>& etiquetas_train, vector<double>& pesos_calculados);

// Función que realiza los cálculos pertinentes con RELIEF y muestra por pantalla los porcentajes
void evaluarRELIEF(int bd_elegida, int particion);

// Algoritmo que genera un vecino para la Búsqueda Local
void generarVecino(vector<double>& solucion_base, vector<double>& solucion_generada, normal_distribution<double>& distribucion_normal, default_random_engine& generador, vector<int>& indices);

// Algoritmo de Búsqueda Local
void localSearch(vector<vector<double> >& train, vector<int>& etiquetas_train, vector<double>& pesos_calculados, normal_distribution<double>& distribucion_normal, default_random_engine& generador, int& evaluaciones);

// Función que realiza los cálculos para la local search y muestra por pantalla los porcentajes
void evaluarLocalSearch(int bd_elegida, int particion, normal_distribution<double>& distribucion_normal, default_random_engine& generador);
