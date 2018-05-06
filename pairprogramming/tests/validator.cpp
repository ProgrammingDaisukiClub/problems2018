#include "testlib.h"
#include "constraints.h"
#include <iostream>
#include <numeric>
using namespace std;

void check_case(){
    int N = inf.readInt(1, MAX_N, "N");
    inf.readEoln();
    vector<int> a(N);
    for(int i=0; i<N; ++i){
        a[i] = inf.readInt(0, MAX_A, format("a[%d]", i));
        if(i == N-1) inf.readEoln();
        else inf.readSpace();
    }
}

int main(){
    registerValidation();

    int cases = inf.readInt(1, MAX_T, "cases");
    inf.readEoln();

    for(int i=0; i<cases; ++i) check_case();
    inf.readEof();
    return 0;
}
