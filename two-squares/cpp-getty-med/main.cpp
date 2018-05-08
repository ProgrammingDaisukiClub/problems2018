#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi                first
#define se                second
#define pb                push_back
#define INF               LLONG_MAX/3
#define MOD               1000000007
#define bcnt              __builtin_popcount
#define all(x)            (x).begin(),(x).end()
#define srt(x)            sort(all(x))
#define rvs(x)            reverse(all(x))
#define uni(x)            x.erase(unique(all(x)),x.end())
#define ub(x,y)           (upper_bound(all(x),y)-x.begin())
#define lb(x,y)           (lower_bound(all(x),y)-x.begin())
#define rep(i,n)          repl(i,0,n-1)
#define mkp(x,y)          make_pair(x,y)
#define mmax(x,y)         (x>y?x:y)
#define mmin(x,y)         (x<y?x:y)
#define maxch(x,y)        x=mmax(x,y)
#define minch(x,y)        x=mmin(x,y)
#define exist(x,y)        (find(all(x),y)!=x.end())
#define each(itr,v)       for(auto itr:v)
#define repl(i,a,b)       for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)     DVec(n1,Vec(n2,i))
#define tvec(n1,n2,n3,i)  TVec(n1,dvec(n2,n3,i))

int main() {
  cin.sync_with_stdio(false);
  ll N;
  cin >> N;
  rep(i,N){
    vector<P> mp;
    ll a,b;
    rep(i,8)cin >> a >> b,mp.pb(mkp(a,b));
    srt(mp);
    do{
      if(mp[0].fi == mp[1].fi && mp[0].se == mp[2].se && mp[1].se == mp[3].se && mp[2].fi == mp[3].fi)
      if(mp[4].fi == mp[5].fi && mp[4].se == mp[6].se && mp[5].se == mp[7].se && mp[6].fi == mp[7].fi){
        ll a = abs(mp[0].se - mp[1].se) * abs(mp[0].fi - mp[2].fi);
        ll b = abs(mp[4].se - mp[5].se) * abs(mp[4].fi - mp[6].fi);
        ll t1 = mmin(a,b);
        ll t2 = mmax(a,b);
        cout << t1 << " " << t2 << endl;
        break;
      }
    }while(next_permutation(all(mp)));
  }
  return 0;
}

