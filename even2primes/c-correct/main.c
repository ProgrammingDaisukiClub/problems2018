#include <stdio.h>

#define INC(i, a, b) for((i) = (a); (i) < (b); ++(i))
#define REP(i, n)    INC(i, 0, n)
#define maxN 5000000

char isPrime[maxN + 1];

void uN_prime(){
    int i, k;
    isPrime[0] = 0;
    isPrime[1] = 0;
    isPrime[2] = 1;
    isPrime[3] = 1;

    INC(i, 4, maxN + 1){
        if(i % 6 == 1 || i % 6 == 5){
            isPrime[i] = 1;
        }else{
            isPrime[i] = 0;
        }
    }

    INC(i, 5, maxN + 1){
        if(isPrime[i]){
            INC(k, 2, maxN/i + 1){
                isPrime[i * k] = 0;
            }
        }
    }
}

int main(){

    uN_prime();

    int T;
    scanf("%d", &T);
    
    int E;
    int t, p;
    int ans = 0;
    REP(t, T){
        ans = 0;
        scanf("%d", &E);
        INC(p, 2, E/2 + 1){
            if(isPrime[p] == 1 && isPrime[E - p] == 1){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}