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
const int maxn=200;
double f[maxn][maxn][5];
int n,m;
int main()
{
    int tt=read();
    while(tt--){
        n=read();
        m=read();
    }
    f[0][0][0]=f[0][0][1]=1;
    F(i,0,n-1) F(j,0,n-1){
        f[i][j][0]=f[i][j][1];
        if(i>=1){
            f[i][j][]=f[i-1][j]
        }
    }
    return 0;
}