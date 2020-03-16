//
// Created by 赵婉如 on 2019-08-23.
//

#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
const int maxn = 5e5 + 10;
const int Block = 719;
LL a[maxn];
LL ans[Block + 10][Block + 10];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int q, tp, x, y;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &tp, &x, &y);
        if (tp == 1) {
            a[x] += y;
            for (int mod = 1; mod <= Block; ++mod)
                ans[mod][x % mod] += y;
        } else {
            if (x <= Block)
                printf("%lld\n", ans[x][y]);
            else {
                LL sum = 0ll;
                for (int i = y; i <= 500000; i += x)
                    sum += a[i];
                printf("%lld\n", sum);
            }
        }
    }
    return 0;
}