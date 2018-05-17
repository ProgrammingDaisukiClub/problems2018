#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

void solve(){
	int cnt=0;
	for(int i=0;i<100;i++){
		int a;
		scanf("%d",&a);
		cnt+=a;
	}
	printf("%d\n",100-cnt);
}

int main(void){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}