#include <iostream>
#include <string>

using namespace std;

void TFprint(bool b, string T, string F){
    if(b){
        cout << T << endl;
    }else{
        cout << F << endl;
    }
}

int main(){
    int T;
    cin >> T;
    
    int A, B;
    for(int t = 0; t < T; ++t){
        cin >> A >> B;
        int diff = A - B;
        bool b = ((diff == 0) || (diff == 1) || (diff == -1));
        TFprint(b, "YES", "NO");
    }
    
    return 0;
}