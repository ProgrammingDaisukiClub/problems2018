#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

P p[8];
bool side[8];
bool unko=false;

int norm(P a,P b){
	int x=a.first-b.first;
	int y=a.second-b.second;
	return x*x+y*y;
}

int calc_sq(int type){
	int len_mini=914514190;
	for(int i=0;i<8;i++){
		if(side[i]!=type)continue;
		for(int j=i+1;j<8;j++){
			if(side[j]!=type)continue;
			len_mini=min(norm(p[i],p[j]),len_mini);
		}
	}
	if(len_mini==0)return -1;
	int cnt=0,cnt2=0;
	for(int i=0;i<8;i++){
		if(side[i]!=type)continue;
		for(int j=i+1;j<8;j++){
			if(side[j]!=type)continue;
			if(norm(p[i],p[j])==len_mini)cnt++;
			if(norm(p[i],p[j])==len_mini*2)cnt2++;
		}
	}
	if(cnt!=4)return -1;
	if(cnt2!=2)return -1;
	return len_mini;
}

void dfs(int v,int c){
	if(v==8){
		if(c!=4)return;
		P ans;
		ans.first=calc_sq(0);
		ans.second=calc_sq(1);
		if(ans.first==-1 || ans.second==-1)return;
		if(ans.first>ans.second)swap(ans.first,ans.second);
		if(unko)return;
		unko=true;
		printf("%d %d\n",ans.first,ans.second);
		
		/*
		for(int i=0;i<8;i++){
			printf("%d ",side[i]);
		}
		printf("\n");
		*/
		return;
	}
	side[v]=1;
	dfs(v+1,c+1);
	side[v]=0;
	dfs(v+1,c);
}

void solve(){
	for(int i=0;i<8;i++){
		scanf("%d%d",&p[i].first,&p[i].second);
	}
	unko=false;
	dfs(1,0);
}

int main(void){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}