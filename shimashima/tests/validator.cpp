#include "testlib.h"
#include "constraints.h"
#include <iostream>
using namespace std;

void check_case(){
  int a = inf.readInt(MIN_AB, MAX_AB, "A");
  inf.readSpace();
  int b = inf.readInt(MIN_AB, MAX_AB, "B");
  inf.readEoln();
}

int main(){
  registerValidation();

  int cases = inf.readInt(1, MAX_T, "cases");
  inf.readEoln();

  for(int i=0; i<cases; ++i){
      check_case();
  }

  inf.readEof();
  return 0;
}
