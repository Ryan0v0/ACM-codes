//
// Created by 赵婉如 on 2019-08-07.
//


#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int M=5e5+10,N=1e5+10;
struct edge{int from,go,next;}e[2*M];
int tot=0;
int head[3*N];
void add(int x,int y)
{
    e[++tot]=(edge){x,y,head[x]};head[x]=tot;
    e[++tot]=(edge){y,x,head[y]};head[y]=tot;
}
int n,m;
int color[3*N];
bool dfs(int u,int c)
{
    color[u]=c;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].go;
        if(color[v]==c) return false;
        if(color[v]==0 && !dfs(v,-c)) return false;
    }
    return true;
}
bool solve()
{
    F(i,1,3*n){
        if(color[i]==0){
            if(!dfs(i,1)) return false;
        }
    }
}
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();
        mec(color,0);
        F(i,1,m){
            int x=read();
            int y=read();
            add(x,y);
        }
        if(solve()){

        }
    }
    return 0;
}