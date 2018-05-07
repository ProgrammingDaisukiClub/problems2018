#include "testlib.h"
#include "constraints.h"
#include <iostream>
#include <numeric>
using namespace std;

void check_case(){
    vector<int> k(PLAYERS);
    for(int i=0; i<PLAYERS; ++i){
        k[i] = inf.readInt(0, 100, format("k[%d]", i));
        if(i == PLAYERS-1) inf.readEoln();
        else inf.readSpace();
    }

    // check: 100人のプレイヤーのキル数としてありえない入力は与えられない
    int sum_kill = accumulate(k.begin(), k.end(), 0);
    ensure(sum_kill <= PLAYERS-1);
}

int main(){
    registerValidation();

    int cases = inf.readInt(1, MAX_T, "cases");
    inf.readEoln();

    for(int i=0; i<cases; ++i) check_case();
    inf.readEof();
    return 0;
}
