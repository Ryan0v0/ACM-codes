//
// Created by 赵婉如 on 2020-02-16.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
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
const int N=1010;
int tot;
int head[N];
struct edge{int go,next;}e[N*N];
void ins(int x,int y)
{
    e[++tot].go=y;e[tot].next=head[x];head[x]=tot;
}
int n,a[N];
bool c[N];
bool vis[N];
void dfs(int x,int col,int fa){
    c[x]=col;vis[x]=true;
    //cout<<x<<' '<<col<<' '<<fa<<endl;
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].go;
        if(vis[y]) continue;
        dfs(y,!col,x);
    }
}
void solve()
{
    n=read();mec(c,0);mec(head,0);tot=0;mec(vis,0);
    F(i,1,n) a[i]=read();
    for(int i=1;i<=n;i+=2){
        ins(i,i+1),ins(i+1,i);
        //cout<<i<<' '<<i+1<<endl;
    }
    for(int i=n;i>2;i-=2){
        ins(a[i],a[i-1]),ins(a[i-1],a[i]);
        //cout<<a[i]<<' '<<a[i-1]<<endl;
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        dfs(i,0,0);
    }
    F(i,1,n){
        if(c[i]) cout<<'L';
        else cout<<'R';
    }
    cout<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}
