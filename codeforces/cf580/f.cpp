//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 10000000000000000////
using namespace std;
typedef long long LL;

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

const int N = (int) 2e5 + 10;///
struct query {
    int x, y, id;
    LL w;
    LL ans;
} q[N];

bool cmpq1(query a, query b) {
    return a.w < b.w;
}

bool cmpq2(query a, query b) {
    return a.id < b.id;
}

struct node {
    int id;
    LL w;
} p[N];

bool cmp(node a, node b) {
    return a.w < b.w;
}

int n, m;
LL d[300][300];

int main() {
    int tt=read();
    F(Case, 1, tt) {
        cout << "Case #" << Case << ": " << endl;
        n = read();
        m = read();
        F(i, 1, n) p[i].id = i, p[i].w = read();
        //mec(d,-1);
        F(i, 1, n) F(j, 1, n) d[i][j] = inf;
        F(i, 1, n) F(j, 1, n) {
                d[i][j] = read();
            }
        F(i, 1, m) {
            q[i].id = i;
            q[i].x = read();
            q[i].y = read();
            q[i].w = read();
        }
        sort(p + 1, p + n + 1, cmp);
        sort(q + 1, q + m + 1, cmpq1);
        //cout<<"m1="<<m<<endl;
        int l = 1;
        F(qx, 1, m) {
            while (l <= n && p[l].w <= q[qx].w) {
                int k = p[l].id;
                F(i, 1, n) F(j, 1, n) if (d[i][k] + d[k][j] < d[i][j]) {
                            d[i][j] = d[i][k] + d[k][j];
                        }
                l++;
            }
            q[qx].ans = d[q[qx].x][q[qx].y];
        }
        sort(q + 1, q + m + 1, cmpq2);
        //cout<<"m="<<m<<endl;
        F(i, 1, m) cout << q[i].ans << endl;
    }
    return 0;
}
/*
2
3 6
3 1 2
0 1 3
1 0 1
3 1 0
1 1 1
1 2 1
1 3 1
1 1 2
1 2 2
1 3 2
3 6
1 2 3
0 1 3
1 0 1
3 1 0
1 1 1
1 2 1
1 3 1
1 1 2
1 2 2
1 3 2

 */