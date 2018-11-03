#include <iostream>
#include <vector>
#include <string>
#include "p1Header.h"
using namespace std;


solveArray::solveArray(){}


int solveArray::sum(double * arr, int count){ //Funcion que suma los elem del array
  int sumatory=0;
  for (int i = 0; i < count; i++) {
    sumatory+= arr[i]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
  }
  std::cout << sumatory << '\n';
  return sumatory;
}


double ** solveArray::createArray(int arrLength,char option, char numThreads){ //Funcion que crea el array(de momento)
  // std::vector< std::vector<double> > my_array; /* 2D Array */
  double ** arrayNum= (double**)malloc(numThreads * sizeof(double)); //Reservando espacio para el array
  int count = 0;
  int auxCounting = 0;
  for (int i = 0; i < numThreads; i++) {
    arrayNum[i]=(double*)malloc((arrLength/numThreads) * sizeof(double)); //Asignando valores al array
  }
  for (double x = 0; x < arrLength; x++) { //Creamos los arrays para cada thread
    if(auxCounting==(arrLength/numThreads)){
      auxCounting = 0;
      count++;
    }
    arrayNum[count][auxCounting] = x;
    auxCounting++;
  }
    std::cout << sizeof(arrayNum) << '\n';
  //std::cout << arrayNum[0][600] << '\n'; Devuelve 588 ¿Accede a otra zona de la memora?
  return  arrayNum  ;
}


 int solveArray::xorr(double * arr,  int count){
   return 0;
 }
