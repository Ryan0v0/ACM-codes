//
// Created by 赵婉如 on 2019-09-30.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
#define mod 1000000007
const int N=300;
int n,K;
LL fac[N],inv[N],kpow[N],k1pow[N];
LL dp[N][N];
LL Pow(LL a,LL b)
{
    if(!b) return 1LL;
    LL res=Pow(a,b/2);
    res=1LL*res*res%mod;
    if(b&1) res=1LL*res*a%mod;
    return res;
}
LL C(LL n,LL m)
{
    if(n<m) return 0;
    return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    n=read();K=read();
    fac[0]=inv[0]=kpow[0]=k1pow[0]=1LL;
    F(i,1,n){
        fac[i]=1LL*fac[i-1]*i%mod;
        inv[i]=Pow(fac[i],mod-2);
        kpow[i]=1LL*kpow[i-1]*K%mod;
        k1pow[i]=1LL*k1pow[i-1]*(K-1)%mod;
        //cout<<i<<' '<<fac[i]<<' '<<inv[i]<<' '<<kpow[i]<<' '<<k1pow[i]<<endl;
    }
    F(i,1,n) dp[1][i]=1LL*C(n,i)*k1pow[n-i]%mod;
    F(i,2,n) F(j,1,n){
        F(k,1,j) (dp[i][j]+=1LL*dp[i-1][k]*C(n-k,j-k)%mod*(k==j?(kpow[k]-k1pow[k]+mod)%mod:kpow[k])%mod)%=mod;
        dp[i][j]=1LL*dp[i][j]*k1pow[n-j]%mod;
    }
    cout<<dp[n][n]<<endl;
    return 0;
}