// This is start of the header guard.  p1Header_H can be any unique name.  By convention, we use the name of the header file.
#ifndef p1Header_H
#define p1Header_H

#include <iostream>
#include <thread>
// This is the content of the .h file, which is where the declarations go
extern int loggerValue;
extern int conditionalLogger;
class solveArray
{
 public:
 enum class Oper{ sum, xorOp};
 solveArray();
 int doOp(double * _arr, Oper oper, int start, int end);
};
// This is the end of the header guard
#endif
