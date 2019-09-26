
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
int n;
LL a[100010];
LL b[100010];
LL dp[100010][5];
LL f[100010][5];
int main()
{
    int n=read();
    F(i,1,n) a[i]=read();
    F(i,1,n) b[i]=read();
    dp[0][1]=dp[0][2]=0;
    dp[1][1]=a[1];dp[1][2]=b[1];
    f[1][1]=a[1];f[1][2]=b[1];
    F(i,2,n) {
        dp[i][1]=max(f[i-2][1]+a[i],f[i-1][2]+a[i]);
        dp[i][2]=max(f[i-2][2]+b[i],f[i-1][1]+b[i]);
        f[i][1]=max(f[i-1][1],dp[i][1]);
        f[i][2]=max(f[i-1][2],dp[i][2]);
    }
    cout<<max(f[n][1],f[n][2])<<endl;
    return 0;
}

