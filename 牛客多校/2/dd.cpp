//
// Created by 赵婉如 on 2019-07-20.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define inf 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn=1010;
const int maxm=100010;
int  n,m,s,t,maxflow,tot=1,head[maxn],cur[maxn],h[maxn];
queue<int>q;
struct edge{int go,next,v;}e[maxm];
void add(int x,int y,int v)
{
    e[++tot]=(edge){y,head[x],v};head[x]=tot;
    e[++tot]=(edge){x,head[y],0};head[y]=tot;
}
bool bfs()
{
    for(int i=s;i<=t;i++)h[i]=-1;
    q.push(s);h[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
            if(e[i].v&&h[e[i].go]==-1)
            {
                h[e[i].go]=h[x]+1;q.push(e[i].go);
            }
    }
    return h[t]!=-1;
}
int dfs(int x,int f)
{
    if(x==t) return f;
    int tmp,used=0;
    for(int i=cur[x];i;i=e[i].next)
        if(e[i].v&&h[e[i].go]==h[x]+1)
        {
            tmp=dfs(e[i].go,min(e[i].v,f-used));
            e[i].v-=tmp;if(e[i].v)cur[x]=i;
            e[i^1].v+=tmp;used+=tmp;
            if(used==f)return f;
        }
    if(!used) h[x]=-1;
    return used;
}
void dinic()
{
    maxflow=0;
    while(bfs())
    {
        for (int i=s;i<=t;i++)cur[i]=head[i];maxflow+=dfs(s,inf);
    }
}
int k;
int main()
{
    n=read();k=read();
    s=0;t=2*n+1;
    F(i,1,n){
        int val=read();
        if(val>=0){
            add(s,i,val);
        }else{
            add(i+n,t,-val);
        }
    }
    F(i,1,n) {
        F(j,1,n) {
            int xx = read();
            if (xx) add(i, n + j, 1);
        }
    }
    dinic();
    return 0;
}