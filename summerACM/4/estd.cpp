//
// Created by 赵婉如 on 2019-08-14.
//

#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 10;
vector<pii> vec;
vector<int> G[maxn], W[maxn];
bool isPrime[maxn], legal[maxn];
int T, n, tot, pri[maxn], sz[maxn], fa[maxn], u[maxn], v[maxn], w[maxn];

void pre() {
    for (int i = 2; i <= 100000; ++i)
        if (!isPrime[i]) {
            pri[++tot] = i;
            for (int j = i + i; j <= 100000; j += i)
                isPrime[j] = 1;
        }
    for (int i = 6; i <= 100000; ++i)
        for (int j = 1; pri[j] * pri[j] < i; ++j)
            if (i % pri[j] == 0 && !isPrime[i / pri[j]]) {
                legal[i] = true;
                break;
            }
}

int find(int a) {
    return fa[a] == a ? a : fa[a] = find(fa[a]);
}

int main()
{
    freopen("evaluations.in", "r", stdin);
    freopen("std.txt","w",stdout);
    pre();
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        LL ans = 0ll;
        printf("Case %d: ", ca);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            sz[i] = 1, fa[i] = i, G[i].clear(), W[i].clear();
        for (int i = 1, fu, fv; i < n; ++i) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            if (w[i] == 1) {
                fu = find(u[i]);
                fv = find(v[i]);
                if (fu != fv) {
                    fa[fu] = fv;
                    sz[fv] += sz[fu];
                }
            }
        }
        for (int i = 1, a, b; i < n; ++i) {
            a = find(u[i]);
            b = find(v[i]);
            if (a != b) {
                G[a].pb(b); W[a].pb(w[i]);
                G[b].pb(a); W[b].pb(w[i]);
                if (legal[w[i]])
                    ans += 1ll * sz[a] * sz[b];
            }
        }
        for (int i = 1; i <= n; ++i) {
            vec.clear();
            for (int j = 0, v; j < (int) G[i].size(); ++j) {
                v = G[i][j];
                if (!isPrime[W[i][j]])
                    vec.pb(mp(W[i][j], v));
            }
            sort(vec.begin(), vec.end());
            int sum = 0;
            for (int j = 0, k, sum2; j < (int) vec.size(); j = k) {
                sum2 = 0; k = j;
                while (k < (int) vec.size() && vec[k].fi == vec[j].fi) {
                    sum2 += sz[vec[k++].se];
                }
                ans += 1ll * sum2 * sum;
                sum += sum2;
                //cout<<i<<' '<<sum2<<' '<<sum<<' '<<ans<<endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
