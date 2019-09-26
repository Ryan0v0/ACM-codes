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
const int N=2e5+10;
const int M=128;

struct SuffixArray{
    int m,n,rk[N],c[N],sa[N],t2[N],t[N],ht[N],fal[N],far[N];
    bool mk[N];
    char s[N];

    void build_sa(){
        n=strlen(s);
        m=M;
        int i,*x=t,*y=t2,p=0;
        for(i=0;i<m;i++)
            c[i]=0;
        for(i=0;i<n;i++)
            c[x[i]=s[i]]++;
        for(i=1;i<m;i++)
            c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)
            sa[--c[x[i]]]=i;
        for(int k=1;k<=n&&p<n;k<<=1){
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

    void getHeight(){
        int i,j,k=0;
        for(i=0;i<n;i++)
            rk[sa[i]]=i;
        for(i=0;i<n;i++){
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

    int d[N][20],mm[N];

    void RMQ_init(){
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

    int LCP(int L, int R){
        if(L==R)
            return n-L;
        L=rk[L],R=rk[R];
        if(L>R)
            swap(L,R);
        L++;
        int &t=mm[R-L+1];
        return min(ht[d[L][t]],ht[d[R-(1<<t)+1][t]]);
    }

    int lower(int pos, int m){
        int L=0,R=pos,M;
        while(L<R){
            M=L+R>>1;
            if(LCP(sa[M],sa[pos])>=m)
                R=M;
            else
                L=M+1;
        }
        return L;
    }

    int upper(int pos, int m){
        int L=pos+1,R=n,M;
        while(L<R){
            M=L+R>>1;
            if(LCP(sa[M],sa[pos])>=m)
                L=M+1;
            else
                R=M;
        }
        return L;
    }
}A;

struct ChairmanTree {
    int root[N],ls[N*20],rs[N*20],sum[N*20];
    int cnt;
    void build(int &p, int l, int r) {
        p = ++cnt;
        sum[p] = 0;
        if (l == r)return;
        int mid = (l + r) >> 1;
        build(ls[p], l, mid);
        build(rs[p], mid + 1, r);
    }

    void update(int &p, int pre, int l, int r, int pos) {
        p = ++cnt;
        if (l == r) {
            sum[p] = sum[pre] + 1;
	    return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)update(ls[p], ls[pre], l, mid, pos);
        else update(rs[p], rs[pre], mid + 1, r, pos);
        sum[p] = sum[ls[p]] + sum[rs[p]];
    }

    int query(int s, int t, int l, int r, int k) {
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        int Cnt = sum[ls[t]] - sum[ls[s]];
        if (k <= Cnt)return query(ls[s], ls[t], l, mid, k);
        return query(rs[s], rs[t], mid + 1, r, k - Cnt);
    }
}T;
int n,q;
int main()
{
    int tt=read();
    while(tt--){
        n=read();q=read();scanf("%s",A.s);
        A.build_sa();
        A.getHeight();
        A.RMQ_init();
        T.cnt=0;
        T.build(T.root[0],1,n);
        for(int i=0;i<n;i++)
            T.update(T.root[i+1],T.root[i],1,n,A.sa[i]+1);
        while(q--){
            int l=read();int r=read();int k=read();
            l--,r--;//sa从0开始
            int pos=A.rk[l];//***
	    int p=A.lower(pos,r-l+1)+1;//主席树从1开始
            int q=A.upper(pos,r-l+1)+1;
            q--;
            if(q-p+1<k) puts("-1");
            else{
                int ans=T.query(T.root[p-1],T.root[q],1,n,k);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
