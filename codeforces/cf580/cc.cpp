//
// Created by 赵婉如 on 2019-08-20.
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
const int N=1000010;
int ans[N];
int main()
{
    int n=read();
    int p=0;
    F(i,1,n){
        ans[i]=2*i-1;
        ans[i+n]=2*i;
        if(p) swap(ans[i],ans[i+n]);
        p^=1;
    }
    if(n&1){
        puts("YES");
        F(i,1,2*n) cout<<ans[i]<<' ';
    }else puts("NO");
    return 0;
}