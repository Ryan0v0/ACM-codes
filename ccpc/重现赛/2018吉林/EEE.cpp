//
// Created by 赵婉如 on 2019-10-01.
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
int n,m;
//max{(n-m)*x+m*y}<=n*(n-1)
//x<n 偶数
//y<n 奇数

//ans=(n-m)*x/2+m*y/2
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();

    }
}