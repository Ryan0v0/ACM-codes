//
// Created by 赵婉如 on 2019-09-29.
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
const int N=3000;
#define MOD 1000000007
int n,m;
int h[N],w[N];
int g[N][N];
int main()
{
    n=read();m=read();bool ok=1;
    //F(i,1,n) F(j,1,m) g[i][j]=-1;
    F(i,1,n){
        h[i]=read();
        F(j,1,h[i]){
            if(g[i][j]==-1) ok=0;
            g[i][j]=1;
        }
        if(g[i][h[i]+1]==1) ok=0;
        g[i][h[i]+1]=-1;
    }
    F(i,1,m){
        w[i]=read();
        F(j,1,w[i]){
            if(g[j][i]==-1) ok=0;
            g[j][i]=1;
        }
        if(g[w[i]+1][i]==1) ok=0;
        g[w[i]+1][i]=-1;
    }
    if(!ok){
        cout<<0<<endl;
        return 0;
    }
    LL ans=1LL;
    F(i,1,n) F(j,1,m){
        if(g[i][j]==0){
            //ok=1;
            ans=ans*2LL%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
3 4
4 4 4
3 3 3 2

 */