#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define N 100005
#define INF 0x3f3f3f3f
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int a[N],pos[N];
struct Node{int l,r,maxn;}t[N*4];
void build(int idx,int l,int r)
{
    t[idx].l=l,t[idx].r=r;
    if(l==r){t[idx].maxn=pos[l];return;}
    int mid=(l+r)>>1;
    build(idx<<1,l,mid),build(idx<<1|1,mid+1,r);
    t[idx].maxn=max(t[idx<<1].maxn,t[idx<<1|1].maxn);
}
void del(int idx,int x)
{
    if(t[idx].l==t[idx].r){t[idx].maxn=INF;return;}
    int mid=(t[idx].l+t[idx].r)>>1;
    if(x<=mid)del(idx<<1,x);else del(idx<<1|1,x);
    t[idx].maxn=max(t[idx<<1].maxn,t[idx<<1|1].maxn);
}
int query(int idx,int k,int r)
{
    if(t[idx].maxn<=r)return 0;
    if(t[idx].l==t[idx].r)return t[idx].l;
    int mid=(t[idx].l+t[idx].r)>>1;
    if(k<=t[idx].l)
    {
        if(t[idx<<1].maxn>r)return query(idx<<1,k,r);
        else if(t[idx<<1|1].maxn>r)return query(idx<<1|1,k,r);
        else return 0;
    }
    else
    {
        if(k<=mid)
        {
            int f=query(idx<<1,k,r);
            if(f)return f;
            f=query(idx<<1|1,k,r);
            if(f)return f;
            return 0;
        }
        else
        {
            int f=query(idx<<1|1,k,r);
            if(f)return f;
            return 0;
        }
    }
}
int main()
{
    int T=read();
    while(T--)
    {
        int n=read(),m=read();
        for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
        build(1,1,n);
        int lstans=0;
        for(int i=1;i<=m;i++)
        {
            int op=read(),r=read()^lstans,k;
            if(op==1){if(a[r]!=-1)del(1,a[r]),a[r]=-1;}
            else
            {
                k=read()^lstans;
                int f=query(1,k,r);
                lstans=f?f:n+1;
                printf("%d\n",lstans);
            }
            
        }
    }
    return 0;
}
