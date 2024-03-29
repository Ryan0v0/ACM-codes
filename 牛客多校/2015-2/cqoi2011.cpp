//
// Created by 赵婉如 on 2019-08-05.
//

#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') ch=='-'&&(f=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int N=1e5+10;
struct AC{int m,v,d,id,t;}e[N<<1];
int n,m,tot;
int pos[N],a[N],c[N];ll ans[N];
bool cmp1(AC x,AC y){return x.d<y.d;}
void add(int x,int k){while (x<=n)c[x]+=k,x+=(x&(-x));}
int query(int x){int su=0;while(x)su+=c[x],x-=(x&(-x));return su;}
void cdq(int l,int r){
    if (l==r) return;
    int mid=(l+r)>>1,j=l;
    cdq(l,mid),cdq(mid+1,r);
    sort(e+l,e+mid+1,cmp1);
    sort(e+mid+1,e+r+1,cmp1);
    for (int i=mid+1;i<=r;++i){
        while (j<=mid&&e[j].d<=e[i].d)add(e[j].v,e[j].m),++j;
        ans[e[i].id]+=e[i].m*(query(n)-query(e[i].v));
    }
    for (int i=l;i<j;++i) add(e[i].v,-e[i].m);
    j=mid;
    for (int i=r;i>mid;--i){
        while (j>=l&&e[j].d>=e[i].d)add(e[j].v,e[j].m),--j;
        ans[e[i].id]+=e[i].m*query(e[i].v-1);
    }
    for (int i=mid;i>j;--i) add(e[i].v,-e[i].m);
}
int main(){
    n=read(),m=read();
    for (int i=1;i<=n;++i)a[i]=read(),pos[a[i]]=i,e[++tot]=(AC){1,a[i],i,0,tot};
    for (int i=1,x;i<=m;++i)x=read(),e[++tot]=(AC){-1,x,pos[x],i,tot};
    cdq(1,tot);
    for (int i=1;i<=m;++i) ans[i]+=ans[i-1];
    for (int i=0;i<m;++i) printf("%lld\n",ans[i]);
    return 0;
}