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
int main()
{
    int tt=read();
    while(tt--){
        n=read();tot=0;mec(head,0);
        F(i,1,n-1){
            //cout<<"!!!"<<i<<' '<<n<<endl;
            int x=read();int y=read();
            add(x,y);
        }
        //F(i,1,tot) cout<<"~~"<<i<<' '<<e[i].go<<endl;
        F(i,1,n) a[i].l=read(),a[i].r=read();
        mec(dp,0);
        dp[0][0]=dp[0][1]=0;
        dfs(1,-1);
        cout<<max(dp[1][0],dp[1][1])<<endl;
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