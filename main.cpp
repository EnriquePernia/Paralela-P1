#include <iostream>
#include <thread>
#include <cmath>  //Para comprobar los posibles fallos del usuario
#include <string> //Para comprobar si es multi Thread
#include <vector>
#include "p1Header.h"
using namespace std;
//unsigned int n = std::thread::hardware_concurrency(); Maximo de cores

int logger(int *previousLoggerValue);
int main(int argc, char **argv)
{
  int numThreads = 1;
  int x = 0;           // 'x' is 23
  int *previousLoggerValue = &x; 
  std::thread myThreads[numThreads]; //Array de threads (Vector si das tiempo).
  std::thread loggerT;
  if (argc > 3)
  {                                               //Comprobamos si es multi threading
    if (argv[3] == std::string("--multi-thread")) //Comparamos el tercer arg para ver si es --multi-thread
      if (stoi(argv[4]) <= 10)
        numThreads = stoi(argv[4]);
  }
  solveArray::Oper opType = (argv[2] == std::string("xor")) ? solveArray::Oper(1) : solveArray::Oper(0);
  solveArray solve;
  int num = stoi(argv[1]);
  double *array = (double *)malloc(num * sizeof(double));
  for (size_t i = 0; i < num; i++)
  {
    array[i] = (double)i;
  }
  int extraNumbers = 0;
  if ((num % numThreads) != 0)
  { //Para tener en cuenta los  numeros que faltan(Trabajo extra para el thread 1)
    extraNumbers = num - floor(num / numThreads) * numThreads;
  };                                                  //Para saber la longitud de los arrays
  int size0 = floor(num / numThreads) + extraNumbers; //Tamanho del array para primer thread
  int size1 = floor(num / numThreads);                //Tamanho del array para resto de threads
  int start = 0;
  int end = size0;
  for (size_t i = 0; i < numThreads; i++)
  {
    myThreads[i] = std::thread(&solveArray::doOp, solve, std::ref(array), opType, start, end); //Mejorado el bucle de threads, antes habia un switch
    myThreads[i].join(); // Cuando termina un thread ejecutamos el logger
    loggerT = std::thread(logger, previousLoggerValue);
    loggerT.join(); //Terminamos el logger y pasamos al siguiente trhead para que no haya fallos
    if (i == 0)
    {
      start += end;
    }
    else
      start += size1;
    end += size1;
  }
  // for (size_t i = 0; i < numThreads; i++)
  // {
  //   // myThreads[i].join();
  //   // loggerT.join();               //Guardar los valores de las operaciones
  // };
  return 0;
}

int logger(int *previousValue) //Le pasamos un puntero a la direccion de la variable x donde iremos almacenando los valores
{
  *previousValue += loggerValue;
  std::cout << "logger : " << *previousValue << '\n';
  return 0;
}