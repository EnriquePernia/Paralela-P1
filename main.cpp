#include <iostream>
#include <thread>
#include "p1Header.h"
using namespace std;



int main(int argc, char** argv) {
  solveArray solve;
  std::cout << "Have " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) {  //Mostramos argumentos
    std::cout << argv[i] << std::endl;
  }
  double * workingArray = solve.createArray(stoi(argv[1]),*argv[2],*argv[3]);    //Array con el que trabajamos
  std::cout << *(workingArray + 1) << std::endl; //Mostrar primer elemento

  //int *a1; //array a pasar a cada thread
  //int *a2;

  std::thread t1(&solveArray::sum,solve,workingArray, stoi(argv[1]));
  t1.join();
  // std::thread t2{(f, odd)};

 /* Espera que finalicen */
 // t1.join();
 // t2.join();
 return 0;
}
