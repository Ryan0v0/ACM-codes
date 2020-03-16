//
// Created by 赵婉如 on 2019-08-09.
//


#include <bits/stdc++.h>
#define fir first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
const int maxn=3000+10;
const ll mod=998244353;
const double eps=1e-7;
const int maxm=1e6+10;
const int inf=0x3f3f3f3f;
//怕炸空间没敢开long long
int c[maxn][maxn];   //组合数
int p[maxn*maxn];   //2的倍数
int g[maxn][maxn];
int n,m,a,b;
int i,j,k;
void init(){
    for (i=0;i<maxn;i++) c[i][0]=1;
    for (i=1;i<=3000;i++){
        for (j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    p[0]=1;
    for (i=1;i<maxn*maxn;i++)
        p[i]=(ll)p[i-1]*2%mod;
}
int fa[maxn],fb[maxn];  //容斥系数
int main() {
    init();
    while (scanf("%d %d %d %d", &n, &m, &a, &b) != EOF) {
        ll ans = 0;
        for (j = a; j <= n; j++) {
            fa[j] = 1;
            for (k = a; k <= j - 1; k++) {
                fa[j] = (fa[j] - (ll) c[j][k] * fa[k]) % mod;
                //这个部分在前面出现了c[j][k]*fa[k]次
                //考虑j之前的结果，在计算的时候包括了j的情况，相当于在j行中选出k行作为a[k]的计算结果
                //因为容斥的时候还有a[k]的系数，所以要乘上一个a[k]
                //fa[j]=(fa[j]+mod)%mod;
            }
        }
        for (j = b; j <= m; j++) {
            fb[j] = 1;
            for (k = b; k <= j - 1; k++) {
                fb[j] = (fb[j] - (ll) c[j][k] * fb[k]) % mod;
                //这个部分在前面出现了c[j][k]*fa[k]次
                //考虑j之前的结果，在计算的时候包括了j的情况，相当于在j行中选出k行作为a[k]的计算结果
                //因为容斥的时候还有a[k]的系数，所以要乘上一个a[k]
                //fb[j]=(fb[j]+mod)%mod;
            }
        }
        /*for (int i=1;i<=n;i++)
            cout<<fa[i]<<" ";
        cout<<endl;
        for (int i=1;i<=m;i++)
            cout<<fb[i]<<" ";
        cout<<endl;*/
        for (i = a; i <= n; i++) {
            for (j = b; j <= m; j++) {
                g[i][j] = (ll) p[(n - i) * (m - j)] * c[n][i] % mod;
                g[i][j] = (ll) g[i][j] * c[m][j] % mod;
            }
        }
        for (i = a; i <= n; i++) {
            for (j = b; j <= m; j++) {
                ans = (ans + (ll) fa[i] * fb[j] % mod * (ll) g[i][j]) % mod;
            }
        }
        if (ans < 0) {
            ans = (ans + mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}