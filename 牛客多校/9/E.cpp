//
// Created by 赵婉如 on 2019-08-15.
//

//
// Created by 赵婉如 on 2019-08-14.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x/10);
    putchar(x%10 + '0');
}
typedef unsigned __int128 LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,m;
int p[N],siz[N];
int find(int x) { return x==p[x]?x:p[x]=find(p[x]); }
LL fac[N];/*
LL C(int x,int y)//c(x,y)
{
    return fac[x]/(fac[y]*fac[x-y]);
}*/
LL C(LL x)//c(x,4)
{
    if(x<4) return 0;
    return x*(x-1)*(x-2)*(x-3)/24;
}
int cnt=0,tot=0;
LL pro;
int main()
{
    //print(C(4));print(C(0));
    n=read();m=read();
    F(i,1,n) p[i]=i,siz[i]=1;tot=n;
    cnt=n;
    print(C(n));cout<<endl;
    //cout<<C(n)<<endl;
    pro=1LL;
    while(m--){
        int x=read();int y=read();
        int fx=find(x);int fy=find(y);
        if(siz[fx]==1){
            cnt--;
        }
        if(siz[fy]==1){
            cnt--;
        }
        if(fx!=fy){
            pro=pro/((LL)siz[fx]*(LL)siz[fy]);
            p[fy]=fx,siz[fx]+=siz[fy];
            tot--;
            pro=pro*(LL)siz[fx];
        }
        //cout<<cnt<<' ';print(pro);cout<<' ';print(C(n)-C(cnt));cout<<endl;
        LL res=(C(tot)-C(cnt))*pro+C(cnt);
        print(res);
        cout<<endl;
    }
    return 0;
}
/*
10 20
210
8 9
182
8 7
140
1 2
185
9 7
185
*/