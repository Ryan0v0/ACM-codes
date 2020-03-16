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
const int maxn=200005;
const int maxm=128;
const int maxlog=20;

struct SuffixArray
{
    int m,n,rk[maxn],c[maxn],sa[maxn],t2[maxn],t[maxn],ht[maxn];
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

    int f_strncmp(char *P, char *S, int &pos, int m)
    {
        for(;pos<m&&P[pos]==S[pos];pos++);
        if(pos==m)
            return 0;
        return P[pos]>S[pos]?1:-1;
    }

    int fast_lower_bound(char *P){
        int L=0,R=n,M,r,max_match=0,lst=0,pos,m=strlen(P);
        while(L<R){
            int M=L+R>>1;
            pos=min(max_match,LCP(sa[M],sa[lst]));
            r=f_strncmp(P,s+sa[M],pos,m);
            if(pos>max_match)
                max_match=pos,lst=M;
            if(r>0)
                L=M+1;
            else
                R=M;
        }
        return L;
    }

    int fast_upper_bound(char *P){
        int L=0,R=n,M,r,max_match=0,lst=0,pos,m=strlen(P);
        while(L<R){
            int M=L+R>>1;
            pos=min(max_match,LCP(sa[M],sa[lst]));
            r=f_strncmp(P,s+sa[M],pos,m);
            if(pos>max_match)
                max_match=pos,lst=M;
            if(r>=0)
                L=M+1;
            else
                R=M;
        }
        return L;
    }
}A;
char s[200005];
int n,m,al[200005],bl[200005];
int root[200005],ls[20000005],rs[20000005],sum[20000005];
int cnt;
void build(int &p,int l,int r)
{
    p = ++cnt;
    sum[p] = 0;
    if(l==r)return ;
    int mid = (l+r)>>1;
    build(ls[p],l,mid);
    build(rs[p],mid+1,r);
}
void update(int &p,int pre,int l,int r,int pos)
{
    p = ++cnt;
    if(l==r)
    {
        sum[p] = sum[pre]+1;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos<=mid)update(ls[p],ls[pre],l,mid,pos);
    else update(rs[p],rs[pre],mid+1,r,pos);
    sum[p] = sum[ls[p]]+sum[rs[p]];
}
int query(int s, int t, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l+r)>>1;
    int Cnt = sum[ls[t]]-sum[ls[s]];
    //cout << s << " " << t << " " << cnt << endl;
    if (k <= Cnt)return query(ls[s],ls[t],l,mid,k);
    return query(rs[s],rs[t],mid+1,r,k-Cnt);
}

int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();
        scanf("%s",A.s);
        A.build_sa();
        A.getHeight();
        A.RMQ_init();
        int h,p,q;
        build(root[0],1,n);
        for(int i = 0;i<n;i++)
            update(root[i+1],root[i],1,n,A.sa[i]+1);
        while(m--){
            int l=read();int r=read();int k=read();
            //scanf("%s",s);
            h=strlen(s);
            p=A.fast_lower_bound(s);
            q=A.fast_upper_bound(s);
            al[p]++,al[q]--;
            if(al[p]-al[q]+1<k){
                puts("-1");
                continue;
            }
            else
            {
                printf("%d\n",query(root[al[p]-1],root[al[q]],1,n,k));
            }
        }
    }
    return 0;
}
