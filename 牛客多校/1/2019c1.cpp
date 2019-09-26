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
const int MAXN=2e5+10;
struct UF{
    int fa[MAXN];
    void init(){
        mec(fa,0);
    }
    void join(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy) fa[fy]=fx;
    }
    int find(int x){

    }
};
UF N,E,S,W;
#define pa pair<int,int>
map<pa,int> p2id;
map<int,pa> id2p;
int n,m,q,sx,sy;
char str[MAXN];
void init()
{

}
int tot;
int getId(int x,int y)
{
    pa p=make_pair(x,y);
    if(!p2id.count(p)){
        p2id[p]=++tot;
        id2p[tot]=p;
    }
    return p2id[p];
}
pa getNext(int x,int y,char dir)
{
    int now=getId(x,y);
    int nextId;
    if(dir=='N'){
        nextId=N.find(now);
    }else if(dir=='W'){
        nextId=W.find(now);
    }else if(dir=='S'){
        nextId=S.find(now);
    }else if(dir=='E'){
        nextId=E.find(now);
    }
    return id2p[nextId];
}
void work(int x,int y)
{
    int now=getId(x,y);

    int w=getId(x,y-1);
    int e=getId(x,y+1);
    int n=getId(x-1,y);
    int s=getId(x+1,y);

    W.join(w,now);
    E.join(e,now);
    N.join(n,now);
    S.join(s,now);
}
void solve()
{
    n=read();m=read();q=read();
    sx=read();sy=read();
    scanf("%s",str);
    init();
    work(sx,sy);
    pair<int,int> now=make_pair(sx,sy);
    F(i,1,n){
        now=getNext(now.first,now.second,str[i]);
        work(now.first,now.second);
    }
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}