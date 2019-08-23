//
// Created by 赵婉如 on 2019-08-23.
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
LL x;
LL ans;
int main()
{
    printf("?");
    F(i,1,100) printf(" %d",i);printf("\n");
    fflush(stdout);
    scanf("%d",&x);
    ans+=((x>>7)<<7);
    printf("?");
    F(i,1,100) printf(" %d",i*128);printf("\n");
    fflush(stdout);
    scanf("%d",&x);
    ans+=(x&((1<<7)-1));
    printf("! %lld\n",ans);
    return 0;
}