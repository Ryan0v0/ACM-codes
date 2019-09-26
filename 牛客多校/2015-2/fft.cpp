//
// Created by 赵婉如 on 2019-08-05.
//

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define maxn 800005
typedef long long ll;
const int LOW=50000;
const double pi=acos(-1.0);
struct complex
{
    double x,y;
    complex(double X=0,double Y=0)
    {
        x=X,y=Y;
    }
}a[maxn],b[maxn];
complex operator + (complex a,complex b) {return complex(a.x+b.x,a.y+b.y);}
complex operator - (complex a,complex b) {return complex(a.x-b.x,a.y-b.y);}
complex operator * (complex a,complex b) {return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
int S,T,n,m,L,R[maxn],zero;
long long F[maxn],num[maxn],cnt[maxn];
void FFT(complex a[maxn],int opt)
{
    for (int i=0;i<n;++i)
        if (i<R[i]) swap(a[i],a[R[i]]);
    for (int k=1;k<n;k<<=1)
    {
        complex wn=complex(cos(pi/k),opt*sin(pi/k));
        for (int i=0;i<n;i+=(k<<1))
        {
            complex w=complex(1,0);
            for (int j=0;j<k;++j,w=w*wn)
            {
                complex x=a[i+j],y=w*a[i+j+k];
                a[i+j]=x+y,a[i+j+k]=x-y;
            }
        }
    }
}
void calc(int opt)
{
    FFT(a,1);FFT(b,1);
    for (int i=0;i<=n;++i) a[i]=a[i]*b[i];
    FFT(a,-1);
    for (int i=0;i<n;++i)//对于统计两数组加法的都要完全统计0-n
    {
        F[i]+=(long long)(a[i].x/n+0.5)*opt;
    }
}
int main()
{
    scanf("%d",&S);
    T=S;
    for(int i=0;i<S;i++)
    {
        scanf("%lld",&num[i]);
        if(num[i]==0) zero++;
        cnt[num[i]+LOW]++;//离散化
    }
    for (n=1;n<=200000;n<<=1) ++L;
    for (int i=0;i<n;++i)
        R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
    for (int i=0;i<=n;++i) a[i]=complex(1.0*cnt[i],0.0),b[i]=complex(1.0*cnt[i],0.0);
    calc(1);//传递的参数为多项式乘法的常数可以为正负

    for(int i=0;i<T;i++)//去除本身与本身相加的结果
    {
        F[(num[i]+LOW)*2]--;
    }
    ll pp = 0;
    for(int i=0;i<T;i++)
    {
        pp+=F[num[i]+LOW*2];
        if(num[i]==0)
            pp-=(zero-1)*2;//元素为0的情况
        else
            pp-=zero*2;//元素非0的情况
    }
    printf("%lld\n",pp);
    return 0;
}
