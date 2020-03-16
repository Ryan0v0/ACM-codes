//
// Created by 赵婉如 on 2019-08-22.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const int N = 5e4+5;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct Point
{
    double x,y;
    Point(double _x=0,double _y=0):x(_x),y(_y){}
    friend Point operator -(const Point &a,const Point &b)
    {return Point(a.x-b.x,a.y-b.y);}
    friend double operator ^(const Point &a,const Point &b)
    {return a.x*b.y-a.y*b.x;}
    bool operator <(const Point &s)const
    {
        return y<s.y||(dcmp(y-s.y)==0&&x<s.x);
    }
}p[N],stack[N];
int n;
double Get_angle(const Point &a)
{
    return atan2(a.y,a.x);
}/*
double Get_dis(const Point &a,const Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}*/
double Get_dis(const Point &a,const Point &b)
{
   min(a.x-b.x,a.y-b.y)
}
bool cmp(const Point &a,const Point &b)
{
    double aa = Get_angle(a-p[0]),ba = Get_angle(b-p[0]);
    return dcmp(aa-ba)==-1||(dcmp(aa-ba)==0&&Get_dis(p[0],a)<Get_dis(p[0],b));
}
int Get_Convex()
{
    int mni = 0;
    for(int i = 0;i<n;i++)
        if(p[i]<p[mni])mni = i;
    swap(p[0],p[mni]);
    sort(p+1,p+n,cmp);
    int top = 2;
    stack[0] = p[0],stack[1] = p[1],stack[2] = p[2];
    for(int i = 3;i<n;i++)
    {
        while(top>=1&&dcmp((stack[top]-p[i])^(stack[top-1]-p[i]))>=0)
            top--;
        stack[++top] = p[i];
    }
    return top;
}
double Rolling_Lines(int top)
{
    int p = 1,q = 2;
    stack[++top] = stack[0];
    double ans = 0;
    for(int i = 0;i<top;i++)
    {
        while(((stack[p]-stack[i])^(stack[q+1]-stack[i]))>((stack[p]-stack[i])^(stack[q]-stack[i])))
            q = (q+1)%top;
        ans = max(ans,(stack[p]-stack[i])^(stack[q]-stack[i]));
        while(((stack[p+1]-stack[i])^(stack[q]-stack[i]))>((stack[p]-stack[i])^(stack[q]-stack[i])))
            p = (p+1)%top;
        ans = max(ans,(stack[p]-stack[i])^(stack[q]-stack[i]));
    }
    return ans/2.0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)break;
        for(int i = 0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        int cnt = Get_Convex();
        printf("%.2f\n",Rolling_Lines(cnt));
    }
    return 0;
}