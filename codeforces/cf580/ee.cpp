//
// Created by 赵婉如 on 2019-08-30.
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
const int N=4e5+10;
int  n,m,st,t,maxflow,tot=0,head[N];
struct edge{int fro,go,next,v;}e[N];
void add(int x,int y,int v)
{
    e[++tot]=(edge){x,y,head[x],v};head[x]=tot;
    //e[++tot]=(edge){x,head[y],v};head[y]=tot;
}
bool cmp1(edge &x,edge &y){
    return x.v<y.v;
}
struct query{int id,val;LL ans;}q[N];
bool cmp2(query &x,query &y){
    return x.val<y.val;
}
bool cmp3(query &x,query &y){
    return x.id<y.id;
}
int fa[N];
LL siz[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    n=read();m=read();
    F(i,1,n) fa[i]=i,siz[i]=1;
    F(i,1,n-1){
        int x=read();int y=read();int w=read();
        add(x,y,w);
    }
    sort(e+1,e+tot+1,cmp1);
    F(i,1,m){
        q[i].id=i;
        q[i].val=read();
    }
    sort(q+1,q+m+1,cmp2);
    q[0].ans=0;
    int st=1;
    F(i,1,m){
        q[i].ans=q[i-1].ans;
        F(j,st,n-1){
            if(e[j].v>q[i].val){
                st=j;
                break;
            }
            int x=e[j].fro;
            int y=e[j].go;
            int fx=find(x);
            int fy=find(y);
            if(fx!=fy){
                q[i].ans+=siz[fx]*siz[fy];
                fa[fy]=fx;
                siz[fx]+=siz[fy];
            }
        }
    }

    sort(q+1,q+m+1,cmp3);
    F(i,1,m){
        cout<<q[i].ans<<' ';
    }
    //cout<<endl;
    return 0;
}
/*
5 6
1 2 1
1 5 2
2 3 3
2 4 4
0 4 1 3 2 5

4 4
1 2 1
2 3 2
3 4 1
0 1 2 3

 */