#include <iostream>
#include <thread>
#include <string>
#include <array>
using namespace std;

// Usar Malloc

// void createThreads(int arrLength,char option, char numThreads);

int * createThreads(int arrLength,char option, char numThreads){
  int arrayNum[arrLength];
  for (int i = 0; i < arrLength; i++) {
    arrayNum[i]=i+1;
  }
  return  arrayNum  ;
}


int main(int argc, char** argv) {
  std::cout << "Have " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
  int *z;
  z = createThreads(stoi(argv[1]),*argv[2],*argv[3]);
  std::cout << *(z + 1) << std::endl;
  std::thread t1{std::bind(f, even)};
  std::thread t2{std::bind(f, odd)};

 /* Espera que finalicen */
 // t1.join();
 // t2.join();
 return 0;
}
