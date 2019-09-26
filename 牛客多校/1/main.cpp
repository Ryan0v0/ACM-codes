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
int x1,x2,x3,x4;
int y1,y2,y3,y4;
int w,h;
int main()
{
    //freopen("grave.in","r",stdin);
    //freopen("grave.out","w",stdout);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
    int w1=x2-x1;int h1=max(y3-y1,y2-y4);
    int w2=max(x3-x1,x2-x4);int h2=y2-y1;
    scanf("%d%d",&w,&h);
    if((w<=w1&&h<=h1)||(w<=w2&&h<=h2)){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

double sx,sy,fx,fy;
int n,k,t[20005];
double v,wx[20005],wy[20005];
double vx,vy;
int tot = 0;
double winx=0,winy=0;
int check(int mid)
{
    tot = 0,winx = winy = 0;
    double ex = fx,ey = fy;
    for(int i=0;i<mid;i++)
    {
        if(tot<n&&t[tot]==i)
            winx=wx[tot],winy=wy[tot],tot++;
        ex-=winx,ey-=winy;
    }
    double dis = sqrt((ex-sx)*(ex-sx)+(ey-sy)*(ey-sy));
    if(dis/v>mid)return 0;
    return 1;
}
int main()
{
    freopen("joy.in","r",stdin);
    freopen("joy.out","w",stdout);
    cin>>sx>>sy>>fx>>fy;
    cin>>n>>k>>v;
    for(int i=0;i<n;i++)
        cin>>t[i]>>wx[i]>>wy[i];
    int L = 0;
    for(;L<=k+5;L++)
        if(check(L))
            break;
    if(L>k)return puts("No");
    double ex = fx,ey = fy;
    tot = winx = winy = 0;
    for(int i=0;i<L;i++)
    {
        if(tot<n&&t[tot]==i)
            winx=wx[tot],winy=wy[tot],tot++;
        fx-=winx,fy-=winy;
    }
    double l = fx - sx;
    double h = fy - sy;
    double dis = sqrt(l*l+h*h);
    double vx = v * l / dis;
    double vy = v * h / dis;
    tot = winx = winy = 0;
    puts("Yes");
    if(L==0)L++;
    for(int i=0;i<L-1;i++)
    {
        if(tot<n&&t[tot]==i)
            winx=wx[tot],winy=wy[tot],tot++;
        sx += vx + winx;
        sy += vy + winy;
        printf("%.6f %.6f\n",sx,sy);
    }
    for(int i=L;i<=k;i++)
        printf("%.6f %.6f\n",ex,ey);
}
