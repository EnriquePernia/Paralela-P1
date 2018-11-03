#include <iostream>
#include "p1Header.h"
using namespace std;


solveArray::solveArray(){}


int solveArray::sum(double * arr, int count){ //Funcion que suma los elem del array
  int sumatory=0;
  for (int i = 0; i < count; i++) {
    sumatory+= arr[i]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
  }
  return sumatory;
}


double ** solveArray::createArray(int arrLength,char option, char numThreads){ //Funcion que crea el array(de momento)
  double ** arrayNum= (double**)malloc(numThreads * sizeof(double)); //Reservando espacio para el array
  int count = 0;
  int auxVect = 0;
  int auxCounting = 0;
  for (int i = 0; i < numThreads; i++) {
    arrayNum[i]=(double*)malloc((arrLength/numThreads) * sizeof(double)); //Asignando valores al array
  }
  for (size_t x = 0; x < arrLength; x++) {
    if(auxCounting==(arrLength/numThreads)){
      auxCounting = 0;
      count++;
      auxVect = 0;
    }
    arrayNum[count][auxVect]=x;
    auxCounting++;
  }
  std::cout << arrayNum[0][2] << '\n';
  return  arrayNum  ;
}


 int solveArray::xorr(double * arr,  int count){
   return 0;
 }
