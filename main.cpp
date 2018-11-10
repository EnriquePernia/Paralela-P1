#include <iostream>
#include <thread>
#include <cmath> //Para comprobar los posibles fallos del usuario
#include <string> //Para comprobar si es multi Thread
#include <vector>
#include "p1Header.h"
using namespace std;
//unsigned int n = std::thread::hardware_concurrency(); Maximo de cores

int main(int argc, char** argv) {
  int *lengthTracking;
  int executionType = 0;
  int numThreads =1;
  if(argc>3){ //Comprobamos si es multi threading
    if(argv[3] == std::string("--multi-thread"))//Comparamos el tercer arg para ver si es --multi-thread
      numThreads = stoi(argv[4]);
  }
  solveArray::Oper opType = (argv[2] == std::string("xor"))? solveArray::Oper(1):solveArray::Oper(0);
  solveArray solve;
  int num = stoi(argv[1]);
  double * array = (double *)malloc(num * sizeof(double));
  for(size_t i = 0; i<num; i++){
    array[i]=i;
  }
  int extraNumbers = 0;
  if ((num % numThreads) != 0)
  { //Para tener en cuenta los  numeros que faltan(Trabajo extra para el thread 1)
    extraNumbers = num - floor(num / numThreads) * numThreads;
  }; //Para saber la longitud de los arrays
  int size0 = floor(num / numThreads) + extraNumbers; //Tamanho del array para primer thread
  int size1 = floor(num / numThreads); //Tamanho del array para resto de threads
  std::thread myThreads[numThreads]; //Array de threads (Vector si das tiempo).
  int start = 0;
  int end = size0;
    for(size_t i = 0; i < numThreads; i++) {
      myThreads[i] = std::thread(&solveArray::doOp,solve,std::ref(array), opType, start, end); //Mejorado el bucle de threads, antes habia un switch
      if(i==0)start += end;
      else start += size1;
      end += size1;
     }
    for (size_t i = 0; i < numThreads; i++){
      myThreads[i].join();
    };
    return 0;
}
