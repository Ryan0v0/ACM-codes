//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 10000000000000000////
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n,k;
const int N=4e5+10;
int tot=0,head[N];
struct edge{int fro,go,next,v;}e[N];
void add(int x,int y,int v)
{
    e[++tot]=(edge){x,head[x],v};head[x]=tot;
    e[++tot]=(edge){x,head[y],v};head[y]=tot;
}
int dp[N][N];
int siz[N];
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].go;
        if(y==fa) continue;
        dfs(y,x);
        int lx=min(k,siz[x]);
        int ly=min(k,siz[y]);
        F(p,0,lx) for(int q=0;q<=ly&&p+q<=k;q++){
            dp[x][p+q]=min(dp[x][p+q],dp[y][q]+e[i].v*(k-q)*q)
        }
        siz[x]+=siz[y];
    }
}
int main()
{
    int tt=read();
    F(Case, 1, tt) {
        cout << "Case #" << Case << ": " << endl;
        n=read();k=read();
        F(i,1,n-1){
            int x=read();int y=read();LL w=read();
            add(x,y,w);
        }
        dfs(1,-1);
        cout<<dp[1][k]<<endl;
    }
    return 0;
}