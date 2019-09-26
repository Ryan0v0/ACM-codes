//
// Created by 赵婉如 on 2019-08-17.
// 11:30-1:00
// wa1 注意d要用LL!
//


#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
#define MOD 998244353
const int N=1010;
LL f[N][N];
int n;LL d;
LL qpow(LL x,LL b)        //求x^n%mod
{
    LL ret=1;
    for(; b; b>>=1)
    {
        if(b&1) ret=ret*x%MOD;
        x=x*x%MOD;
    }
    return ret;
}

LL C(LL a,LL b=2)
{
    return a%MOD*(a-1)%MOD/2%MOD;
    //return a*(a-1)%MOD*qpow(b,MOD-2)%MOD;
}
void init()
{
    f[1][1]=2;
    F(i,1,N-10){
        f[i+1][0]=(f[i+1][0]+2*f[i][0]%MOD*C(2*i+1,2)%MOD)%MOD;
        f[i+1][0]=(f[i+1][0]+2*f[i][1]%MOD*(2*i)%MOD)%MOD;
        f[i+1][0]=(f[i+1][0]+2*f[i][2]%MOD)%MOD;
        F(j,1,i+1){
            f[i+1][j]=(f[i+1][j]+2*f[i][j-1]%MOD*(2*i+1-(j-1))%MOD)%MOD;
            f[i+1][j]=(f[i+1][j]+2*f[i][j]%MOD*(j+C(2*i+1-j,2))%MOD)%MOD;
            f[i+1][j]=(f[i+1][j]+2*f[i][j+1]%MOD*((j+1)*(2*i+1-(j+1))%MOD%MOD))%MOD;
            f[i+1][j]=(f[i+1][j]+2*f[i][j+2]%MOD*C(j+2,2)%MOD)%MOD;
        }
    }
}
int main()
{
    init();
    while(~scanf("%d%lld",&n,&d)){
        LL ans=0,now=1LL;
        F(i,0,n){//注意从0开始!
            //cout<<"f[n][i]="<<f[n][i]<<endl;
            ans=(ans+f[n][i]*now%MOD)%MOD;
            now=now*d%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}