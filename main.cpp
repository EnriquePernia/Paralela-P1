#include <iostream>
#include <thread>
#include <cmath> //Para comprobar los posibles fallos del usuario
#include <string> //Para comprobar si es multi Thread
#include "p1Header.h"
using namespace std;



int main(int argc, char** argv) {
  int executionType = (argv[3] == std::string("--multi-thread"))? 1:0;//Comparamos el tercer arg para ver si es --multi-thread
  int opType = (argv[2] == std::string("xor"))? 1:0;
  solveArray solve;
  double * workingArray = solve.createArray(stoi(argv[1]),*argv[2],*argv[3]);

  switch (executionType) {
    case 0: {//Caso base 2 threads
      std::cout << "suma" << '\n';
      switch (opType) {
        case 0:{
          std::cout << "suma" << '\n';
          std::thread t1(&solveArray::sum,solve,workingArray, stoi(argv[1]));//Creamos thread que utiliza la funcion sum de la clase solveArray
          std::thread t2(&solveArray::sum,solve,workingArray, stoi(argv[1]));
          break;}
        case 1:{
          std::thread t1(&solveArray::xorr,solve,workingArray, stoi(argv[1]));//Creamos thread que utiliza la funcion xor de la clase solveArray
          std::thread t2(&solveArray::xorr,solve,workingArray, stoi(argv[1]));
          break;}
      }
      break;}

    // case 1:{//Caso multi threading argv[4]
    //   switch (opType) {
    //     case 0:{
    //       std::thread t1(&solveArray::sum,solve,workingArray, stoi(argv[1]));//Creamos thread que utiliza la funcion sum de la clase solveArray
    //       std::thread t2(&solveArray::sum,solve,workingArray, stoi(argv[1]));
    //       break;}
    //     case 1:{
    //       std::thread t1(&solveArray::xorr,solve,workingArray, stoi(argv[1]));//Creamos thread que utiliza la funcion xor de la clase solveArray
    //       std::thread t2(&solveArray::xorr,solve,workingArray, stoi(argv[1]));
    //       break;}
    //   }
    //   break;}
  }    //Array con el que trabajamos

  // t1.join();  //Esperamos a que finalice el thread
  return 0;
}
