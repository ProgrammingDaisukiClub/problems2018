#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

void solve(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		sum+=a;
		sum%=2;
		printf("%d\n",sum);
	}
}

int main(void){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}