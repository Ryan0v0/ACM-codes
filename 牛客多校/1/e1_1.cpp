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
int a[N],days[N];
LL ans;
void solve()
{
    F(i,1,n) days[min(a[i],n)-1]++;
    D(i,n-1,0){
        if(i>0) days[i-1]+=max(days[i]-k,0);
        ans+=min(days[i],k);
    }
    cout<<ans<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        n=read();k=read();mec(days,0);ans=0;
        F(i,1,n) a[i]=read();
        solve();
    }
    return 0;
}
/*
4
2 1
1 1
5 1
3 2 3 2 3
2 2
1 1
6 2
1 1 1 7 7 7

 */
