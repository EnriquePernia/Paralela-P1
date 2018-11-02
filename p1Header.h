// This is start of the header guard.  p1Header_H can be any unique name.  By convention, we use the name of the header file.
#ifndef p1Header_H
#define p1Header_H

#include <iostream>
#include <thread>
// This is the content of the .h file, which is where the declarations go
class solveArray
{
 public:
 int sum(double * arr, int count);
 double * createArray(int arrLength,char option, char numThreads);
};
// This is the end of the header guard
#endif
