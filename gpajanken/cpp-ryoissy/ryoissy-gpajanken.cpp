#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b)printf("SATO\n");
	if(a>b)printf("KATO\n");
	if(a==b)printf("DRAW\n");
}

int main(void){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}