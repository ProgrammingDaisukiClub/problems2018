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

int dist(int u, int v){
    return (p[u].fi - p[v].fi) * (p[u].fi - p[v].fi) + (p[u].se - p[v].se) * (p[u].se - p[v].se);
}

bool check2(int x, int y, int z, int w) {
    int a = dist(x, y);
    int b = dist(x, z);
    int c = dist(x, w);
    return a == b && c == a + b;
}

bool check(int a, int b, int c, int d) {
    int q[] = {a, b, c, d};

    return check2(q[0], q[1], q[2], q[3]) && check2(q[1], q[0], q[3], q[2]) && check2(q[2], q[0], q[3], q[1]) && check2(q[3], q[2], q[1], q[0]);
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
        do {
            bool ok1 = check(v[0], v[1], v[2], v[3]), ok2 = check(v[4], v[5], v[6], v[7]);
            if (ok1 && ok2) {
                int n = dist(v[0], v[1]);
                int m = dist(v[4], v[5]);
                if (n > m) swap(n, m);
                cout << n << " " << m << endl;
                break;
            }
        } while(next_permutation(all(v)));
    }

    return 0;
}

