//
// Created by 赵婉如 on 2019-08-07.
//


#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
//#include<windows.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
const int inf = 0x3f3f3f3f;

struct node
{
    int val;
    int fa,ch[2];
    bool reverse,is_root;
    int MIN;
    int u,v;
    int pp[2];
    void init(int x)
    {
        val=x;
        fa=ch[0]=ch[1]=0;
        reverse=0;
        is_root=1;
        MIN=inf;
        u=v=-1;
        pp[0]=pp[1]=x;
    }
}T[maxn];

int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}

void pushreverse(int x)
{
    if(!x) return;
    swap(T[x].ch[0],T[x].ch[1]);
    swap(T[x].pp[0],T[x].pp[1]);
    T[x].reverse^=1;
}

void pushdown(int x)
{
    if(T[x].reverse)
    {
        pushreverse(T[x].ch[0]);
        pushreverse(T[x].ch[1]);
        T[x].reverse=false;
    }
}

void pushup(int x)
{
    T[x].MIN=inf;
    T[x].u=T[x].v=-1;
    T[x].pp[0]=T[x].pp[1]=x;
    pushdown(x);
    for(int i=0;i<2;i++)
    {
        if(T[x].ch[i])
        {
            T[x].pp[i]=T[T[x].ch[i]].pp[i];
            if(T[x].MIN>T[T[x].ch[i]].MIN)
            {
                T[x].MIN=T[T[x].ch[i]].MIN;
                T[x].u=T[T[x].ch[i]].u;
                T[x].v=T[T[x].ch[i]].v;
            }
            int GCD=gcd(T[x].val,T[T[x].ch[i]].pp[i^1]);
            if(T[x].MIN>GCD)
            {
                T[x].MIN=GCD;
                T[x].u=x;
                T[x].v=T[T[x].ch[i]].pp[i^1];
            }
        }
    }
}

int getson(int x)
{
    return x==T[T[x].fa].ch[1];
}

void rotate(int x)
{
    if(T[x].is_root) return;
    int k=getson(x);
    int fa=T[x].fa;
    int fafa=T[fa].fa;
    pushdown(fa);
    pushdown(x);
    T[fa].ch[k]=T[x].ch[k^1];
    if(T[x].ch[k^1]) T[T[x].ch[k^1]].fa=fa;
    T[x].ch[k^1]=fa;
    T[fa].fa=x;
    T[x].fa=fafa;
    if(T[fa].is_root)
    {
        T[fa].is_root=false;
        T[x].is_root=true;
    }
    else
    {
        T[fafa].ch[fa==T[fafa].ch[1]]=x;
    }
    pushup(fa);
    pushup(x);
}

void push(int x)
{
    if(!T[x].is_root) push(T[x].fa);
    pushdown(x);
}

void Splay(int x)
{
    push(x);
    for(int fa;!T[x].is_root;rotate(x))
    {
        if(!T[fa=T[x].fa].is_root)
        {
            rotate((getson(x)==getson(fa))?fa:x);
        }
    }
}

void access(int x)
{
    int y=0;
    do
    {
        Splay(x);
        T[T[x].ch[1]].is_root=true;
        T[T[x].ch[1]=y].is_root=false;
        pushup(x);
        x=T[y=x].fa;
    }while(x);
}

void mroot(int x)
{
    access(x);
    Splay(x);
    pushreverse(x);
}

void link(int u,int v)
{
    mroot(u);
    T[u].fa=v;
}

void cut(int u,int v)
{
    mroot(u);
    access(v);
    Splay(v);
    pushdown(v);
    T[T[v].ch[0]].fa=T[v].fa;
    T[T[v].ch[0]].is_root=true;
    T[v].fa=0;T[v].ch[0]=0;
    pushup(v);
}

vector<int>vec[maxn];
int vis[maxn];
ll a[maxn];
ll ans;

void getpri()
{
    for(int i=2;i<maxn;i++) if(!vis[i])
            for(int j=i;j<maxn;j+=i)
            {
                vis[j]=1;
                vec[j].push_back(i);
            }
}

void debug()
{
    puts("----------");
    for(int i=1;i<=21;i++)
    {
        printf("i:%d fa:%d le:%d ri:%d rt:%d rev:%d lll:%d rrr:%d\n",i,T[i].fa,T[i].ch[0],T[i].ch[1],T[i].is_root,T[i].reverse,T[i].pp[0],T[i].pp[1]);
    }
    puts("----------");
}

void init()
{
    getpri();
    ans=0;
    a[0]=0;
    a[1]=0;
    T[1].init(1);
    for(int i=2;i<maxn;i++)
    {
        T[i].init(i);
        bool f=1;
        for(int j=0;j<(int)vec[i].size();j++)
        {
            int x = vec[i][j];
            x=i/x;
            if(f)
            {
                link(x,i);
                ans+=x;
                f=false;
                //debug();
            }
            else
            {
                mroot(i);
                access(x);
                Splay(x);
                //debug();
                int MIN = T[T[x].ch[0]].MIN;
                int u = T[T[x].ch[0]].u;
                int v = T[T[x].ch[0]].v;
                int GCD = T[x].MIN;
                if(MIN>GCD)
                {
                    MIN=GCD;
                    u=x;
                    v=T[x].ch[0];
                }
                if(MIN<x)
                {
                    cut(u,v);
                    link(x,i);
                    ans-=MIN;
                    ans+=x;
                }
            }
        }
        a[i]=ans;
    }
}

int n;

void solve()
{
    printf("%lld\n",a[n]);
}

int main()
{
    init();
    while(~scanf("%d",&n)) solve();
    return 0;
}