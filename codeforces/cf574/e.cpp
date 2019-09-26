//
// Created by 赵婉如 on 2019-07-18.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=3050;
int n,m;
int a,b;
int g[N*N],h[N][N];

int dp[N][N][12][12];
void initRMQ(int n,int m)
{
    F(i,1,n) F(j,1,m) dp[i][j][0][0]=h[i][j];
    F(i,0,mm[n]) F(j,0,mm[m]) if()
}
int RMQ(int x1,int y1,int x2,int y2)
{
    int k1=mm[x2-x1+1];
}
void solve()
{
    mm[0]=-1;
    F(i,1,305) mm[i]=
}
int main()
{
    n=read();m=read();
    a=read();b=read();
    g[0]=read();int x=read(),y=read(),mod=read();
    h[1][1]=g[0];
    F(i,1,m*n){
        g[i]=(g[i-1]%mod*x%mod+y%mod)%mod;
        int xx=i/m+1;
        int yy=i%m+1;
        h[xx][yy]=g[i];
        //cout<<g[i]/m<<' '<<xx<<" "<<yy<<endl;
    }/*
    F(i,1,n) {
        F(j,1,m) cout<<h[i][j]<<' ';
        cout<<endl;
    }*/


    return 0;
}