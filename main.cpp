#include <iostream>
#include <thread>
#include <cmath> //Para comprobar los posibles fallos del usuario
#include "p1Header.h"
using namespace std;



int main(int argc, char** argv) {
  solveArray solve;
  double * workingArray = solve.createArray(stoi(argv[1]),*argv[2],*argv[3]);    //Array con el que trabajamos
  std::thread t1(&solveArray::sum,solve,workingArray, stoi(argv[1])); //Creamos thread que utiliza la funcion sum de la clase solveArray
  t1.join();  //Esperamos a que finalice el thread
  return 0;
}
