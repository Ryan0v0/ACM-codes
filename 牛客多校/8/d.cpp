//
// Created by 赵婉如 on 2019-08-10.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
using namespace std;
const int N=500000+5;
const int inf=1<<30;
int n,m,rt,D,ans;
struct kdtree{
    int l,r;
    int d[2];
    int mn[2],mx[2];
    bool operator <(const kdtree &rhs)const{
        return d[D]<rhs.d[D]||(d[D]==rhs.d[D]&&d[D^1]<rhs.d[D^1]);
    }
}t[N<<1],p[N],tmp;
int dis(kdtree a,kdtree b)
{return abs(a.d[0]-b.d[0])+abs(a.d[1]-b.d[1]);}
void pushup(int k)
{
    int ls=t[k].l,rs=t[k].r;
    F(i,0,1){
        if(ls){
            t[k].mn[i]=min(t[k].mn[i],t[ls].mn[i]);
            t[k].mx[i]=max(t[k].mx[i],t[ls].mx[i]);
        }
        if(rs){
            t[k].mn[i]=min(t[k].mn[i],t[rs].mn[i]);
            t[k].mx[i]=max(t[k].mx[i],t[rs].mx[i]);
        }
    }
}
inline int build(int l,int r,int now)
{
    D=now;
    int mid=(l+r)>>1;
    nth_element(p+l,p+mid,p+r+1);
    t[mid]=p[mid];
    F(i,0,1) t[mid].mn[i]=t[mid].mx[i]=t[mid].d[i];
    if (l<mid) t[mid].l=build(l,mid-1,now^1);
    if (mid<r) t[mid].r=build(mid+1,r,now^1);
    pushup(mid);
    return mid;
}
int get(int k,kdtree x)//这就是"估价函数"啦~
{
    int res=0;
    F(i,0,1) res+=max(0,t[k].mn[i]-x.d[i]);
    F(i,0,1) res+=max(0,x.d[i]-t[k].mx[i]);
    return res;
}
void insert(int k,int now)
{
    if(tmp.d[now]>=t[k].d[now]){//右侧
        if(t[k].r) insert(t[k].r,now^1);
        else{
            t[k].r=++n;t[n]=tmp;
            F(i,0,1) t[n].mn[i]=t[n].mx[i]=t[n].d[i];
        }
    }else{
        if(t[k].l) insert(t[k].l,now^1);
        else{
            t[k].l=++n;t[n]=tmp;
            F(i,0,1) t[n].mn[i]=t[n].mx[i]=t[n].d[i];
        }
    }
    pushup(k);
}
void query(int k,int now)
{
    int dl=inf,dr=inf;
    int d=dis(t[k],tmp);
    ans=min(ans,d);
    if(t[k].l) dl=get(t[k].l,tmp);//注意要判断
    if(t[k].r) dr=get(t[k].r,tmp);
    if(dl<dr){
        if(dl<ans) query(t[k].l,now^1);
        if(dr<ans) query(t[k].r,now^1);
    }else{
        if(dr<ans) query(t[k].r,now^1);
        if(dl<ans) query(t[k].l,now^1);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("sjy.in", "r", stdin);
#endif
    scanf("%d%d",&n,&m);
    F(i,1,n){
        p[i].l=p[i].r=0;
        scanf("%d%d",&p[i].d[0],&p[i].d[1]);
    }
    rt=build(1,n,0);
    tmp.l=tmp.r=0;
    while(m--){
        int typ;
        scanf("%d%d%d",&typ,&tmp.d[0],&tmp.d[1]);
        if(typ==1) insert(rt,0);
        else{
            ans=inf;
            query(rt,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}
