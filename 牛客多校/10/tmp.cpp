//
// Created by 赵婉如 on 2019-08-17.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define CLR(x) memset(x,0,sizeof(x))
#define _CLR(x) memset(x,-1,sizeof(x))
#define REP(i,n) for(int i=0;i<n;i++)
#define Debug(x) cout<<#x<<"="<<x<<" "<<endl
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define rep(i,l,r) for(int i=l;i<r;i++)
#define RREP(i,l,r) for(int i=l;i>=r;i--)
#define rrep(i,l,r) for(int i=1;i>r;i--)
#define put(x) printf("%d\n",x)
//#define ll long long
#define ll __int128
#define lson l,m,rt<<1
#define rson m+1,r,rt<<11
using namespace std;
inline ll read()
{
    ll x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x/10);
    putchar(x%10 + '0');
}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0,d=a;
        return;
    }
    exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

int main()
{
        ll a1,r1,a2,r2;
        ll n=read();ll m=read();
        //scanf("%lld%lld",&a1,&r1);
        a1=read();r1=read();
        bool flag=1;
        REP(i,2,n){
            ll d,x,y;
            //scanf("%lld%lld",&a2,&r2);
            a2=read();r2=read();
            ll ans=0;
            exgcd(a1,a2,d,x,y);   //扩展欧几里德算法
            if((r2-r1)%d) flag=0; //扩展欧几里德算法的性质，如果不能整除，则无法合并。
            else{
                x*=((r2-r1)/d);
                ll n1=a2/d;
                x=(x%n1+n1)%n1;   //x不断地加a2/gcd直到x大于0，如果用循环的话会超时，x可以通过直接取模计算。由于这里用不到y的值，所以暂时可以不用管
                r1=a1*x+r1;      //这相当于是x0的值
                a1=(a1*a2)/d;    //将a1变成a1和a2的最小公倍数
            }
        }
        if(flag){
            if(r1<=m){
                print(r1);
                //cout<<r1<<endl;
                //printf("%lld\n",r1);
            }else{
                printf("he was probably lying\n");
            }
        }
        else printf("he was definitely lying\n");
        return 0;
}
/*
2 1000000000000000000
100000 9999
9999 9998
 */