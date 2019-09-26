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
LL d[N];
LL a[N],sum[N],mn[N];
LL sumd[N];
LL ans;
int main()
{
    int tt=read();
    //while(tt--){
    F(Case,1,tt){
        n=read();m=read();ans=0LL;
        mec(a,0);mec(sum,0);mec(sumd,0);//mec(mn,0);
        F(j,1,m) mn[j]=inf;
        F(i,1,n) F(j,1,m){
            c[i][j]=read();
            if(c[i][j]<=0){
                a[j]=a[j]-c[i][j];
                mn[j]=min(mn[j],-c[i][j]);
            }
            sum[j]+=c[i][j];
        }
        F(j,1,m){
            d[j]=read();
            sumd[j]=sumd[j-1]+d[j];
            //ans=max(ans,sum[j]+sumd);
        }
        F(j,1,m){
            if(sum[j]+a[j]==0&&d[j]<0){
                a[j]-=mn[j];
                //cout<<j<<' '<<mn[j]<<' '<<a[j]<<endl;
            }
        }
        //a[m+1]=0;
        F(j,1,m) sum[j]+=sum[j-1];
        F(j,0,m){
            ans=max(ans,sumd[j]-sum[j]+a[j+1]);
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