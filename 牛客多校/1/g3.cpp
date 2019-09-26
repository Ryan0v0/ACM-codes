//
// Created by 赵婉如 on 2019-08-24.
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
const int N=;
int n,m;
int sx,sy,tx,ty;
int a[N][N],g[N][N];
int d[][2]={{0,1},{0,-1},{-1,0},{1,0}};
LL bit[20];
pair<int,int> traps[20];
bool vis[N];
void init()
{
    bit[0]=1;
    F(i,1,15) bit[i]=bit[i-1]<<1;
}
void solve()
{
    n=read();m=read();e=read();sx=read();sy=read();tx=read();ty=read();
    sx--;sy--;tx--;ty--;
    F(i,0,n-1) F(j,0,m-1) a[i][j]=read();
    ans=-1;
    int num=0;//traps number
    F(i,0,n-1) F(j,0,m-1) if(a[i][j]<0&&a[i][j]>-100000){
        traps[++num]=make_pair(i,j);
        g[i][j]=num;
    }

    queue<int> q;
    mec(vis,0);
    q.push(0);vis[0]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        F(i,0,n-1) F(j,0,m-1) b[i][j]=a[i][j];
        LL sum=e;
        F(i,1,num){
            if(x&bit[i]){
                sum+=
            }
        }
    }
}
int main()
{
    int tt=read();init();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}
