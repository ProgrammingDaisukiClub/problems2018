#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<int> pi;
static const int MAX=5000005;
bool prime[MAX];

void solve(){
	int n;
	scanf("%d",&n);
	int r=pi.size()-1;
	int cnt=0;
	for(int i=0;i<pi.size();i++){
		while(r>=1 && pi[i]+pi[r]>n)r--;
		if(i>r)break;
		if(pi[i]+pi[r]==n)cnt++;
	}
	printf("%d\n",cnt);
}

int main(void){
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<MAX;i++){
		if(!prime[i])continue;
		pi.push_back(i);
		for(int j=i*2;j<MAX;j+=i){
			prime[j]=false;
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}