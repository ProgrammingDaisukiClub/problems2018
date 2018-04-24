#include <iostream>
#include <string>
#include "testlib.h"
#include "constraints.h"
using namespace std;

void check_case() {
  int K[PLAYERS];
  for(int i = 0; i < PLAYERS; i++) {
    K[i] = inf.readInt(0, 99, "K[" + to_string(i + 1) + "]");
    if(i + 1 != PLAYERS) inf.readSpace();
    else inf.readEoln();
  }
  int sum = 0;
  for(int i = 0; i < PLAYERS; i++) sum += K[i];
  ensure(sum < PLAYERS);
}

int main() {
  registerValidation();

  int T = inf.readInt(1, MAX_T, "T");
  inf.readEoln();

  for(int i = 0; i < T; i++) {
    check_case();
  }

  inf.readEof();

  return 0;
}
