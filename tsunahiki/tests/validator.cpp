#include "testlib.h"
#include "constraints.h"
#include <iostream>
using namespace std;

void check_case(){
    int n = inf.readInt(1, MAX_ABN, "n");
    inf.readEoln();

    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i){
        a[i] = inf.readInt(1, MAX_ABN, format("a[%d]", i));
        if(i == n-1) inf.readEoln();
        else inf.readSpace();
    }
    for(int i=0; i<n; ++i){
        b[i] = inf.readInt(1, MAX_ABN, format("b[%d]", i));
        if(i == n-1) inf.readEoln();
        else inf.readSpace();
    }

    // check whether lists are sorted
    for(int i=0; i<n-1; ++i){
        ensuref(a[i] <= a[i+1], "list a is not sorted: a[%d](= %d) > a[%d](= %d)", i, a[i], i+1, a[i+1]);
        ensuref(b[i] <= b[i+1], "list b is not sorted: b[%d](= %d) > b[%d](= %d)", i, b[i], i+1, b[i+1]);
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
