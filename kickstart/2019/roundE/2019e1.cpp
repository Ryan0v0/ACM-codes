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
const int N=100010;
int n,m;
LL ans;
int p[N];
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
#define pa pair<int,int>
pa e[N];
void solve()
{
    n=read();m=read();
    mec(e,0);
    ans=0LL;
    F(i,1,n) p[i]=i;
    F(i,1,m){
        int x=read();int y=read();
        e[i].first=x;
        e[i].second=y;
        int fx=find(x);int fy=find(y);
        if(fx!=fy) {
            p[fy]=fx;
            ans++;
        }
    }
    if(ans<n-1){
        ans+=((n-1)-ans)*2;
    }
    cout<<ans<<endl;
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
4
2 1
1 2
3 1
2 3
6 6
1 2
1 3
2 3
2 4
3 4
4 6
6 3
1 2
3 4
4 6

 */