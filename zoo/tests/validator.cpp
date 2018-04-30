#include "testlib.h"
#include "constraints.h"
#include <iostream>
using namespace std;

bool flag=false;

void check_case(){
  int n = inf.readInt(1, MAX_N, "N");
  inf.readEoln();
  for(int i=0;i<n;i++){
  	string str=inf.readToken("[a-z]{1,20}","s");
  	inf.readEoln();
  }
  int m = inf.readInt(1, MAX_M, "M");
  inf.readEoln();
  for(int i=0;i<m;i++){
  	string str=inf.readToken("[a-z]{1,20}","s");
  	inf.readEoln();
  }
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
