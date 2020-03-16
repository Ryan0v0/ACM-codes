//
// Created by 赵婉如 on 2019-08-13.
//

//
// Created by 赵婉如 on 2019-08-13.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 1e5 + 5;
struct node {
    int go, next;
    LL w;
} e[N << 1];
bool notprime[N];
int head[N], tot, p[N], priNum, cnt[N];

void add(int x, int y, LL z) {
    e[++tot].go = y;
    e[tot].w = z;
    e[tot].next = head[x];
    head[x] = tot;
    e[++tot].go = x;
    e[tot].w = z;
    e[tot].next = head[y];
    head[y] = tot;
}

LL dfs(int x, int fa, int num) {
    int cnt = 0;
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].go;
        if (y == fa) continue;
        if (e[i].w + num <= 2) cnt += dfs(y, x, num + e[i].w);
    }
    if (num == 2) cnt++;
    return cnt;
}

void get_prime() {
    F(i, 2, N) {
        if (!notprime[i]) {
            p[++priNum] = i;
            cnt[i]++;
            for (int j = 2 * i; j < N; j += i) {
                notprime[j] = true;
                cnt[j]++;
            }
        }
    }
}

int main() {
    get_prime();
    //cout << "priNum=" << priNum << endl;
    int tt = read();
    //freopen("evaluations.in", "r", stdin);
    F(Case, 1, tt) {
        tot = 0;
        mec(head, -1);
        int n = read();
        int u, v, w;
        F(i, 1, n - 1) {
            int x = read();
            int y = read();
            LL w = read();
            add(x, y, cnt[w]);
        }
        LL ans = 0;
        F(i, 1, n) ans += dfs(i, 0, 0);
        cout << "Case " << Case << ": " << ans / 2 << endl;
    }
    return 0;
}