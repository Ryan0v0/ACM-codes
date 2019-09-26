//
// Created by 赵婉如 on 2019-08-24.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn = 1e3 + 3;
const ll mo = 998244353;
int n, a[maxn], cnt[maxn], psc[maxn];
ll dp[maxn][maxn];
ll C[maxn][maxn], frac[maxn];
void init()
{
    F(i,0,maxn)C[i][0] = C[i][i] = 1;
    F(i,2,maxn) F(j,1,i-1) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
    frac[0] = 1;
    F(i,1,maxn) frac[i] = frac[i - 1] * (ll)i % mo;
}
int main() {
    int t=read();init();
    while(t--){
        n=read();
        for(int i = 1; i <= n; ++i) cnt[i] = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            ++cnt[a[i]];
        }
        psc[0] = 0;
        for(int i = 1; i <= n; ++i)
            psc[i] = cnt[i] + psc[i - 1];

        dp[0][0] = 1; // empty seq
        for(int i = 0; i < n; ++i) {
            memset(dp[i + 1], 0, sizeof(dp[0][0]) * (psc[i + 1] + 1));
            for(int j = 0; j <= psc[i]; ++j) {
                // 对于当前 a 中所有等于 i 的东西，往里面插入；且有 j 个位置不能放东西
                // cnt[i + 1] - k 个放末尾，剩下的总共有 psc[i] - j 个位置可以放
                if(dp[i][j])
                    for(int k = 0; k <= cnt[i + 1] && j + k * 2 <= psc[i + 1] && k <= psc[i] - j; ++k) {
                        // 插 k 个到可以放的地方上，组合数；这 cnt[i + 1] 个数是不同的，阶乘
                        dp[i + 1][j + k * 2] += dp[i][j] * C[psc[i] - j][k] % mo * frac[cnt[i + 1]];
                        dp[i + 1][j + k * 2] %= mo;
                    }
            }
        }
        ll ans = 0;
        for(int i = 0; i <= psc[n]; ++i) ans = (ans + dp[n][i]) % mo;
        cout<<ans<<endl;
    }
    return 0;
}
