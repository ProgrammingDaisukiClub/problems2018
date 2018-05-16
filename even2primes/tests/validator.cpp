#include "testlib.h"
#include "constraints.h"
#include <iostream>
using namespace std;

void check_case(){
  int E = inf.readInt(2, MAX_E, "E");
  inf.readEoln();

  ensure(E % 2 == 0);
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
