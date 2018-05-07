#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	printf("%s\n",(b-a<=1)?"YES":"NO");
}

int main(void){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}