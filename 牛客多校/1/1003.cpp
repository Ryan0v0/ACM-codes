//
// Created by 赵婉如 on 2019-08-25.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int n,q;

const int maxn=100005;
const int maxm=128;
const int maxlog=18;

struct ChairmanTree
{
    struct item
    {
        LL d;
        int L,R;
    }T[maxlog*maxn];

    int c,root[maxn],n;

    void init(int x)
    {
        n=x,c=0;
    }

    void modify(int k1,int k2,int L,int R,int pos,LL d)
    {
        int M=L+R>>1;
        if(L==R)
        {
            T[k2].d=T[k1].d+d;
            return;
        }
        if(pos<=M)
            T[k2].L=++c,T[k2].R=T[k1].R,modify(T[k1].L,c,L,M,pos,d);
        else
            T[k2].R=++c,T[k2].L=T[k1].L,modify(T[k1].R,c,M+1,R,pos,d);
        T[k2].d=T[T[k2].L].d+T[T[k2].R].d;
    }

    int query(int k1, int k2, int L, int R, int q)
    {
        int M=L+R>>1;
        if(L==R)
            return L;
        if(T[T[k2].L].d-T[T[k1].L].d>=q)
            return query(T[k1].L,T[k2].L,L,M,q);
        else
            return query(T[k1].R,T[k2].R,M+1,R,q-(T[T[k2].L].d-T[T[k1].L].d));
    }

    void insert(int id, int pos, LL val)
    {
        root[id]=++c;
        modify(root[id-1],root[id],1,n,pos,val);
    }
}T;

struct SuffixArray
{
    int m,n,rk[maxn],c[maxn],sa[maxn],t2[maxn],t[maxn],ht[maxn],fal[maxn],far[maxn];
    bool mk[maxn];
    char s[maxn];

    void build_sa()
    {
        n=strlen(s);
        m=maxm;
        int i,*x=t,*y=t2,p=0;
        for(i=0;i<m;i++)
            c[i]=0;
        for(i=0;i<n;i++)
            c[x[i]=s[i]]++;
        for(i=1;i<m;i++)
            c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)
            sa[--c[x[i]]]=i;
        for(int k=1;k<=n&&p<n;k<<=1)
        {
            p=0;
            for(i=n-k;i<n;i++)
                y[p++]=i;
            for(i=0;i<n;i++)
                if(sa[i]>=k)
                    y[p++]=sa[i]-k;
            for(i=0;i<m;i++)
                c[i]=0;
            for(i=0;i<n;i++)
                c[x[y[i]]]++;
            for(i=1;i<m;i++)
                c[i]+=c[i-1];
            for(i=n-1;i>=0;i--)
                sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for(i=1;i<n;i++)
                x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&
                         sa[i-1]+k<n&&sa[i]+k<n&&y[sa[i-1]+k]==y[sa[i]+k]?
                         p-1:p++;
            m=p;
        }
    }

    void getHeight()
    {
        int i,j,k=0;
        for(i=0;i<n;i++)
            rk[sa[i]]=i;
        for(i=0;i<n;i++)
        {
            if(!rk[i])
                continue;
            if(k)
                --k;
            j=sa[rk[i]-1];
            while(j+k<n&&i+k<n&&s[i+k]==s[j+k])
                ++k;
            ht[rk[i]]=k;
        }
    }

    int d[maxn][maxlog],mm[maxn];

    void RMQ_init()
    {
        mm[0]=-1;
        for(int i=1;i<n;i++)
            mm[i]=i&i-1?mm[i-1]:mm[i-1]+1;
        for(int i=1;i<n;i++)
            d[i][0]=i;
        for(int j=1;1<<j<n;j++)
            for(int i=1;i+(1<<j)-1<n;i++)
                if(ht[d[i][j-1]]<ht[d[i+(1<<j-1)][j-1]])
                    d[i][j]=d[i][j-1];
                else
                    d[i][j]=d[i+(1<<j-1)][j-1];
    }

    int LCP(int L, int R)
    {
        if(L==R)
            return n-L;
        L=rk[L],R=rk[R];
        if(L>R)
            swap(L,R);
        L++;
        int &t=mm[R-L+1];
        return min(ht[d[L][t]],ht[d[R-(1<<t)+1][t]]);
    }

    int lower(int pos, int m)
    {
        int L=0,R=pos,M;
        while(L<R)
        {
            M=L+R>>1;
            if(LCP(sa[M],sa[pos])>=m)
                R=M;
            else
                L=M+1;
        }
        return L;
    }

    int upper(int pos, int m)
    {
        int L=pos+1,R=n,M;
        while(L<R)
        {
            M=L+R>>1;
            if(LCP(sa[M],sa[pos])>=m)
                L=M+1;
            else
                R=M;
        }
        return L;
    }
}A;

int tt,l,r,k;

int main()
{
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%s",&n,&q,A.s);
        A.build_sa();
        A.getHeight();
        A.RMQ_init();
        T.init(n);
        for(int i=0;i<n;i++)
            T.insert(i+1,A.sa[i]+1,1);
        while(q--)
        {
            scanf("%d%d%d",&l,&r,&k);
            --l,--r;
            int pos=A.rk[l];
            int p=A.lower(pos,r-l+1)+1;
            int q=A.upper(pos,r-l+1)+1;
            q--;
            p--;
            if(q-p<k)
                puts("-1");
            else
            {
                int ans=T.query(T.root[p],T.root[q],1,T.n,k);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
