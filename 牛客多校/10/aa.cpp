//
// Created by 赵婉如 on 2019-08-26.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
LL a,b;
LL n;
int main()
{
    int tt=read();
    while(tt--){
       a=read();b=read();n=read();
       switch(n%3){
           case 0:cout<<a<<endl;break;
           case 1:cout<<b<<endl;break;
           case 2:cout<<(a xor b)<<endl;break;
       }
    }
    return 0;
}