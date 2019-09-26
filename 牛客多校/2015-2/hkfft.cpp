//
// Created by 赵婉如 on 2019-08-04.
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
struct cp
{
    double x,y;
    inline cp operator +(cp b){return (cp){x+b.x,y+b.y};}
    inline cp operator -(cp b){return (cp){x-b.x,y-b.y};}
    inline cp operator *(cp b){return (cp){x*b.x-y*b.y,x*b.y+y*b.x};}
};
const int maxn=2e5+10;
const double PI=acos(-1.0);
cp a[maxn],b[maxn],c[maxn],y[maxn];
int n,m,len,rev[maxn],ans[maxn];
char s[maxn];
void fft(cp *x,int n,int flag)
{
    F(i,0,n-1)y[rev[i]]=x[i];
    F(i,0,n-1)x[i]=y[i];//翻转
    for(int m=2;m<=n;m<<=1)
    {
        cp wn=(cp){cos(2.0*PI/m*flag),sin(2.0*PI/m*flag)};//w（m，1）
        for(int i=0;i<n;i+=m)//n个数按m个一份，每份内进行操作
        {
            cp w=(cp){1.0,0};int mid=m>>1;
            F(j,0,mid-1)
            {
                cp u=x[i+j],v=x[i+j+mid]*w;
                x[i+j]=u+v;x[i+j+mid]=u-v;
                w=w*wn;
            }//蝴蝶操作
        }
    }
    if(flag==-1)F(i,0,n-1)x[i].x/=n;
}
LL a[maxn];
long long num[4*maxn];
long long sum[4*maxn];
Complex x1[4*maxn];
ll n;
const ll M=50000;
int main()
{

    scanf("%lld",&n);
    memset(num,0,sizeof(num));

    LL zero=0;
    F(i,0,n-1){
        scanf("%lld",&a[i]);
        if(a[i]==0)zero++;
        num[a[i]+M]++;
    }

    sort(a,a+n);
    ll len1=(a[n-1]+M)+1;
    ll len=1;
    while(len<2*len1){len<<=1;}

    for(ll i=0;i<len1;i++)
        x1[i]=Complex(num[i],0);
    for(ll i=len1;i<len;i++)
        x1[i]=Complex(0,0);

    fft(a,len,1);

    for(LL i = 0;i < len;i++)
        a[i] = a[i]*a[i];

    fft(a,len,-1);

    for(ll i=0;i<len;i++)
        num[i]=(long long)(a[i].x+0.5);
    for(ll i=0;i<n;i++){num[a[i]+a[i]+2*M]--;}

    long long res=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            res=res+num[a[i]+2*M];
            res=res-zero*2;
        }
        else
        {
            res=res+num[a[i]+2*M];
            res=res-(zero-1)*2;
        }
    }


    printf("%lld\n",res);
    return 0;
}

