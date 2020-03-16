//
// Created by 赵婉如 on 2019-08-15.
// luogu3809 求sa
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e6+10;
int m,n;
int sa[N],rk[N],t[N],t2[N],c[N],h[N];
char s[N];
void getsa(int m)
{
    int *x=t,*y=t2;
    F(i,0,m)c[i]=0;
    F(i,0,n)c[x[i]=s[i]]++;
    F(i,1,m)c[i]+=c[i-1];
    D(i,n,0)sa[--c[x[i]]]=i;
    for(int k=1;k<=n+1;k<<=1){
        int p=0;
        F(i,n-k+1,n)y[p++]=i;
        F(i,0,n)if(sa[i]>=k)y[p++]=sa[i]-k;
        F(i,0,m)c[i]=0;
        F(i,0,n)c[x[y[i]]]++;
        F(i,1,m)c[i]+=c[i-1];
        D(i,n,0)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);p=0;x[sa[0]]=0;
        F(i,1,n)x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p:++p;
        if(p>=n)break;
        m=p;
    }
    F(i,1,n)rk[sa[i]]=i;
    for(int i=0,k=0,j;i<n;h[rk[i++]]=k)
     for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
}
char str[N];
int main()
{
    scanf("%s",s);
    n=strlen(s);
    //F(i,0,n) s[i]=str[i]-'0';
    getsa(150);//128
    F(i,0,n-1) cout<<sa[i]<<' ';
    return 0;
}