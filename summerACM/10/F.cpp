//
// Created by 赵婉如 on 2019-08-27.
//

#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
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

int n;

const int MAXN = 1e5 + 10;
int a[MAXN];
int dp[MAXN];

int lis() {
    memset(dp, 0, sizeof(int) * n);
    int len = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        int pos = upper_bound(dp, dp + len, a[i]) - dp;
        dp[pos] = a[i];
        len = max(len, pos + 1);
    }
    //cout<<"len="<<len<<endl;
    return len;
}


int main() {
    int tt = read();
    while (tt--) {
        n = read();
        F(i, 0, n - 1) a[i] = read();
        int ans1 = lis();
        reverse(a, a + n);
        int ans2 = lis();
        //cout<<ans1<<' '<<ans2<<endl;
        if (n - max(ans1, ans2) <= 1) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}
/*
100
3
2 1 7
3
3 2 1
5
3 1 3 1 5
7
1 2 3 4 5 6 7
7
1 1 1 1 1 1 1
7
7 6 5 4 3 2 1
7
1 2 3 2 2 3 5
6
1 2 1 3 1 4

 */