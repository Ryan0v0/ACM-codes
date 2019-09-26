//
// Created by 赵婉如 on 2019-08-27.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
LL mu[10000010];int flag[10000010],prime[10000010],cnt,f[10000010],sum[10000010];
void sieve() {
    mu[1]=1;
    for (int i=2;i<=10000000;i++) {
        if (!flag[i]) prime[++cnt]=i,mu[i]=-1;
        for (int j=1;j<=cnt&&i*prime[j]<=10000000;j++) {
            flag[i*prime[j]]=1;
            if (i%prime[j]==0) break;
            mu[i*prime[j]]=-mu[i];
        }
    }
    for (int i=1;i<=cnt;i++)
        for (int j=1;prime[i]*j<=10000000;j++)
            f[j*prime[i]]+=mu[j];
    for (int i=1;i<=10000000;i++)
        sum[i]=sum[i-1]+f[i];
}
LL solve(int a,int b) {
    LL ans=0;
    if (a>b) swap(a,b);
    for (int l=1,r=0;l<=a;l=r+1) {
        r=min(a/(a/l),b/(b/l));
        ans+=(LL)(sum[r]-sum[l-1])*(LL)(a/l)*(LL)(b/l);
    }
    return ans;
}
int main() {
    sieve();
    int n,m,T;scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        if (n>m) swap(n,m);
        printf("%lld\n",solve(n,m));
    }
}