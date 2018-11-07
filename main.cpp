#include <iostream>
#include <thread>
#include <cmath> //Para comprobar los posibles fallos del usuario
#include <string> //Para comprobar si es multi Thread
#include <vector>
#include "p1Header.h"
using namespace std;

//unsigned int n = std::thread::hardware_concurrency(); Maximo de cores

int main(int argc, char** argv) {
  int executionType = 0;
  int numThreads =2;
  if(argc>3){
    if(argv[3] == std::string("--multi-thread"))//Comparamos el tercer arg para ver si es --multi-thread
      numThreads = stoi(argv[4]);
  }
  int opType = (argv[2] == std::string("xor"))? 1:0;
  solveArray solve;
  int num = stoi(argv[1]);
  double ** workingArray;
  std::thread myThreads[numThreads]; //Array de threads (Vector si das tiempo)
      workingArray = solve.createArray(num,numThreads);//Problema porque pasaba como terver argumento argv[4] y este es el caso sin multi
      switch (opType) {
        case 0:{ //SUMA
          for(size_t i = 0; i < numThreads; i++) {
            if(i==0) myThreads[i] = std::thread(&solveArray::sum,solve,std::ref(workingArray[i]), 0);
            else myThreads[i] = std::thread(&solveArray::sum,solve,std::ref(workingArray[i]), 1);
         };
          for (size_t i = 0; i < numThreads; i++){
            myThreads[i].join();
         };
          break;}
        case 1:{ //XOR
          for(size_t i = 0; i < numThreads; i++) {
           if(i==0) myThreads[i] = std::thread(&solveArray::xorOp,solve,std::ref(workingArray[i]), 0);
           else myThreads[i] = std::thread(&solveArray::xorOp,solve,std::ref(workingArray[i]), 1);
         };
          for (size_t i = 0; i < numThreads; i++){
            myThreads[i].join();
         }
          break;}
        }
  return 0;
}
