#include <iostream>
#include <thread>
#include <string>
using namespace std;
int main(int argc, char** argv) {
  std::cout << "Have " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
  std::thread t1{std::bind(f, even)};
  std::thread t2{std::bind(f, odd)};

 /* Espera que finalicen */
 t1.join();
 t2.join();
}
