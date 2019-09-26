//
// Created by 赵婉如 on 2019-07-27.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10,inf=1000000000000;
int a[N],b[N],n,sta[N],L[N],R[N],tp;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
struct D {ll sum,lsum,rsum;} s[N<<2];
D mg(D a,D b) {
    D t= {0,0};
    t.sum=a.sum+b.sum;
    t.lsum=min(a.lsum,a.sum+b.lsum);
    t.rsum=min(b.rsum,b.sum+a.rsum);
    return t;
}
void build(int u=1,int l=1,int r=n) {
    if(l==r) {s[u].sum=b[l],s[u].lsum=min((ll)b[l],0ll),s[u].rsum=min((ll)b[l],0ll); return;}
    build(ls,l,mid),build(rs,mid+1,r),s[u]=mg(s[ls],s[rs]);
}
void qry(int L,int R,D& x,int u=1,int l=1,int r=n) {
    if(l>=L&&r<=R) {x=mg(x,s[u]); return;}
    if(l>R||r<L)return;
    qry(L,R,x,ls,l,mid),qry(L,R,x,rs,mid+1,r);
}
int main() {
    scanf("%d",&n);
    a[0]=a[n+1]=~inf;b[0]=b[n+1]=~inf;
    for(int i=1; i<=n; ++i)scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i)scanf("%d",&b[i]);

    sta[tp=0]=0;
    for(int i=1; i<=n; ++i) {
        cout<<i<<endl;
        for(; a[sta[tp]]>=a[i]; --tp);
        L[i]=sta[tp]+1,sta[++tp]=i;
    }
    cout<<"fini"<<endl;
    sta[tp=0]=n+1;
    for(int i=n; i>=1; --i) {
        for(; a[sta[tp]]>=a[i]; --tp);
        R[i]=sta[tp]-1,sta[++tp]=i;
    }
    cout<<"fini"<<endl;
    build();
cout<<"fini"<<endl;
    ll ans=0;
    for(int i=1; i<=n; ++i) {
        if(a[i]>0) {
            D t= {0,0};
            qry(L[i],R[i],t);
            ans=max(ans,a[i]*t.sum);
        } else if(a[i]<0) {
            ll x=0;
            D t= {0,0};
            qry(L[i],i,t);
            x+=t.rsum;
            t= {0,0};
            qry(i,R[i],t);
            x+=t.lsum;
            x-=a[i];
            ans=max(ans,a[i]*x);
        }
    }
    printf("%lld\n",ans);
    return 0;
}