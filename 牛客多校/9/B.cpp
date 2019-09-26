//
// Created by 赵婉如 on 2019-08-15.
//

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
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
        puts("------");
        LL b=read(),c=read();
        /*cout<<"b="<<b<<' '<<"c="<<c<<endl;
        if(b*b-4*c<0){
            c-=P;
            cout<<"***"<<b*b-4*c<<endl;
        }
        cout<<"inv="<<inv(1,P)<<endl;
        LL delta=((b*b%P-4*c%P)+P)%P;
        LL sq=sqr(delta);
        if(sq*sq%P!=delta)puts("!!");
        LL x=inv(1,P)*(b-sq+P)%P*inv(2,P)%P;
        LL y=inv(1,P)*(b+sq+P)%P*inv(2,P)%P;*/
        LL sq=sqrt((P+b)*(P+b)/4-c);cout<<sq<<' '<<(P+b)*(P+b)/4-c<<endl;
        if(sq*sq==((P+b)*(P+b)/4-c)){
            cout<<"《1111》"<<endl;
            cout<<inv(2,P-1)*sq<<' '<<inv(2,P-1)*sq+P<<endl;
        }else{
            cout<<"《2222》"<<endl;
            cout<<(-sqr(2+4*c)-1)*b*inv(2,P)<<' '<<(-sqr(2+4*c)-1)*b*inv(2,P)<<endl;
        }
        //printf("%lld %lld\n",x,y);
        //puts("------");
    }
    return 0;
}