//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 10000000000000000////
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
const int N=4e5+10;
int tot=0,head[N];
struct edge{int go,next;}e[N];
struct node{LL l,r;}a[N];
void add(int x,int y)
{
    e[++tot]=(edge){y,head[x]};head[x]=tot;
    e[++tot]=(edge){x,head[y]};head[y]=tot;
}
int n;
LL dp[N][5];
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next) {
        int y = e[i].go;
        if (y == fa) continue;
        //cout<<x<<' '<<y<<endl;
        dfs(y,x);
        dp[x][0] += max(dp[y][0]+abs(a[x].l - a[y].l), dp[y][1]+abs(a[x].l - a[y].r));
        dp[x][1] += max(dp[y][0]+abs(a[x].r - a[y].l), dp[y][1]+abs(a[x].r - a[y].r));
    }
}
#define a first
#define b second
#define pa pair<int,int>
pa A(pa x)
{
    pa res;
    res.a=x.a;
    res.b=2*x.b-x.a;
    return res;
}
pa B(pa x)
{
    pa res;
    res.a=2*x.a-x.b;
    res.b=x.b;
    return res;
}
void Print(pa x)
{
    cout<<"("<<x.a<<","<<x.b<<")"<<endl;
}
int main()
{
    int x=1,y=2;
/*    Print(A(make_pair(100,200)));
    Print(B(A(make_pair(100,200))));
    Print(A(B(A(make_pair(100,200)))));
    Print(B(A(B(A(make_pair(100,200))))));*/
    pa cur=make_pair(1,2);
    F(i,1,100){
        if(i&1){
            cur=A(cur);

        }
        else cur=B(cur);
        Print(cur);
    }
    return 0;
}
/*
3
5
1 2
2 3
3 4
4 5
1 5
2 7
7 9
5 8
3 4
3
1 2
1 3
3 4
2 3
4 5
6
1 2
1 2
2 4
2 5
1 6
1 5
2 7
7 9
5 8
3 4
1000000000 1000000000

 */