#include <iostream>
#include <cmath>
#include <string>
#include <mutex>
#include "p1Header.h"
using namespace std;
std::mutex mtx;

solveArray::solveArray(){}
int *lengthTracking;
/*No estoy utilizando container classes como vector por lo que tengo que tener
constancia de la longitud de cada array Parapoder recorrerlo ya que utilizo
pointers, por lo que sizeof(p) sera el tamanio del pointer = 8.*/

int solveArray::sum(double * arr, int numThread){ //Funcion que suma los elem del array
  mtx.lock();
  int sumatory=0;
  if(numThread == 0){
    for (int i = 0; i < lengthTracking[0]; i++) {
      sumatory+= arr[i]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
    }
  }
  else{
    for (int i = 0; i < lengthTracking[1]; i++) {
      sumatory+= arr[i]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
    }
  }
  std::cout << "Sum: "<<sumatory << '\n';
  mtx.unlock();
  return sumatory;
}


double ** solveArray::createArray(int arrLength, char numThreads){ //Funcion que crea el array(de momento)
  double ** arrayNum= (double**)malloc(numThreads * sizeof(double)); //Reservando espacio para el array a devolver
  int count = 0;
  int auxCounting = 0;
  int extraNumbers=0;
  if((arrLength%numThreads) != 0 ){ //Para tener en cuenta los  numeros que faltan(Trabajo extra para el thread 1)
    extraNumbers = arrLength-floor(arrLength/numThreads)*numThreads;
  };
  lengthTracking=(int*)malloc(arrLength * sizeof(double));//Para saber la longitud de los arrays
  lengthTracking[0]=floor(arrLength/numThreads)+extraNumbers;
  lengthTracking[1]=floor(arrLength/numThreads);
  for (int i = 0; i < numThreads; i++) {
    if(i==0) arrayNum[i]=(double*)malloc(lengthTracking[0] * sizeof(double));
    arrayNum[i]=(double*)malloc(lengthTracking[1] * sizeof(double)); //Reservamos espacio en memoria para los arrays
  }
  for (double x = 0; x < arrLength; x++) { //Creamos los arrays para cada thread
    if(count==0 && extraNumbers != 0){ //Si es el primero puede que tenga mas trabajo
      if(auxCounting==lengthTracking[0]){
        auxCounting = 0;
        count++;
      }
    }
    else if(auxCounting==lengthTracking[1]){ //Si terminamos un array y empezamos el siguiente del mismo tamanio
      auxCounting = 0;
      count++;
    }
    arrayNum[count][auxCounting] = x;
    auxCounting++;
  }
  return  arrayNum  ;
}


 int solveArray::xorOp(double * arr, int numThread){
   return 0;
 }
