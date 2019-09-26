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
const int N=64;
int dp[N][N][N][N];
int a[N][N];//sum(x,y)
char str[N];
int area(int x,int y,int xx,int yy)
{
    return a[xx][yy]-a[x-1][yy]-a[xx][y-1]+a[x-1][y-1];
}
int dfs(int lx,int rx,int ly,int ry)
{
    if(area(lx,ly,rx,ry)==0) {
        return 0;
    }
    if(dp[lx][rx][ly][ry]!=-1){
        return dp[lx][rx][ly][ry];
    }
    int &f=dp[lx][rx][ly][ry];//引用 同时改变!
    f=max(rx-lx+1,ry-ly+1);
    F(i,lx,rx-1) f=min(f,dfs(lx,i,ly,ry)+dfs(i+1,rx,ly,ry));
    F(i,ly,ry-1) f=min(f,dfs(lx,rx,ly,i)+dfs(lx,rx,i+1,ry));
    return f;
}
int main()
{
    int n=read();
    F(i,1,n) {
        scanf("%sv", str + 1);
        F(j, 1, n) {
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(str[j]=='#');
        }
    }
    //F(i,1,n){ F(j,1,n) cout<<a[i][j]<<' ';cout<<endl;}
    mec(dp,-1);
    cout<<dfs(1,n,1,n)<<endl;
    return 0;
}
