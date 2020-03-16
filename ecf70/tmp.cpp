//
// Created by 赵婉如 on 2019-08-22.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#define N 200005
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,m,head[N],cnt=0;
vector<int>r,G[N];
bool vis[N];
struct Node{int nxt,to;}Edges[N*4];
void addedge(int u,int v){G[u].push_back(v);}
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!vis[v])dfs(v);
    }
    r.push_back(u);
}
int main()
{
    memset(head,-1,sizeof(head));
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int a=read(),b=read();
        addedge(b,a);
    }
    for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i);
    for(int i=0;i<r.size();i++)printf("%d ",r[i]);
    return 0;
}
/*
4 4
4 1
4 2
4 3
3 1

3 1
3 3

 */