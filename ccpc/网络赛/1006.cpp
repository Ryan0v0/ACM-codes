#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int INF = 20000307;
const int N = 2e5+5;
struct Splay
{
    Splay *ls,*rs,*fa;
    int size,num;
    Splay (int x);
    void push_up();
}*null = new Splay(0),*root,*tree[N];
int a[N],n,m;
Splay :: Splay (int x)
{
    ls = rs = fa = null;
    size = x?1:0;
    num = x;
}
void Splay :: push_up()
{
    size = ls->size+rs->size+1;
}
void go_left(Splay *x)
{
    Splay *y = x->fa;
    y->rs = x->ls;
    x->ls->fa = y;
    x->ls = y;
    x->fa = y->fa;
    if(y->fa->ls==y)
        y->fa->ls = x;
    else y->fa->rs = x;
    y->fa = x;
    y->push_up();
    if(y==root)root = x;
}
void go_right(Splay *x)
{
    Splay *y = x->fa;
    y->ls = x->rs;
    x->rs->fa = y;
    x->rs = y;
    x->fa = y->fa;
    if(y->fa->ls==y)
        y->fa->ls = x;
    else y->fa->rs = x;
    y->fa = x;
    y->push_up();
    if(y==root)root = x;
}
void splay(Splay *x,Splay *tar)
{
    while(true)
    {
        Splay *y = x->fa,*z = y->fa;
        if(y==tar)break;
        if(z==tar)
        {
            if(x==y->ls)
                go_right(x);
            else go_left(x);
            break;
        }
        if(x==y->ls)
        {
            if(y==z->ls)go_right(y);
            go_right(x);
        }else
        {
            if(y==z->rs)go_left(y);
            go_left(x);
        }
    }
    x->push_up();
}
void Find(Splay *x,int y,Splay *z)
{
    while(true)
    {
        if(x->ls->size>=y)
            x = x->ls;
        else
        {
            y-=x->ls->size;
            if(y==1)break;
            y--;
            x = x->rs;
        }
    }
    splay(x,z);
}
int get_rank(Splay *x)
{
    int ans = x->ls->size;
    for(;x!=root;x = x->fa)
        if(x==x->fa->rs)
            ans+=x->fa->ls->size+1;
    return ans;
}
void Insert(Splay *x,int y)
{
    Find(root,y,null);
    Find(root,y+1,root);
    root->rs->ls = x;
    x->fa = root->rs;
    root->rs->push_up();
    root->push_up();
}
void Delete(int y)
{
    Find(root,y,null);
    Find(root,y+2,root);
    root->rs->ls = null;
    root->rs->push_up();
    root->push_up();
}
void build(Splay *&x,int l,int r)
{
    if(r<l)return ;
    int mid = (l+r)>>1;
    x = tree[a[mid]];
    build(x->ls,l,mid-1);
    build(x->rs,mid+1,r);
    if(x->ls!=null)x->ls->fa = x;
    if(x->rs!=null)x->rs->fa = x;
    x->push_up();
}
void init()
{
    root = new Splay(INF);
    root->rs = new Splay(INF);
    build(root->rs->ls,1,n);
    root->rs->ls->fa = root->rs;
    root->rs->push_up();
    root->rs->fa = root;
    root->push_up();
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i = 1;i<= n;i++)
        tree[i] = new Splay(i);
    init();
    for(int i = 1;i<=m;i++)
    {
        int pos;
        scanf("%d",&pos);
        int tmp = get_rank(tree[pos]);
        Delete(tmp);
        Insert(tree[pos],1);
    }
    for(int i = 2;i<= n+1;i++)
    {
        Find(root,i,null);
        printf("%d ",root->num);
    }
    return 0;
}

