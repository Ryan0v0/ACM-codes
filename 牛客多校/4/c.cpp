//
// Created by 赵婉如 on 2019-07-27.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
#define kl (k<<1)
#define kr (k<<1|1)
#define M (L+R>>1)
#define lin L,M
#define rin M+1,R
using namespace std;
using LL=long long;

struct node
{
    LL x,y;
}T[1<<20];

pair<int,int> a[500005];
int n,l[500005],r[500005],p,q;
LL sum[500005],ans=-1E18;

inline int fis(int *fa, int x)
{
    return fa[x]==x?x:fa[x]=fis(fa,fa[x]);
}

void build_tree(int k, int L, int R)
{
    if(L==R)
    {
        T[k].x=T[k].y=sum[L];
        return ;
    }
    build_tree(kl,lin);
    build_tree(kr,rin);
    T[k].x=min(T[kl].x,T[kr].x);
    T[k].y=max(T[kl].y,T[kr].y);
}

LL query1(int k, int L, int R, int l, int r)
{
    if(l>r)
        return 1E18;
    if(l<=L&&R<=r)
        return T[k].x;
    LL res=1E18;
    if(l<=M)
        res=min(res,query1(kl,lin,l,r));
    if(r>M)
        res=min(res,query1(kr,rin,l,r));
    return res;
}

LL query2(int k, int L, int R, int l, int r)
{
    if(l>r)
        return -1E18;
    if(l<=L&&R<=r)
        return T[k].y;
    LL res=-1E18;
    if(l<=M)
        res=max(res,query2(kl,lin,l,r));
    if(r>M)
        res=max(res,query2(kr,rin,l,r));
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].first),a[i].second=i,sum[i]=sum[i-1]+a[i].first;
    sort(a+1,a+n+1,greater<pair<int,int> >());
    build_tree(1,1,n);
    for(int i=1;i<=n;i++) {
        int u=a[i].second;
        l[u]=u;
        r[u]=u;
        if(l[u+1])
            l[fis(l,u+1)]=fis(l,u);
        if(l[u-1])
            l[fis(l,u)]=fis(l,u-1);
        if(r[u-1])
            r[fis(r,u-1)]=fis(r,u);
        if(r[u+1])
            r[fis(r,u)]=fis(r,u+1);
        p=fis(l,u);
        q=fis(r,u);
        ans=max(ans,(query2(1,1,n,u,q)-min(query1(1,1,n,p,u-1),sum[p-1]))*a[i].first);
        ans=max(ans,(query1(1,1,n,u,q)-max(query2(1,1,n,p,u-1),sum[p-1]))*a[i].first);
    }
    printf("%lld",ans);
    return 0;
}