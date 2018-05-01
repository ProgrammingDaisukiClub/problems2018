#include "testlib.h"
#include "constraints.h"
#include <iostream>
using namespace std;
typedef pair<int,int> P;

P p[8];
bool side[8];

set<P> res;

int norm(P a,P b){
  int x=a.first-b.first;
  int y=a.second-b.second;
  return x*x+y*y;
}

int calc_sq(int type){
  int len_mini=11451419;
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
    printf("%d %d\n",ans.first,ans.second);
    res.insert(ans);
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

int main(){
  registerValidation();

  int cases = inf.readInt(1, MAX_T, "cases");
  inf.readEoln();

  for(int i=0; i<cases; ++i){
    bool flag=false;
    res.clear();
      for(int j=0;j<8;j++){
       if(flag)inf.readSpace();
       flag=true;
        p[j].first=inf.readInt(-MAX_ABS,MAX_ABS,"x");
        inf.readSpace();
        p[j].second=inf.readInt(-MAX_ABS,MAX_ABS,"y");
      }
      inf.readEoln();
      dfs(1,0);
      if(res.size()>=2 || res.size()==0){
        //printf("invalid inputs: there are more than two answers.\n");
        //return -1;
      }

  }

  inf.readEof();
  return 0;
}
