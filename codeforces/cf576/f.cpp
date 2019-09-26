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
const int N=55;
int g[N][N];
int dp[N][N][N][N];
int sum[N][N];//sum(x,y)
char str[N];
int main()
{
    int n=read();
    F(i,1,n) {
        scanf("%s", str + 1);
        F(j, 1, n) {
            if (str[j] == '#') g[i][j] = 1;
            else if (str[j] == '.') g[i][j] = 0;
        }
    }
        sum[0][0]=0;sum[0][1]=0;sum[1][0]=0;
        sum[1][1]=g[1][1];
        F(i,1,n) F(j,1,n){
            sum[i][j]=g[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
        F(i,1,n) F(j,1,n) F(p,i,n) F(k,j,n){
            dp[i][j][p][k]=sum[p][k]-sum[p][j-1]-sum[i-1][k]+sum[i-1][j-1];
        }
        F(i,1,n) F(j,1,n) F(p,i,n) F(k,j,n) F(q,){
            dp[i][j][p][k]=sum[p][k]-sum[p][j-1]-sum[i-1][k]+sum[i-1][j-1];
        }
    }
    return 0;
}

