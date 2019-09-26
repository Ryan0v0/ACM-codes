//
// Created by 赵婉如 on 2019-07-17.
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
#define maxn 505
int n, ans, a[maxn], f[maxn][maxn];
int main()
{
    n = read();
    memset(f, -60, sizeof(f));
    f[0][0] = 0;
    a[0] = -(1 << 30);
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < i; ++k)
            {
                if (a[j] <= a[i])
                {
                    f[i][k] = max(f[i][k], f[j][k] + a[i]);
                    ans = max(ans, f[i][k]);
                }
                if (a[k] <= a[i])
                {
                    f[j][i] = max(f[j][i], f[j][k] + a[i]);
                    ans = max(ans, f[j][i]);
                }
            }
        }
    }/*
    F(i,0,n) F(j,0,n) F(k,max(i,j)+1,n){
                if(a[k]>a[i]){
                    f[k][j]=max(f[k][j],f[i][j]+a[k]);
                }if(a[k]>a[j]){
                    f[i][k]=max(f[i][k],f[i][j]+a[k]);
                }
                ans=max(ans,max(f[k][j],f[i][k]));
            }*/
    F(i,1,n) {
        F(j,1,n) cout<<f[i][j]<<' ';
        cout<<endl;
    }
    printf("%d\n", ans);
    return 0;
}