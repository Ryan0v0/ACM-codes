//
// Created by 赵婉如 on 2019-07-27.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10,inf=0x3f3f3f3f;
int a[N],b[N],n,sta[N],L[N],R[N],tp;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
struct D {ll sum,lsum,rsum,lsum1,rsum1;} s[N<<2];
D mg(D a,D b) {
    D t= {0,0};
    t.sum=a.sum+b.sum;
    t.lsum=min(a.lsum,a.sum+b.lsum);
    t.rsum=min(b.rsum,b.sum+a.rsum);
    return t;
}
D mg1(D a,D b) {
    D t= {0,0};
    t.sum=a.sum+b.sum;
    t.lsum1=max(a.lsum1,a.sum+b.lsum1);
    t.rsum1=max(b.rsum1,b.sum+a.rsum1);
    return t;
}
void build(int u=1,int l=1,int r=n) {
    if(l==r) {s[u].sum=b[l],s[u].lsum=min(0ll,(ll)b[l]),s[u].rsum=min(0ll,(ll)b[l]);
        s[u].lsum1=max(0ll,(ll)b[l]),s[u].rsum1=max(0ll,(ll)b[l]);
        return;}
    build(ls,l,mid),build(rs,mid+1,r),s[u]=mg(s[ls],s[rs]);
}
void qry(int L,int R,D& x,int u=1,int l=1,int r=n) {
    if(l>=L&&r<=R) {x=mg(x,s[u]); return;}
    if(l>R||r<L)return;
    qry(L,R,x,ls,l,mid),qry(L,R,x,rs,mid+1,r);
}
void qry1(int L,int R,D& x,int u=1,int l=1,int r=n) {
    if(l>=L&&r<=R) {x=mg1(x,s[u]); return;}
    if(l>R||r<L)return;
    qry1(L,R,x,ls,l,mid),qry1(L,R,x,rs,mid+1,r);
}
int main() {
    scanf("%d",&n);
    a[0]=a[n+1]=~inf;b[0]=b[n+1]=~inf;
    for(int i=1; i<=n; ++i)scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i)scanf("%d",&b[i]);
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
    build();
    ll ans=0;
    for(int i=1; i<=n; ++i) {
        /*if(a[i]>0) {
            D t= {0,0};
            qry(L[i],R[i],t);
            ans=max(ans,a[i]*t.sum);
        } else if(a[i]<0) {*/
            ll x=0,x1=0;
            D t= {0,0};
            qry(L[i],i,t);
            x+=t.rsum;
            t= {0,0};
            qry(i,R[i],t);
            x+=t.lsum;
            x-=b[i];
            D t1= {0,0};
            qry1(L[i],i,t1);
            cout<<"x1="<<x1<<endl;
            x1+=t1.rsum1;cout<<t1.rsum1<<" x1="<<x1<<endl;
            t1= {0,0};
            qry1(i,R[i],t1);
            x1+=t1.lsum1;cout<<t1.lsum1<<" x1="<<x1<<endl;
            x1-=b[i];cout<<b[i]<<" x1="<<x1<<endl;/*
            if(a[i]*x>ans){
                ans=a[i]*x;
                cout<<ans<<' '<<a[i]<<' '<<x<<endl;
            }*/
            cout<<i<<' '<<L[i]<<' '<<R[i]<<' '<<a[i]<<' '<<ans<<' '<<x<<' '<<"x1="<<x1<<' '<<t.lsum<<' '<<t.rsum<<' '<<t1.lsum1<<' '<<t1.rsum1<<endl;
            ans=max(ans,max(a[i]*x,a[i]*x1));
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