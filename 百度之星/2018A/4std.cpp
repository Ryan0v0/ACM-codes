#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const LL N=1005;
LL n,d;
LL f[N][N];
LL C (LL x,LL y)    {return x*(x-1)/2;}
void add (LL &x,LL y)
{
    x=x+y;
    if (x>=MOD) x-=MOD;
}
void prepare ()
{
    f[1][1]=2;
    for (LL u=1;u<=1000;u++)
    {
        add(f[u+1][0],2*f[u][0]%MOD*C(2*u+1,2)%MOD);
        add(f[u+1][0],2*f[u][1]%MOD*(2*u)%MOD);
        add(f[u+1][0],2*f[u][2]%MOD);
        for (LL i=1;i<=u+1;i++)
        {
            add(f[u+1][i],2*f[u][i-1]%MOD*(2*u+1-(i-1))%MOD);
            add(f[u+1][i],2*f[u][i]%MOD*(i+C(2*u+1-i,2))%MOD);
            add(f[u+1][i],2*f[u][i+1]%MOD*((i+1)*(2*u+1-(i+1)))%MOD);
            add(f[u+1][i],2*f[u][i+2]%MOD*C(i+2,2)%MOD);
        }
    }
}
int main()
{
    prepare();
    while (scanf("%lld%lld",&n,&d)!=EOF)
    {
        LL ans=0,now=1;
        for (LL u=0;u<=n;u++)
        {
            cout<<"f[n][u]="<<f[n][u]<<endl;
            add(ans,f[n][u]*now%MOD);
            now=now*d%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}