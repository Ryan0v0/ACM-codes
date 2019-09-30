//
// Created by 赵婉如 on 2019-09-29.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int, int> VII;
#define inf 0x3f3f3f3f
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 1e5 + 7;
const ll MAXM = 1e5 + 7;
const ll MOD = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1.0);
int a[MAXN];
int b0[MAXN], b1[MAXN], b[MAXN];
int vis[MAXN];
int main()
{
    int t;
    scanf("%d", &t);
    for (int Case = 1; Case <= t; Case++)
    {
        memset(vis, 0, sizeof(vis));
        int cnt1 = 0, cnt2 = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int j = 0; j < m; j++)
            scanf("%d", &b[j]);
        for (int j = 0; j < m; j++)
        {
            int t;
            scanf("%d", &t);
            if (t)
                b1[cnt2++] = b[j]; /* 防御 */
            else
                b0[cnt1++] = b[j]; /* 攻击 */
        }
        int ans1 = 0, ans2 = 0;
        sort(a, a + n);
        sort(b0, b0 + cnt1);
        sort(b1, b1 + cnt2);
        /*先尝试一下能不能打爆所有防御的*/
        int posa = 0, posb = 0;
        while (posa < n && posb < cnt2)
        {
            if (b1[posb] <= a[posa])
            {
                vis[posa] = 1;
                posa++;
                posb++;
            }
            else
                posa++;
        }
        if (posb >= cnt2) /* 我把防守的打完了！ */
        {
            /* 试试能不能打完攻击的 */
            posa = 0, posb = 0;
            while (posa < n && posb < cnt1)
            {
                if (!vis[posa] && b0[posb] <= a[posa])
                {
                    vis[posa] = 1;
                    ans1 += a[posa] - b0[posb];
                    posa++;
                    posb++;
                }
                else if (vis[posa])
                    posa++;
            }
            if (posb >= cnt1) /* 打完了攻击的 */
            {
                for (int i = 0; i < n; i++)
                    if (!vis[i])
                        ans1 += a[i];
            }
            else
                ans1 = 0;
        }
        else /* 打不过防守的 */
        {
            /* 尝试一下暴打攻击的 */
            posa = n - 1, posb = 0;
            while (posa >= 0 && posb < cnt1)
            {
                if (a[posa] >= b0[posb])
                {
                    ans2 += a[posa] - b0[posb];
                    posa--;
                    posb++;
                }
                else
                    break;
            }
            if (posb < cnt1)
                ans2 = 0;
        }
        printf("Case %d: %d\n", Case, max(ans1, ans2));
    }
    return 0;
}