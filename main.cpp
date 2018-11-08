#include <iostream>
#include <thread>
#include <cmath> //Para comprobar los posibles fallos del usuario
#include <string> //Para comprobar si es multi Thread
#include <vector>
#include "p1Header.h"
using namespace std;
enum Oper { sum, xorr};
//unsigned int n = std::thread::hardware_concurrency(); Maximo de cores

int main(int argc, char** argv) {
  int executionType = 0;
  int numThreads =1;
  if(argc>3){ //Comprobamos si es multi threading
    if(argv[3] == std::string("--multi-thread"))//Comparamos el tercer arg para ver si es --multi-thread
      numThreads = stoi(argv[4]);
  }
  solveArray::Oper opType = (argv[2] == std::string("xor"))? solveArray::Oper(1):solveArray::Oper(0);
  solveArray solve;
  int num = stoi(argv[1]);
  double ** workingArray;
  std::thread myThreads[numThreads]; //Array de threads (Vector si das tiempo)
  workingArray = solve.createArray(num,numThreads);//Problema porque pasaba como terver argumento argv[4] y este es el caso sin multi
    for(size_t i = 0; i < numThreads; i++) {
     if(i==0) myThreads[i] = std::thread(&solveArray::doOp,solve,std::ref(workingArray[i]), 0, opType); //Mejorado el bucle de threads, antes habia un switch
      else myThreads[i] = std::thread(&solveArray::doOp,solve,std::ref(workingArray[i]), 1, opType);
     };
    for (size_t i = 0; i < numThreads; i++){
      myThreads[i].join();
    };
    return 0;
        }
