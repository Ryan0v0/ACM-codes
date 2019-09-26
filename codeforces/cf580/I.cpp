//
// Created by 赵婉如 on 2019-08-20.
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
const int N=1e5+10,M=2e5+10;
int  n,m,tot,head[N];
struct edge{int fro,go,next;}e[M];/*
void add(int x,int y,LL v)
{
    e[++tot]=(edge){x,y,head[x],v};head[x]=tot;
    e[++tot]=(edge){y,x,head[y],v};head[y]=tot;
}*/
void add(int x,int y)
{
    e[++tot]=(edge){x,y,head[x]};head[x]=tot;
    e[++tot]=(edge){y,x,head[y]};head[y]=tot;
}
int X,Y;
LL w[N];
LL dp[N][5];
//dp[i][0] i子树不翻转
//dp[i][1] i子树翻转
bool rev[N];
bool flag;
void dfs(int x,int fa)
{
    if(rev[x]) flag^=1;
    if(flag) w[x]=-w[x];
    dp[x][0]=w[x];
    dp[x][1]=-w[x];
    R(i,x){
        int y=e[i].go;
        if(y==fa) continue;
        dfs(y,x);
        LL t=0;
        if(rev[y]) t=Y;else t=X;
        dp[x][0]+=max(dp[y][0],dp[y][1]-t);
        dp[x][1]+=max(dp[y][1],dp[y][0]-t);
    }
    if(rev[x]) flag^=1;
    //printf("dp[%d][0]=%d,dp[%d][1]=%d\n",x,dp[x][0],x,dp[x][1]);
}
int main()
{
    while(scanf("%d%d%d",&n,&X,&Y)==3){
        mec(w,0);mec(dp,0);
        w[0]=0;rev[0]=0;
        tot=0;mec(head,0);
        F(i,1,n){
            w[i]=read();
            int fa=read();
            add(fa,i);
            rev[i]=read();
            bool like=read();
            if(like) w[i]=-w[i];
        }
        //for(int i=1;i<=n;i++) cout<<w[i]<<' ';cout<<endl;
        dfs(0,0);
        if(dp[0][0]<0){
            puts("HAHAHAOMG");
        }else{
            cout<<dp[0][0]<<endl;
        }
    }
    return 0;
}
/*
4 3 2
5 0 0 0
3 1 0 1
4 2 1 0
1 2 0 0


7 2 1
5 0 0 0
4 1 0 1
1 1 0 1
2 1 0 0
3 2 0 1
6 3 1 0
7 3 0 0
1 3 0 0
*/