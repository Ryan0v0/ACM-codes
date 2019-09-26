//
// Created by 赵婉如 on 2019-07-27.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
const ll INF=1e18;
const int inf = 0x3f3f3f3f;
int a[N],b[N],n,sta[N],L[N],R[N],tp;
#define ls (u<<1)
#define rs (u<<1|1)
ll sum[N];
ll mx[N<<2],mn[N<<2];
void push_up(int p)
{
    mx[p] = max(mx[p<<1],mx[p<<1|1]);
    mn[p] = min(mn[p<<1],mn[p<<1|1]);
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        mx[p] = mn[p] = sum[l];
        return ;
    }
    int mid;
    mid = (l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(p);
}
ll get_mx(int p,int l,int r,int a,int b)
{
    if(a>b)return 0;
    if(l>=a&&r<=b)return mx[p];
    ll ans = -INF;
    int mid = (l+r)>>1;
    if(a<=mid)ans = max(ans,get_mx(p<<1,l,mid,a,b));
    if(b >mid)ans = max(ans,get_mx(p<<1|1,mid+1,r,a,b));
    return ans;
}
ll get_mn(int p,int l,int r,int a,int b)
{
    if(a>b)return 0;
    if(l>=a&&r<=b)return mn[p];
    ll ans = INF;
    int mid = (l+r)>>1;
    if(a<=mid)ans = min(ans,get_mn(p<<1,l,mid,a,b));
    if(b >mid)ans = min(ans,get_mn(p<<1|1,mid+1,r,a,b));
    return ans;
}
int main() {
    scanf("%d",&n);
    a[0]=a[n+1]=~inf;b[0]=b[n+1]=~inf;
    for(int i=1; i<=n; ++i)scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i)scanf("%d",&b[i]),sum[i] = sum[i-1]+b[i];
    build(1,0,n);
    sta[tp=0]=0;
    for(int i=1; i<=n; ++i) {
        for(; a[sta[tp]]>=a[i]; --tp);
        L[i]=sta[tp]+1,sta[++tp]=i;
    }
    sta[tp=0]=n+1;
    for(int i=n; i>=1; --i) {
        for(; a[sta[tp]]>=a[i]; --tp);
        R[i]=sta[tp]-1,sta[++tp]=i;
    }
    //build();
    ll ans=-INF;
    for(int i=1; i<=n; ++i) {
        /*if(a[i]>0) {
            D t= {0,0};
            qry(L[i],R[i],t);
            ans=max(ans,a[i]*t.sum);
        } else if(a[i]<0) {*/
        ll x=0;
        //D t= {0,0};
        ll tsmx = get_mx(1,0,n,L[i]-1,i-1);
        //x+=sum[i-1]-tsmx;
        //t= {0,0};
        ll tsmn = get_mn(1,0,n,i,R[i]);
        //qry(i,R[i],t);
        x+=tsmn-tsmx;
        //x-=b[i];
        //D t1= {0,0};
        //qry1(L[i],i,t1);
        //x1+=t1.rsum1;
        //t1= {0,0};
        //qry1(i,R[i],t1);
        //x1+=t1.lsum1;
        //x1-=b[i];
        /* if(a[i]*x>ans){
             ans=a[i]*x;
             cout<<ans<<' '<<a[i]<<' '<<x<<endl;
         }*/
        //cout<<i<<' '<<L[i]<<' '<<R[i]<<' '<<a[i]<<' '<<ans<<' '<<x<<' '<<x1<<' '<<t.lsum<<' '<<t.rsum<<' '<<t1.lsum1<<' '<<t1.rsum1<<endl;
        ans=max(ans,x*a[i]);
//        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
9
-1 -3 7 -7 6 6 -5 1 9
-8 -2 3 9 1 -8 4 -4 2
 */
