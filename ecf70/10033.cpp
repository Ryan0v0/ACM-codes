//
// Created by 赵婉如 on 2019-08-23.
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
const int N = 4e5+5;
char s1[N>>1],s2[N>>1],s[N];
int sa[N],rnk[N],val[N],nv[N],q[N],cnt[N],h[N],a[N];
inline bool is_same(int a,int b,int hl,int len)
{
    return val[a]==val[b]&&((a+hl>len&&b+hl>len)||(a+hl<len&&b+hl<len&&val[a+hl]==val[b+hl]));
}
void build_sa(int len,int lim)
{
    int i,j,k;
    for(i = 0;i<lim;i++)cnt[i] = 0;
    for(i = 0;i<len;i++)cnt[val[i]=s[i]]++;
    for(i = 1;i<lim;i++)cnt[i]+=cnt[i-1];
    for(i = len-1;i>= 0;i--)sa[--cnt[val[i]]] = i;
    for(int d = 1;;d++)
    {
        int hl = 1<<(d-1),id = 0;
        for(i = 0;i<len;i++)if(sa[i]+hl>=len)q[id++] = sa[i];
        for(i = 0;i<len;i++)if(sa[i]>=hl)q[id++] = sa[i]-hl;

        for(i = 0;i<lim;i++)cnt[i] = 0;
        for(i = 0;i<len;i++)cnt[val[q[i]]]++;
        for(i = 1;i<lim;i++)cnt[i]+=cnt[i-1];
        for(i = len-1;i>= 0;i--)sa[--cnt[val[q[i]]]] = q[i];

        lim = 0;
        for(i = 0;i<len;lim++)
        {
            for(j = i;j<len-1&&is_same(sa[j],sa[j+1],hl,len);j++);
            for(k = i,i=j+1;k<= j;k++)nv[sa[k]] = lim;
        }
        if(lim==len)return ;
        for(i = 0;i<len;i++)val[i] = nv[i];
    }
}
void build_height(int len)
{
    for(int i = 0;i< len;i++)rnk[sa[i]]=i;
    for(int i = 0;i< len;i++)
        if(rnk[i])
        {
            int j = 0;
            if(i)j = max(h[rnk[i-1]]-1,0);
            while(i+j<len&&sa[rnk[i]-1]+j<len&&s[i+j]==s[sa[rnk[i]-1]+j])j++;
            h[rnk[i]] = j;
        }
}
inline bool cmp(int a,int b){return h[a]>h[b];}
int fa[N];
LL st[N],en[N];
long long ans;
int Lcp(int l, int r) {
    if (l == r) return n; ++l;
    int p = Log[r - l + 1];
    return min(f[p][l], f[p][r - (1 << p) + 1]);
}
/**************************************************/
const int N = 200005;
const int M = 4000005;
typedef long long ll;
int ls[M],rs[M],sum[M],ans[M];
int root[N],n,m;
int a[N];
int st[N],ed[N],cnt;
struct P
{int val,id;}T[N];
bool cmpT(P a,P b){return a.val<b.val;}
struct Up
{int pos,val,aa;}ask[N<<1];
int cnt_ask;
bool cmp(Up a,Up b){return a.pos<b.pos;}
int a_T[N];
void init()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<= n;i++)
    {
        scanf("%d%d%d",&st[i],&ed[i],&a[i]);
        ask[++cnt_ask] = (Up){st[i],1,i};
        ask[++cnt_ask] = (Up){ed[i]+1,-1,i};
        T[i] = (P){a[i],i};
    }
    sort(T+1,T+n+1,cmpT);
    for(int i = 1;i<= n;i++)
        a_T[T[i].id] = i;
    sort(ask+1,ask+cnt_ask+1,cmp);
}
void update(int &p,int pre,int l,int r,int pos,int val)
{
    p = ++cnt;
    if(l==r)
    {
        sum[p]=sum[pre]+val;
        ans[p]=ans[pre]+val*T[l].val;
        return ;
    }
    int mid = (l+r)>>1;
    ls[p] = ls[pre],rs[p] = rs[pre];
    if(pos<=mid)update(ls[p],ls[pre],l,mid,pos,val);
    else update(rs[p],rs[pre],mid+1,r,pos,val);
    sum[p] = sum[ls[p]]+sum[rs[p]];
    ans[p] = ans[ls[p]]+ans[rs[p]];
}
ll Ans;
void getans(int p,int k)
{
    int l = 1,r = n;
    Ans = 0;
    p = root[p];
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(sum[ls[p]]>=k)
            p = ls[p],r = mid;
        else
            Ans+=ans[ls[p]],k-=sum[ls[p]],p = rs[p],l = mid+1;
    }
    Ans+=ans[p];
    printf("%lld\n",Ans);
}
int tot;
int l[N],r[N],c[N];
int build(int l,int r)
{
    int rt=tot++;
    c[rt]=0;
    if(l!=r){
        int mid=(l+r)>>1;
        ls[rt]=build(l,mid);
        rs[rt]=build(mid+1,r);
    }
    return rt;
}
int update(int rt,int pos,int val){

}

int len,query;
int main()
{
    int tt=read();
    while(tt--){
        len=read();query=read();
        scanf("%s",s);
        build_sa(len,256);
        build_height(len);
        while(query--){
            int l=read();int r=read();int k=read();

        }
    }
    init();
    int j=1;
    for(int i = 1;i<= n;i++) {
        root[i] = root[i-1];
        while(j<=cnt_ask&&ask[j].pos==i){
            update(root[i],root[i],1,n,a_T[ask[j].aa],ask[j].val);
            j++;
        }
    }
    return 0;
}