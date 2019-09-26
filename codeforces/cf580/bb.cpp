//
// Created by 赵婉如 on 2019-08-30.
//

//
// Created by 赵婉如 on 2019-08-30.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e6+10,M=2e5+10;
int a[N];
int n;
int mn;
int main()
{
    int tt=read();
    while(tt--){
        n=read();mn=(int)1e6+10;int res=0;
        F(i,1,n) a[i]=read();
        D(i,n,1){
            if(a[i]>mn) res++;
            mn=min(mn,a[i]);
        }
        cout<<res<<endl;
    }
}