#include <iostream>
#include <cmath>
#include <string>
#include <mutex>
#include "p1Header.h"
using namespace std;
std::mutex mtx;

solveArray::solveArray() {}
int *lengthTracking;
/*No estoy utilizando container classes como vector por lo que tengo que tener
constancia de la longitud de cada array Parapoder recorrerlo ya que utilizo
pointers, por lo que sizeof(p) sera el tamanio del pointer = 8.*/

int solveArray::doOp(double *arr, Oper operation, int start, int end)
{ //Funcion que suma los elem del array
mtx.lock();
  switch (operation){
  case Oper::sum :{
    int sumatory = 0;
    for (size_t i = start; i < end; i++)
    {
      sumatory += arr[i];
    }
    std::cout << "Sum: " << sumatory << '\n';
      mtx.unlock();
    return sumatory;
  }
  case Oper::xorOp:{
    int xorNum = arr[start];
    for (size_t i = start+1; i < end; i++) {
      xorNum = xorNum^(int)arr[i+1]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
      std::cout << "start: "<< start << " end: "<<end<< '\n';
    }
  std::cout << "Xor: "<<xorNum<< '\n';
    mtx.unlock();
  return xorNum;
  }
  }
}

double **solveArray::createArray(int arrLength, char numThreads)
{                                                                     //Funcion que crea el array(de momento)
  double **arrayNum = (double **)malloc(numThreads * sizeof(double)); //Reservando espacio para el array a devolver
  int count = 0;
  int auxCounting = 0;
  int extraNumbers = 0;
  if ((arrLength % numThreads) != 0)
  { //Para tener en cuenta los  numeros que faltan(Trabajo extra para el thread 1)
    extraNumbers = arrLength - floor(arrLength / numThreads) * numThreads;
  };
  lengthTracking = (int *)malloc(arrLength * sizeof(double)); //Para saber la longitud de los arrays
  lengthTracking[0] = floor(arrLength / numThreads) + extraNumbers;
  lengthTracking[1] = floor(arrLength / numThreads);
  for (int i = 0; i < numThreads; i++)
  {
    if (i == 0)
      arrayNum[i] = (double *)malloc(lengthTracking[0] * sizeof(double));
    arrayNum[i] = (double *)malloc(lengthTracking[1] * sizeof(double)); //Reservamos espacio en memoria para los arrays
  }
  for (double x = 0; x < arrLength; x++)
  { //Creamos los arrays para cada thread
    if (count == 0 && extraNumbers != 0)
    { //Si es el primero puede que tenga mas trabajo
      if (auxCounting == lengthTracking[0])
      {
        auxCounting = 0;
        count++;
      }
    }
    else if (auxCounting == lengthTracking[1])
    { //Si terminamos un array y empezamos el siguiente del mismo tamanio
      auxCounting = 0;
      count++;
    }
    arrayNum[count][auxCounting] = x;
    auxCounting++;
  }
  return arrayNum;
}

//  int solveArray::xorOp(double * arr, int numThread){
//    mtx.lock();
//   int xorNum = arr[0];;
//   if(numThread == 0){
//      xorNum = arr[2];
//     for (size_t i = 2; i < lengthTracking[0]-1; i++) { //Con 0 y 1 no operamos
//       xorNum = xorNum^(int)arr[i+1]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
//     }
//   }
//   else{
//     for (size_t i = 0; i < lengthTracking[1]-1; i++) {
//       xorNum = xorNum^(int)arr[i+1]; //*(arr + i) Se puede avanzar tambien asi ¿Por que?
//       std::cout <<  xorNum << '\n';
//     }
//   }
//   std::cout << "Xor: "<<arr[0]<< '\n';
//   mtx.unlock();
//   return xorNum;
//  }
///Refactorizar xor y sum: Las dos en una funcion  DONE
//Crear enums    DONE
//Default = 1 thread  DONE
//double ** thiene que ser un array y me muevo por "cachitos"
