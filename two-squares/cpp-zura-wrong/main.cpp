#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,a,b) for(int i=(int)(a-1);i>=b;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define INF INT_MAX/3

P p[8];

bool check(int a, int b, int c, int d) {
    int q[] = {a, b, c, d};
    sort(q, q + 4);
    int x = (p[q[0]].fi - p[q[1]].fi) * (p[q[0]].fi - p[q[1]].fi) + (p[q[0]].se - p[q[1]].se) * (p[q[0]].se - p[q[1]].se);
    int y = (p[q[0]].fi - p[q[2]].fi) * (p[q[0]].fi - p[q[2]].fi) + (p[q[0]].se - p[q[2]].se) * (p[q[0]].se - p[q[2]].se);
    int z = (p[q[0]].fi - p[q[3]].fi) * (p[q[0]].fi - p[q[3]].fi) + (p[q[0]].se - p[q[3]].se) * (p[q[0]].se - p[q[3]].se);
    if (z == x + y) {
        x = (p[q[0]].fi - p[q[1]].fi) * (p[q[0]].fi - p[q[1]].fi) + (p[q[0]].se - p[q[1]].se) * (p[q[0]].se - p[q[1]].se);
        y = (p[q[1]].fi - p[q[2]].fi) * (p[q[1]].fi - p[q[2]].fi) + (p[q[1]].se - p[q[2]].se) * (p[q[1]].se - p[q[2]].se);
        z = (p[q[1]].fi - p[q[3]].fi) * (p[q[1]].fi - p[q[3]].fi) + (p[q[1]].se - p[q[3]].se) * (p[q[1]].se - p[q[3]].se);
        if (y == x + z) return true;
    }
    return false;
}

int main(){
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    rep(ii, t) {
        vector<int> v(8);
        rep(i, 8) {
            cin >> p[i].fi >> p[i].se;
            v[i] = i;
        }
        sort(p, p + 8);
        do {
            bool ok1 = check(v[0], v[1], v[2], v[3]), ok2 = check(v[4], v[5], v[6], v[7]);
            if (ok1 && ok2) {
                int n = (p[v[0]].fi - p[v[1]].fi) * (p[v[0]].fi - p[v[1]].fi) + (p[v[0]].se - p[v[1]].se) * (p[v[0]].se - p[v[1]].se);
                int m = (p[v[4]].fi - p[v[5]].fi) * (p[v[4]].fi - p[v[5]].fi) + (p[v[4]].se - p[v[5]].se) * (p[v[4]].se - p[v[5]].se);
                if (n > m) swap(n, m);
                cout << n << " " << m << endl;
                break;
            }
        } while(next_permutation(all(v)));
    }

    return 0;
}
