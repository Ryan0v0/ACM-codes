//
// Created by 赵婉如 on 2019-08-24.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    srand(time(NULL));
    int tt=rand()%10+1;cout<<tt<<endl;
    F(i,1,tt){
        int n=rand()%5+1;int m=rand()%20+1;cout<<n<<' '<<m<<endl;
        F(i,1,m){
            int x=rand()%n+1;
            int y=rand()%n+1;
            cout<<x<<' '<<y<<' '<<1<<endl;
        }
    }
    return 0;
}
