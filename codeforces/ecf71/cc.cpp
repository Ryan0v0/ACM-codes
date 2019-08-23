//
// Created by 赵婉如 on 2019-08-22.
//

#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define INF 1000000000000000000//
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

const int N = 1e6 + 10;//2e5+10
LL ans;
LL f[N][5];
char s[N];
int n, a, b;

int main() {
    int tt = read();
    while (tt--) {
        ans = 0;//+b
        n = read();
        a = read();
        b = read();
        scanf("%s", s + 1);
        f[1][0] = a + b;
        f[1][1] = INF;
        F(i, 2, n) {
            //cout << i << endl;
            if (s[i] == '1') {
                f[i][0] = INF;
            } else {
                f[i][0] = min(f[i - 1][0] + a + b, f[i - 1][1] + 2 * a + 2 * b);
            }
            f[i][1] = min(f[i - 1][0] + 2 * a + 2 * b, f[i - 1][1] + a + 2 * b);
        }
        ans = f[n][0] + b;
        cout << ans << endl;
    }
    return 0;
}
/*
4
8 2 5
00110010
8 1 1
00110010
9 100000000 100000000
010101010
2 5 1
00

 */