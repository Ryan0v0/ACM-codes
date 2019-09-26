//
// Created by 赵婉如 on 2019-09-23.
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
}/*
int deg[10];
struct data{
    int id,deg;
    int go;
}a[10];
bool cmp(data x,data y)
{
    return x.deg>y.deg;
}
int ans;*/
int x[100],y[100];
bool vis[10][10];
int col[10];
int n,m,ans;
void solve()
{
    mec(vis,0);
    int cnt=0;
    F(i,1,m){
        int tx=col[x[i]],ty=col[y[i]];
        if(tx>ty) swap(tx,ty);
        if(!vis[tx][ty]) vis[tx][ty]=1,cnt++;
    }
    ans=max(ans,cnt);
}
void dfs(int dep)
{
    if(dep>n){
        solve();
        return;
    }
    F(i,1,6){
        col[dep]=i;
        dfs(dep+1);
    }
}
int main()
{
    n=read();m=read();
    F(i,1,m){/*
        int x=read();int y=read();
        //deg[x]++;deg[y]++;
        a[x].deg++;a[y].deg++;
        a[x].go=y;a[y].go=x;*/
        x[i]=read();y[i]=read();
    }/*
    sort(a+1,a+n+1,cmp);
    F(i,1,5){
        ans+=min(5-i+1,a[i].deg);
    }*/
    dfs(1);
    cout<<ans;
    return 0;
}