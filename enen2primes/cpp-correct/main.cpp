#include <iostream>
#define INC(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n)    for(int (i) = 0; (i) < (n); ++(i))
#define maxN 5000000
using namespace std;

bool isPrime[maxN + 1];

void uN_prime(){
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    isPrime[3] = true;

    INC(i, 4, maxN + 1){
        if(i % 6 == 1 || i % 6 == 5){
            isPrime[i] = true;
        }else{
            isPrime[i] = false;
        }
    }

    INC(i, 5, maxN + 1){
        if(isPrime[i]){
            INC(k, 2, maxN/i + 1){
                isPrime[i * k] = false;
            }
        }
    }
}

int main(){

    uN_prime();

    int T;
    cin >> T;
    
    int E;
    int ans = 0;
    REP(t, T){
        ans = 0;
        cin >> E;
        INC(p, 2, E/2 + 1){
            if(isPrime[p] && isPrime[E - p]){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}