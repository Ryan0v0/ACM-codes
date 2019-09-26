//
// Created by 赵婉如 on 2019-08-15.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define LL long long
#define P 1000000007
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
void exgcd(LL a,LL b,LL &d,LL &x,LL& y)
{
    if(!b)d=a,x=1,y=0;
    else exgcd(b,a%b,d,y,x),y-=x*(a/b);
}
LL inv(LL a,LL p)
{
    LL d,x,y;exgcd(a,p,d,x,y);
    return (x+p)%p==0?p:(x+p)%p;
}
LL _pow(LL a,LL n,LL Mod)
{
    LL res=1;
    while(n)
    {
        if(n&1)res=(res*a)%Mod;
        n>>=1;a=(a*a)%Mod;
    }
    return res;
}
LL sqr(LL x)
{
    return _pow(x,inv(2,P-1)%(P-1),P);
}
int main()
{
    int T=read();
    while(T--)
    {
        LL b=read(),c=read();
        bool flag=false;
        //F(x,1,b/2){
        LL x=1;
        for(x=1;x<=(LL)(P+b)/2;x++){
            if((x*x%P-b*x%P+c%P+P)%P==0){
                flag=1;
                break;
            }
        }
        if(!flag){
            puts("-1 -1");
        }else{
            cout<<x<<' '<<b-x<<endl;
        }
    }
    return 0;
}