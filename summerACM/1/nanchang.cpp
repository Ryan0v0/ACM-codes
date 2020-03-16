//
// Created by 赵婉如 on 2019-08-09.
//

#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn=1005;
const int MOD=9999991;

int T,n,m;
LL a[maxn],inv[MOD+5],finv[maxn];
LL sum[maxn],ans;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void init(){
    inv[1]=1;
    for(int i=2;i<=MOD+5;++i)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
    finv[0]=1;
    for(int i=1;i<=1000;++i)
        finv[i]=finv[i-1]*inv[i]%MOD;
}

LL cal(LL x,LL *a,LL up){
    LL res=0;
    LL p=1;
    for(LL i=0;i<=up;++i)
        p=p*(x-i)%MOD;
    for(LL i=0;i<=up;++i){
        int f=(up-i)&1?-1:1;
        res=(res+MOD+a[i]*f*p%MOD*inv[x-i]%MOD*finv[i]%MOD*finv[up-i]%MOD)%MOD;
    }
    return res;
}

int main(){
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;++i){
            scanf("%lld",&a[i]);
            a[i]%=MOD;
        }
        a[n+1]=cal(n+1,a,n);
        sum[0]=a[0];
        for(int i=1;i<=n+1;++i)
            sum[i]=(sum[i-1]+a[i])%MOD;
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            if(r<=n+1){
                printf("%lld\n",(sum[r]-sum[l-1]+MOD)%MOD);
                continue;
            }
            if(l-1<=n+1)
                ans=(cal(r,sum,n+1)-sum[l-1]+MOD)%MOD;
            else
                ans=(cal(r,sum,n+1)-cal(l-1,sum,n+1)+MOD)%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}