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
const int N=250;
int n,m;
int q;
int a[N][N];

struct BIT{
    int sum[N][N];
    void add(int posx,int posy,int k){
        for(int i=posx;i<=n;i+=(i&-i)){
            for(int j=posy;j<=m;j+=(j&-j)){
                sum[i][j]+=k;
            }
        }
    }

    int query(int posx,int posy){
        int re=0;
        for(int i=posx;i>=1;i-=(i&-i)){
            for(int j=posy;j>=1;j-=(j&-j)){
                re+=sum[i][j];
            }
        }
        return re;
    }
}t[N];
int main()
{

    return 0;
}