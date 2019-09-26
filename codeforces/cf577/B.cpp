//
// Created by 赵婉如 on 2019-08-06.
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
LL sum;
LL mx;
int main()
{
    int n=read();mx=0LL;
    F(i,1,n){
       LL x=read();
       sum+=x;
       mx=max(mx,x);
    }
    if(sum&1) puts("NO");
    else if(mx>sum-mx) puts("NO");
    else puts("YES");
    return 0;
}
/*
5
1 1 1 1 6

 */