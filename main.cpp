#include "p1Header.h"
// void createThreads(int arrLength,char option, char numThreads);

int sum(int * arr, int count){ //Funcion que suma los elem dek array
  int sumatory;
  for (int i = 0; i < count; i++) {
    sumatory+= *(arr + i);
  }
  return sumatory;
}

double * createThreads(int arrLength,char option, char numThreads){ //Funcion que crea el array(de momento)
  double * arrayNum= (double*)malloc(arrLength * sizeof(double)); //Reservando espacio para el array
  // int arrayNum[arrLength];
  for (int i = 0; i < arrLength; i++) {
    arrayNum[i]=i+1; //Asignando valores al array
  }
  return  arrayNum  ;
}


int main(int argc, char** argv) {
  std::cout << "Have " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) {  //Mostramos argumentos
    std::cout << argv[i] << std::endl;
  }
  double *workingArray;  //Array con el que trabajamos
  workingArray = createThreads(stoi(argv[1]),*argv[2],*argv[3]);
  std::cout << *(workingArray + 1) << std::endl; //Mostrar primer elemento

  int *a1; //array a pasar a cada thread
  int *a2;

  // std::thread t1{(f, even)};
  // std::thread t2{(f, odd)};

 /* Espera que finalicen */
 // t1.join();
 // t2.join();
 return 0;
}
