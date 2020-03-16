#include<bits/stdc++.h>
using namespace std;

#define I inline
#define fi first
#define se second
#define pb push_back
#define ALL(X) (X).begin(), (X).end()
#define CLR(A, X) memset(A, X, sizeof(A))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 1e5+10;

bool prime[N], ok[N];
void init() {
    for(int i = 2; i < N; i++) {
        prime[i] = !prime[i];
        if(prime[i]) for(int j = i+i; j < N; j += i) prime[j] = 1;
        else {
            int m = sqrt(i+0.5);
            for(int j = 2; j <= m; j++) if(prime[j] && i%j==0) {
                    if(prime[i/j] && i!=i/j) { ok[i] = 1; break; }
                }
        }
    }
}

int p[N], sz[N], cnt[N];
struct Edge { int u, v, w; };
vector<Edge> e;
vector<PII> G[N];

int find(int x) { return x==p[x]?x:p[x]=find(p[x]); }

I void work() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) G[i].clear(), p[i] = i, sz[i] = 1;
    e.clear();
    for(int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if(w == 1) {
            u = find(u); v = find(v);
            p[v] = u; sz[u] += sz[v];
        }
        else e.pb({u, v, w});
    }
    for(Edge t:e) {
        int u = find(t.u), v = find(t.v), w = t.w;
        G[u].pb({v, w}); G[v].pb({u, w});
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        LL sum = 0;
        for(PII t:G[i]) {
            int v = t.fi, w = t.se;
            if(ok[w]) ans += 1LL*sz[i]*sz[v];
            else if(prime[w]) {
                sum += sz[v];
                cnt[w] += sz[v];
                ans += 2LL*(sum-cnt[w])*sz[v];
            }
        }
        for(PII t:G[i]) {
            int v = t.fi, w = t.se;
            if(prime[w]) cnt[w] -= sz[v];
        }
    }
    static int cas = 0;
    printf("Case %d: %I64d\n", ++cas, ans/2);
}

int main() {
    freopen("evaluations.in", "r", stdin);
    init();
    int X; scanf("%d", &X);
    while(X--) work();
    return 0;
}