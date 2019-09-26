//
// Created by 赵婉如 on 2019-07-19.
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
#define MOD 1000000007
LL mypow(LL x, LL n){
    LL res = 1LL;
    while(n){
        if(n & 1LL)
            res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        n >>= 1;
    }
    return res;
}
const int N=100010;
int n;
LL a[N],a2[N];
LL ans;
int main()
{
    while(scanf("%d",&n)==1){
        ans=0LL;
        F(i,1,n){
            a[i]=read();
            a2[i]=a[i]*a[i]%MOD;
        }
        F(i,1,n){
            LL t=2LL*a[i]%MOD;
            F(j,1,n){
                if(i!=j){
                    t=(a2[j]-a2[i]+MOD)*t%MOD;
                }
            }
            ans=(ans+mypow(t,MOD-2))%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}