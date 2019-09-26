#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long ll;
const int N=100010;
double t[N];
double vx[N];
double vy[N];
int main()
{
    freopen("joy.in","r",stdin);
    freopen("joy.out","w",stdout);
    double sx,sy,fx,fy;
    double n,k,v;
    cin>>sx>>sy>>fx>>fy>>n>>k>>v;
    F(i,1,n) cin>>t[i]>>vx[i]>>vy[i];
    t[(int)n+1]=k;
    vx[(int)n+1]=vy[(int)n+1]=0;
    double lx=0,ly=0;
    F(i,1,n){
        lx+=(vx[i] )*(t[i+1]-t[i]);
        ly+=(vy[i] )*(t[i+1]-t[i]);
    }
    double dx=-lx+fx-sx,dy=-ly+fy-sy;
    double px=(dx)/k,py=(dy)/k;

    if(dx*dx+dy*dy>v*v*k*k){
        puts("No");
        return 0;
    }
    puts("Yes");
    int cur=0;
    double nowfx=0,nowfy=0;
    F(i,0,k-1){
        if(i==t[cur+1]) nowfx=vx[++cur],nowfy=vy[cur];
        sx+=px+nowfx;
        sy+=py+nowfy;
        printf("%.6lf %.6lf\n",sx,sy);
    }
    return 0;
}
