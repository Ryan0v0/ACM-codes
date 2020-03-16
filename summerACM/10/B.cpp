//
// Created by 赵婉如 on 2019-08-27.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
void solve()
{
    F(n,1,10){
        LL ans=0;
        F(i,1,n) ans+=gcd(n,i);
        ans=n*n-ans;
        cout<<n<<' '<<ans<<endl;
    }
}
int main()
{
    int n=read();
//    F(n,1,10){
        LL ans=0;
        F(m,1,n){
            if(n%m==0) ans+=((m*m)-n);
        }
        cout<<n<<' '<<ans<<endl;
//    }
}