//
// Created by 赵婉如 on 2019-08-25.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
#define lson  (i<<1)
#define rson  ((i<<1)|1)
typedef long long ll;
using namespace std;
const int  maxn = 300;
const double PI = 3.1415926;
const double eps = 1e-16;
int n;
int sgn(double x)
{
    if(fabs(x) < eps) return 0;
    if(x < 0)
        return -1;
    else
        return 1;
}

struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};

struct Line
{
    Point s,t;
    double k;
    Line() {}
    Line(Point _s,Point _t)
    {
        s = _s;
        t = _t;
        k = atan2(t.y-s.y,t.x-s.x);
    }
    Point operator &(const Line &b) const
    {
        Point res = s;
        double ta = ((s-b.s)^(b.s-b.t))/((s-t)^(b.s-b.t));
        res.x += (t.x-s.x)*ta;
        res.y += (t.y-s.y)*ta;
        return res;
    }
};


//求p1,p2的直线与a,b,c这条直线的交点
Point Intersection(Point p1,Point p2,double a,double b,double c)
{
    double u = fabs(a*p1.x + b*p1.y + c);
    double v = fabs(a*p2.x + b*p2.y + c);
    Point t;
    t.x = (p1.x*v + p2.x*u)/(u+v);
    t.y = (p1.y*v + p2.y*u)/(u+v);
    return t;
}

double CalArea(Point p[],int n)
{
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (p[i]^p[(i+1)%n])/2;
    }
    return fabs(ans);
}

double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}

Point p[maxn];
Point tp[maxn];
void cut(double a,double b,double c,Point p[],int &cnt)
{
    int tmp = 0;
    for(int i = 1; i <= cnt; i++)
    {
        if(a*p[i].x+b*p[i].y+c < eps) tp[++tmp] = p[i];
        else
        {
            //在p[i]处大于0,那么交点可能在(p[i-1],p[i])or(p[i+1],p[i])
            if(a*p[i-1].x + b*p[i-1].y + c < -eps)
                tp[++tmp] = Intersection(p[i-1],p[i],a,b,c);
            if(a*p[i+1].x + b*p[i+1].y + c < -eps)
                tp[++tmp] = Intersection(p[i],p[i+1],a,b,c);
        }
    }
    cout<<"!!!cnt="<<cnt<<' '<<tmp<<endl;
    for(int i = 1; i <= tmp; i++)
        p[i] = tp[i];
    p[0] = p[tmp];
    p[tmp+1] = p[1];
    cnt = tmp;
}
double inf = 1000000000000000.0;
double U[maxn],V[maxn],W[maxn];
int m;
double C[maxn],D[maxn],A[maxn],B[maxn];

bool cal(int now)
{
    p[1] = Point(0-2*eps,0-2*eps);
    p[2] = Point(0-2*eps,1+2*eps);
    p[3] = Point(1+2*eps,1+2*eps);
    p[4] = Point(1+2*eps,0-2*eps);
    p[0] = p[4];
    p[5] = p[1];
    int cnt = 4;/*
    for(int i = 0; i < n; i++)
    {
        if(i == now) continue;
        double a = //(U[i]-U[now])/(U[i]*U[now]);    //1/U[now] - 1/U[i]
        double b = (V[i]-V[now])/(V[i]*V[now]);
        double c = (W[i]-W[now])/(W[i]*W[now]);

    }*/
    double a,b,c;
    a=C[1];b=C[2];c=-A[now];
    cout<<a<<' '<<b<<' '<<c<<endl;
    if(sgn(a)==0 && sgn(b) == 0 ){
        if(sgn(c) >= 0)
            return false;
    }
    cut(a,b,c,p,cnt);

    a=-D[1];b=-D[2];c=(D[1]+D[2]-B[now]);
    cout<<a<<' '<<b<<' '<<c<<endl;
    if(sgn(a)==0 && sgn(b) == 0 ){
        if(sgn(c) >= 0)
            return false;
    }
    cut(a,b,c,p,cnt);

    //cout<<"cnt="<<cnt<<endl;
    if(sgn(CalArea(p,cnt)) == 0)
        return false;
    else
        return true;
}
void solve()
{
    m=read();n=read();
    F(i,1,n) C[i]=read(),D[i]=read();
    F(i,1,m){
        A[i]=read();B[i]=read();
    }
    F(i,1,m){
        if(cal(i)) cout<<"Y";
        else cout<<"N";
    }
    cout<<endl;/*
    for(int i = 0; i < n; i++)
    {
        scanf("%lf%lf%lf",&U[i],&V[i],&W[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(cal(i))
            printf("Yes\n");
        else
            printf("No\n");
    }*/
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}
/*
2
4 2
3 8
6 10
0 18
3 13
10 0
7 3
1 2
4 4
4 4
0 0

 */