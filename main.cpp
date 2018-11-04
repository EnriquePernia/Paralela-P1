#include <iostream>
#include <thread>
#include <cmath> //Para comprobar los posibles fallos del usuario
#include <string> //Para comprobar si es multi Thread
#include "p1Header.h"
using namespace std;

//unsigned int n = std::thread::hardware_concurrency(); Maximo de cores

int main(int argc, char** argv) {
  int executionType = 0;
  if(argc>3){
    int executionType = (argv[3] == std::string("--multi-thread"))? 1:0;//Comparamos el tercer arg para ver si es --multi-thread
  }
  int opType = (argv[2] == std::string("xor"))? 1:0;
  solveArray solve;
  double ** workingArray;
  switch (executionType) {
    case 0: {//Caso base 2 threads
      workingArray = solve.createArray(stoi(argv[1]),*argv[2],2);//Problema porque pasaba como terver argumento argv[4] y este es el caso sin multi
      switch (opType) {
        case 0:{
          std::thread t1(&solveArray::sum,solve,std::ref(workingArray[0]), 0);//Creamos thread que utiliza la funcion sum de la clase solveArray
          std::thread t2(&solveArray::sum,solve,std::ref(workingArray[1]),1);
          t1.join();
          t2.join();
          break;}
        case 1:{
          std::cout << "xor" << '\n';
          std::thread t1(&solveArray::xorr,solve,workingArray[0], stoi(argv[1])/2);//Creamos thread que utiliza la funcion xor de la clase solveArray
          std::thread t2(&solveArray::xorr,solve,workingArray[1], stoi(argv[1])/2);
          t1.join();
          t2.join();
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
