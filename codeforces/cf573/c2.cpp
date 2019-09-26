//
// Created by 赵婉如 on 2019-07-13.
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

//fdlasfjlasdijgflidjasl
LL n, K, p[100010];
int m, ans;
//dlfsjafjsdalifjlsdaf
int main()
{
    LL n=read();int m=read();LL K=read();
    F(i,1,m) p[i]=read();
    for (int i = 1, j, t; i <= m; ) {
        j = i; t = i - 1;
        LL pos = (p[i] - t) % K;
        if (pos == 0) pos = K;
        while (j <= m && p[j] - p[i] + pos <= K) j++;
        i = j; ans++;
    }
    cout<<ans<<endl;
    return 0;
}