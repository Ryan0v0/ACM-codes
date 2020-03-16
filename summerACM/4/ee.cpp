#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long ll;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 1e5 + 5;
struct node {
    int to, next, val;
} e[N << 1];
int head[N], cnt, p[N], np[N], ctp, num[N];

void get_prime() {
    for (int i = 2; i < N; i++) {
        if (!np[i]) {
            p[++ctp] = i;
            num[i]++;
            for (int j = 2 * i; j < N; j += i)
                np[j] = 1, num[j]++;
        }
    }
}

void add(int x, int y, int w) {
    e[cnt].to = y;
    e[cnt].next = head[x];
    e[cnt].val = w;
    head[x] = cnt++;
}

ll dfs(int pos, int fa, int num) {
    int ans = 0;
    for (int i = head[pos]; ~i; i = e[i].next) {
        int ne = e[i].to;
        if (ne == fa)
            continue;
        if (e[i].val + num <= 2)
            ans += dfs(ne, pos, num + e[i].val);
    }
    if (num == 2)
        ans++;
    return ans;
}

int main() {
    get_prime();
    freopen("evaluations.in","r",stdin);
    int tt = read();
    int cas = 0;
    while (tt--) {
        cnt = 0;
        memset(head, -1, sizeof(head));
        int n = read();
        int u, v, w;
        F(i, 1, n - 1) scanf("%d%d%d", &u, &v, &w), add(u, v, num[w]), add(v, u, num[w]);
        ll ans = 0;
        F(i, 1, n) ans += dfs(i, 0, 0);
        //printf("Case %d: %I64d\n", ++cas, ans / 2);
        cout << "Case " << ++cas << ": " << ans / 2 << endl;
    }
    return 0;
}
