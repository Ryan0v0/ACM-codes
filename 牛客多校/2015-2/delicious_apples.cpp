//
// Created by 赵婉如 on 2019-08-04.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 1e5 + 5;
int a[N], b[N];
LL dp1[N], dp2[N];
int main() {
    int tt=read();
    while (tt--) {
        int L, n, k;
        L=read(), n=read(), k=read();
        int c1 = 0, c2 = 0;
        for (int i = 1, x, y; i <= n; ++i) {
            x=read(), y=read();
            for (int j = 1; j <= y; ++j) {
                if (x * 2 < L)	a[++c1] = x;
                else b[++c2] = L - x;
            }
        }
        sort(a + 1, a + c1 + 1);
        sort(b + 1, b + c2 + 1);
        for (int i = 1; i <= c1; ++i) {
            if (i <= k)	dp1[i] = a[i];
            else dp1[i] = dp1[i - k] + a[i];
        }
        for (int i = 1; i <= c2; ++i) {
            if (i <= k)	dp2[i] = b[i];
            else dp2[i] = dp2[i - k] + b[i];
        }
        LL ans = (dp1[c1] + dp2[c2]) * 2;
        for (int i = 0; i <= c1 && i <= k; ++i) {
            int l = c1 - i, r = max(0, c2 - (k - i));
            ans = min(ans, L + (dp1[l] + dp2[r]) * 2);
        }
        cout << ans << endl;
        for (int i = 1; i <= c1; ++i)	dp1[i] = 0;
        for (int i = 1; i <= c2; ++i)	dp2[i] = 0;
    }
    return 0;
}