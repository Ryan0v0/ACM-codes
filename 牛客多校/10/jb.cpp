//
// Created by 赵婉如 on 2019-08-17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int N = 5e3+5;
const int K = 2e3+5;
typedef __int128 ll;
struct Node
{
    double x,y;
    Node(){}
    Node(ll _x,ll _y):x(_x),y(_y){}
};
Node stack[N];
int top,bot;
double Fabs(double x)
{
    if(x>0)return x;
    else return -x;
}
double slope(Node a,Node b)
{
    if(Fabs(a.y-b.y)<1e-10)return 1e18;
    else return (a.x-b.x)/(a.y-b.y);
}
ll f[2][N];
struct MB
{ll w,h;}mb[N];
bool cmp1(const MB &a,const MB &b)
{
    if(a.h==b.h)return a.w<b.w;
    return a.h<b.h;
}
ll sumw[N];
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
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
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll sum = 0;
    for(int i = 1;i<= n;i++)
    {
        mb[i].w=read();
        mb[i].h=read();
        //scanf("%lld%lld",&mb[i].w,&mb[i].h);
        sum+=mb[i].w*mb[i].h;
    }
    sort(mb+1,mb+n+1,cmp1);
    for(int i = n;i>= 1;i--)
    {
        sumw[i] = sumw[i+1]+mb[i].w;
        if(i!=1)mb[i].h-=mb[1].h;
    }
    int now = 1,pre = 0;
    ll ans = mb[1].h*sumw[1];
    for(int i = 2;i<= k;i++)
    {
        stack[bot = top = 1] = Node(0ll,0ll);
        if(i!=2)stack[++top] = Node(f[pre][i-1],mb[i-1].h);
        for(int j = i;j<= n;j++)
        {
            while(bot<top&&/*slope(stack[bot+1],stack[bot])>(double)sumw[j]*/stack[bot+1].x-stack[bot].x>=sumw[j]*(stack[bot+1].y-stack[bot].y))
                bot++;
            f[now][j] = stack[bot].x+(mb[j].h-stack[bot].y)*sumw[j];
            if(i==k)ans = max(ans,mb[1].h*sumw[1]+f[now][j]);
            while(bot<top&&(f[pre][j]-stack[top].x)*(stack[top].y-stack[top-1].y)>=(stack[top].x-stack[top-1].x)*(mb[j].h-stack[top].y)/*slope(Node(f[pre][j],mb[j].h),stack[top])-slope(stack[top],stack[top-1])>-1e-10*/)
                top--;
            stack[++top] = Node(f[pre][j],mb[j].h);
        }
        swap(pre,now);
    }
    //cout>>sum-ans;
    print(sum-ans);
    //printf("%lld\n",sum-ans);
    return 0;
}