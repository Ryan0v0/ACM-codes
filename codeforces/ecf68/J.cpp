//
// Created by 赵婉如 on 2019-09-28.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int n, m, b[2][MAXN];
typedef long long LL;
LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b) {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--){
        memset(b, 0, sizeof(b));
        scanf("%d%d", &n, &m);
        while (m--){
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            if (x == 2) b[0][l]++, b[0][r + 1]--;
            if (x == 3) b[1][l]++, b[1][r + 1]--;
        }
        int two = INF, three = INF, sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            sum1 += b[0][i];
            sum2 += b[1][i];
            two = min(two, sum1);
            three = min(three, sum2);
        }
        printf("%lld\n", qpow(2, two) * qpow(3, three) % MOD);
    }
    return 0;
}
/*
2
5 3
1 3 2
3 5 2
1 5 3
6 3
1 2 2
5 6 2
1 6 2
*/
