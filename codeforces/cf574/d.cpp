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
#define mod 998244353
int n;
LL ans;
int main()
{
    n=read();
    F(i,1,n){
        LL x=read();
        LL t=x;
        LL sum=0;
        LL pow=1LL;
        while(t){
            //cout<<t%10<<' '<<sum<<endl;
            sum+=(t%10)%mod*pow%mod;
            t/=10;
            pow=pow%mod*100%mod;
            //cout<<"~~~pow="<<pow<<endl;
        }
        (ans+=((sum%mod)%mod+sum%mod*10LL%mod)%mod*n%mod)%=mod;
        //ans=(ans%mod+((sum%mod)%mod+sum%mod*10LL%mod)%mod*n%mod)%mod;
        //cout<<"ans="<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}