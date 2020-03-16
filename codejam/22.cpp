//
// Created by 赵婉如 on 2020-02-16.
//

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
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

const int N = 110;
int f[N][3];//a - b = 1(-1) 2(0) 3(1); sum(a) - sum(b)
int n, a[N];

int main() {
    int tt = read();
    while (tt--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            f[i][1] = f[i][2] = f[i][3] = INT_MAX;
        }
        f[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            f[i][1] = min(f[i][1], f[i - 1][2] - a[i]);
            f[i][2] = min(f[i][2], f[i - 1][1] + a[i], f[i - 1][3] - a[i]);
            f[i][3] = min(f[i][3], f[i - 1][2] + a[i]);
        }
        cout << min(f[n][1], f[n][2], f[n][3]) << endl;
    }
    return 0;
}