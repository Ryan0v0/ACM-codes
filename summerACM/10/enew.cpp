#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cassert>
#define INF 1e9
#define N 10005
#define pi acos(-1.0)
#define eps 1e-7
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}p[N];
int n;
double R[N],D[N];
double dcmp(double x){if(x<-eps)return -1;return x>eps;}
double sqr(double x){return x*x;}
double dis(Point p1,Point p2){return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));}
double work()
{
    if(dcmp(R[1])<0)return INF;
    double S=sqr(R[1]);
    for(int i=2;i<=n;i++)
    {
        R[i]=D[i-1]-R[i-1];
        if(dcmp(R[i])<0)return INF;
        S+=sqr(R[i]);
    }
    return S;
}
int main()
{
    int T=read();
    while(T--)
    {
        n=read();
        for(int i=1;i<=n;i++)
        {
            p[i].x=read(),p[i].y=read();
            if(i-1)D[i-1]=dis(p[i-1],p[i]);
        }
        D[n]=dis(p[n],p[1]);
        if(n&1)
        {
            double sum=0;
            for(int i=1;i<=n;i++)
            {
                if(i&1)sum+=D[i];
                else sum-=D[i];
            }
            R[1]=sum/2;double ans=work();
            if(!dcmp(ans-INF)){puts("IMPOSSIBLE");continue;}
            else
            {
                printf("%.2lf\n",pi*ans);
                for(int i=1;i<=n;i++)
                {
                    if(R[i]<0)R[i]=-R[i];
                    printf("%.2lf\n",R[i]);
                }
                continue;
            }
        }
        double l=0,r=min(D[1],D[n]),resl,resr,sum=0;
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(i&1)sum+=D[i];else sum-=D[i];
            if(i&1)r=min(r,sum);else l=max(l,sum);
            if(i==n&&dcmp(sum)){puts("IMPOSSIBLE");f=1;break;}
        }
        if(f)continue;
        sum=0;
        for(int i=n;i>0;i--)
        {
            if(i&1)sum-=D[i];else sum+=D[i];
            if(i&1)l=max(l,sum);else r=min(r,sum);
        }
        if(dcmp(r-l)<0){puts("IMPOSSIBLE");continue;}
        R[1]=l,resl=work(),R[1]=r,resr=work();
        if(dcmp(resl-INF)==0&&dcmp(resr-INF)==0){puts("IMPOSSIBLE");continue;}
        while(r-l>eps)
        {
            double mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
            R[1]=mid1;double res1=work();assert(dcmp(res1-INF));
            R[1]=mid2;double res2=work();assert(dcmp(res2-INF));
            if(dcmp(res1-res2)<0)r=mid2,resr=res2;
            else l=mid1,resl=res1;
        }
        printf("%.2lf\n",pi*(dcmp(resl-INF)?resl:resr));
        for(int i=1;i<=n;i++)
        {
            if(R[i]<0)R[i]=-R[i];
            printf("%.2lf\n",R[i]);
        }
    }
    return 0;
}
/*
100
3
-4 0
-5 1
-2 -2

*/