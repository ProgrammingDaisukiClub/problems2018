#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

void solve(){
	int n,m;
	scanf("%d",&n);
	set<string> knw,saw;
	string str;
	for(int i=0;i<n;i++){
		cin >> str;
		knw.insert(str);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		cin >> str;
		if(knw.find(str)==knw.end()){
			printf("siranai\n");
		}else{
			if(saw.find(str)==saw.end()){
				printf("kawaii\n");
			}else{
				printf("moumita\n");
			}
			saw.insert(str);
		}
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