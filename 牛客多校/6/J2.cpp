//
// Created by 赵婉如 on 2019-08-03.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define inf 1000000000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1010;
int n,m;
LL c[N][N];
LL d[N],sumd[N];
LL sum[N][N];
LL rs[N][N],rss[N];
LL ans;
int main()
{
    int tt=read();
    F(Case,1,tt){
        n=read();m=read();ans=0LL;
        F(i,1,n) rs[i][m+1]=-inf;
        mec(rss,0);mec(sumd,0);
        F(i,1,n) {
            F(j,1,m){
                c[i][j]=read();
                c[i][j]=-c[i][j];
                sum[i][j]=sum[i][j-1]+c[i][j];
            }
        }
        F(i,1,n) D(j,m,1){
            rs[i][j]=max(rs[i][j+1],sum[i][j]);
        }
        F(j,1,m){
            F(i,1,n) rss[j]+=rs[i][j];
        }
/*
        F(i,1,n) {F(j,1,m)cout<<c[i][j]<<' ';cout<<endl;}
        F(i,1,n) {F(j,1,m)cout<<sum[i][j]<<' ';cout<<endl;}
        F(i,1,n) {F(j,1,m)cout<<rs[i][j]<<' ';cout<<endl;}
        F(j,1,m) cout<<rss[j]<<' ';cout<<endl;
*/
        F(j,1,m){
            d[j]=read();
            sumd[j]=sumd[j-1]+d[j];
        }
        F(j,0,m) F(i,1,n){
            /*if(rss[j]+sumd[j]-(rs[i][j]-sum[i][j])>ans){
                ans=rss[j]+sumd[j]-(rs[i][j]-sum[i][j]);
                //cout<<j<<' '<<i<<' '<<ans<<endl;
            }*/
            ans=max(ans,rss[j]+sumd[j]-(rs[i][j]-sum[i][j]));
        }
        cout<<"Case #"<<Case<<": "<<ans<<endl;
    }
    return 0;
}
/*
10
2 2
1 2
2 -1
4 1
3 3
1 2 3
1 2 3
1 2 3
6 7 8

3 3
1 -2 3
0 1 -5
-2 3 1
3 3 3

5 4
1 3 -1 0
-3 -2 1 1
1 1 1 1
-1 -1 -1 -1
1 2 -2 -1
6 -1 2 -2

3 3
1 2 3
0 1 5
2 3 1
-3 -3 -3

3 3
0 0 0
0 0 0
0 0 0
-3 3 3

3 3
-1 0 0
-2 0 0
-3 0 0
-3 2 2

 */