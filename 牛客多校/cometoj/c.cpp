//
// Created by 赵婉如 on 2019-08-12.
//

//
// Created by 赵婉如 on 2019-08-12.
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
const int N=100010;
LL f[N][5];
LL a[N],b[N];
int main()
{
    int n=read();int k=read();
    F(i,1,n){
        a[i]=read();
        b[i]=read();
    }
    F(i,1,n){
        f[i][0]=f[i-1][0]+b[i-1]*a[i];
        f[i][1]=min(f[i-1][1]+b[i-1]*a[i]*k*k,f[i-1][0]+b[i-1]*a[i]*k);
        f[i][2]=min(f[i-1][2]+b[i-1]*a[i],f[i-1][1]+b[i-1]*k*a[i]);
    }
    cout<<min(f[n][0],min(f[n][1],f[n][2]));
    return 0;
}