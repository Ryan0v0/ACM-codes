//
// Created by 赵婉如 on 2019-08-07.
//

#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 10007;
const int N = 1e5+5;
int fa[N],ch[N][2],size[N],add[N],mul[N],sum[N],val[N];
bool rev[N];
inline void init(int x,int v)
{
    ch[x][0] = ch[x][1] = fa[x] = 0;
    val[x] = sum[x] = v;
    size[x] = mul[x] = 1;add[x] = rev[x] = 0;
}
inline bool is_root(int x)
{
    return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}
void Push_up(int p)
{
    sum[p] = sum[ch[p][0]]+val[p]+sum[ch[p][1]];
    size[p] = size[ch[p][0]]+1+size[ch[p][1]];
}
void reverse(int p)
{
    if(!p)return ;
    swap(ch[p][0],ch[p][1]);rev[p]^=1;
}
void Add(int p,int del)
{
    if(!p)return ;
    (add[p]+=del)%=mod;
    (val[p]+=del)%=mod;
    (sum[p]+=(ll)del*size[p]%mod)%=mod;
}
void Mul(int p,int del)
{
    if(!p)return ;
    add[p] = (ll)add[p]*del%mod;
    val[p] = (ll)val[p]*del%mod;
    sum[p] = (ll)sum[p]*del%mod;
    mul[p] = (ll)mul[p]*del%mod;
}
void Push_down(int p)
{
    if(!is_root(p))Push_down(fa[p]);
    if(mul[p]^1)
    {
        Mul(ch[p][0],mul[p]);
        Mul(ch[p][1],mul[p]);
        mul[p] = 1;
    }
    if(add[p])
    {
        Add(ch[p][0],add[p]);
        Add(ch[p][1],add[p]);
        add[p] = 0;
    }
    if(rev[p])
    {
        reverse(ch[p][0]),reverse(ch[p][1]);
        rev[p]^=1;
    }
}
void rotate(int x)
{
    int y = fa[x],z = fa[y];
    int d = ch[y][1]==x;
    if(!is_root(y))
    {
        if(ch[z][0]==y)ch[z][0] = x;
        else if(ch[z][1]==y)ch[z][1] = x;
    }
    fa[y] = x,fa[x] = z,fa[ch[x][d^1]] = y;
    ch[y][d] = ch[x][d^1],ch[x][d^1] = y;
    Push_up(y);
}
void splay(int x)
{
    Push_down(x);
    while(!is_root(x))
    {
        int y = fa[x],z = fa[y];
        if(!is_root(y))
        {
            if((ch[y][0]==x)^(ch[z][0]==y))rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    Push_up(x);
}
void access(int x)
{
    int t;
    while(x)
    {
        splay(x);
        ch[x][1] = t;
        Push_up(x);
        t = x;
        x = fa[x];
    }
}
void move_to_root(int x)
{
    access(x);
    splay(x);
    reverse(x);
}
void link(int x,int y)
{
    move_to_root(x);
    fa[x] = y;
}
void cut(int x,int y)
{
    move_to_root(x);
    access(y);
    splay(y);
    fa[x] = 0;
    ch[y][0] =0;
    Push_up(y);
}
struct E
{int next,to;}e[N<<1];
int head[N],tot;
queue<int>Q;
void adde(int x,int y)
{
    e[++tot].to = y;e[tot].next = head[x];head[x] = tot;
    e[++tot].to = x;e[tot].next = head[y];head[y] = tot;
}
void bfs()
{
    Q.push(1);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for(int i = head[x];i;i=e[i].next)
            if(e[i].to!=fa[x])
                fa[e[i].to]=x,Q.push(e[i].to);
    }
}
int main()
{
    return 0;
}