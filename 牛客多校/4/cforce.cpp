//
// Created by 赵婉如 on 2019-07-27.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 10000000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int maxx = 5e6+5;
long long a[maxx],b[maxx];
int l[maxx], r[maxx];
long long sum[maxx];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("me.txt","w",stdout);
    int n;
    scanf("%d", &n);
    F(i,1,n) a[i]=read();
    //F(i,1,n) b[i]=read(),sum[i]=sum[i-1]+b[i];
    F(i,1,n) b[i]=read(),sum[i]=sum[i-1]+b[i];
    F(i,1,n) l[i]=r[i]=i;
    a[0] = a[n+1] = -1e18;
    for(int i = 1; i <= n; ++i){
        if(a[i] > 0) {
            while (a[i] <= a[l[i] - 1]) l[i] = l[l[i] - 1];
        }
        else if(a[i] < 0) {
            long long mx = b[i];
            int resl = l[i];
            while(a[i] <= a[l[i]-1]){
                l[i] = l[l[i]-1];
                if(sum[i]-sum[l[i]-1] < mx){
                    mx = sum[i]-sum[l[i]-1];
                    resl = l[i];
                }
            }
            l[i] = resl;
        }
    }
    for(int i = n; i >= 1; --i) {
        if(a[i] > 0) {
            while (a[i] <= a[r[i] + 1]) r[i] = r[r[i] + 1];
        }
        else if(a[i] < 0) {
            long long mx = b[i];
            int resr = i;
            while(a[i] <= a[r[i]+1]) {
                r[i] = r[r[i]+1];
                if(sum[r[i]]-sum[i-1] < mx) {
                    mx = sum[r[i]]-sum[i-1];
                    resr = r[i];
                }
            }
            r[i] = resr;
        }
    }
    long long pp = -INF;///
    //F(i,1,n) pp = max(pp, a[i]*(sum[r[i]]-sum[l[i]-1]));
    F(i,1,n){
        if(a[i]*(sum[r[i]]-sum[l[i]-1])>pp){
            cout<<i<<' '<<a[i]<<' '<<l[i]<<' '<<r[i]<<' '<<sum[r[i]]<<' '<<sum[l[i]-1]<<' '<<sum[r[i]]-sum[l[i]-1]<<endl;
            pp=a[i]*(sum[r[i]]-sum[l[i]-1]);
        }
    }
    cout<<pp<<endl;
    return 0;
}
/*
5
1 2 3 4 5
-5 -4 -3 -2 -1

5
1 2 3 4 5
1 2 3 4 5

3
-1 3 8
0 2 -6

4
5 0 -1 3
-5 -10 -9 6

2
1 -3
2 -7

3
1000000 -1000000 1000000
1000000 2000000 3000000
 */
