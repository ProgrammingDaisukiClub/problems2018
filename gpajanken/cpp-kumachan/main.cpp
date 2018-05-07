#include <iostream>
#include <string>

using namespace std;

void GLprint(int A, int B, string greater, string equal, string less){
    if(A > B){
        cout << greater << endl;
    }else if(A == B){
        cout << equal << endl;
    }else{
        cout << less << endl;
    }
}

int main(){
    int T;
    cin >> T;
    
    int A, B;
    for(int t = 0; t < T; ++t){
        cin >> A >> B;
        GLprint(A, B, "KATO", "DRAW", "SATO");
    }
    
    return 0;
}