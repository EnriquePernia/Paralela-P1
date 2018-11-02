#include <iostream>
#include "p1Header.h"
using namespace std;


solveArray::solveArray(){}


int solveArray::sum(double * arr, int count){ //Funcion que suma los elem del array
  int sumatory=0;
  for (int i = 0; i < count; i++) {
    sumatory+= arr[i];
    //*(arr + i) Se puede avanzar tambien asi ¿Por que?
  }
  return sumatory;
}


double * solveArray::createArray(int arrLength,char option, char numThreads){ //Funcion que crea el array(de momento)
  double * arrayNum= (double*)malloc(arrLength * sizeof(double)); //Reservando espacio para el array
  for (int i = 0; i < arrLength; i++) {
    arrayNum[i]=i+1; //Asignando valores al array
  }
  return  arrayNum  ;
}


// int solveArray::xor(double * arr,  int count){
//   return 0;
// }
