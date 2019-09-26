//
// Created by 赵婉如 on 2019-08-24.
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
const int N=500010;
int n,k;
int a[N];
LL ans;
void solve()
{
    sort(a+1,a+n+1);ans=0;
    int days=0,consumed=0;
    F(i,1,n){
        if(a[i]>days&&consumed<k){
            ans++;consumed++;
            if(consumed==k){
                days++;
                consumed=0;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        n=read();k=read();
        F(i,1,n) a[i]=read();
        solve();
    }
    return 0;
}

