#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 2e5+5;
struct E
{int nxt,to,no;}e[N<<1];
int d[N],st;
int head[N],tot = 1;
bool used[N];
int usedcnt;
void add(int x,int y)
{
    e[++tot].to = y;e[tot].nxt = head[x];head[x] = tot;e[tot].no = tot>>1;
    e[++tot].to = x;e[tot].nxt = head[y];head[y] = tot;e[tot].no = -(tot>>1);
    d[x]++,d[y]++;
}
vector<int>ans;
queue<int>Q;
int anscnt;
void dfs(int x)
{
    for(int i = head[x];i;i=e[i].nxt)
        if(!used[abs(e[i].no)])
        {
            d[x]--,d[e[i].to]--;
            used[abs(e[i].no)] = true;
            usedcnt++;
            head[x] = e[i].nxt;
            ans.push_back(e[i].no);
            dfs(e[i].to);
        }
    if(d[x]&1)st = x;
}
void init()
{
    memset(d,0,sizeof(d));
    memset(head,0,sizeof(head));
    usedcnt = anscnt = 0;
    tot = 1;
    memset(used,0,sizeof(used));
}
int Nod[N<<1];
int get_id(int x,int n)
{
    int l = 1,r = n+1;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(Nod[mid]<x)l = mid+1;
        else r = mid;
    }
    return l;
}
int ex[N],ey[N];
int main()
{
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int cnt = 0;
        init();
        for(int i = 1;i<= m;i++)
        {
            scanf("%d%d",&ex[i],&ey[i]);
            Nod[++cnt] = ex[i],Nod[++cnt] = ey[i];
        }
        sort(Nod+1,Nod+cnt+1);
        n = 0;
        for(int i = 1;i<= cnt;i++)
            if(Nod[i]!=Nod[n])
                Nod[++n] = Nod[i];
        for(int i = 1;i<= m;i++)
            add(get_id(ex[i],n),get_id(ey[i],n));
        int jcnt = 0,lm = m;
        for(int i = 1;i<=n;i++)if(d[i]&1)Q.push(i),jcnt++;
        while(jcnt>=3)
        {
            x = Q.front();Q.pop();
            y = Q.front();Q.pop();
            anscnt++;
            add(x,y);
            jcnt-=2;
        }
        if(Q.size()==2)
        {
            int x = Q.front();
            dfs(x);
        }
        else
        {
            x = Q.front();Q.pop();
            y = Q.front();Q.pop();
            anscnt++;
            x  = Q.front();
            dfs(x);
        }
        printf("%d\n",anscnt);
        int ed = ans.size();
        for(int i = 0;i<ed;i++)
        {
            int cc = 0;
            for(int j = i;ans[j]<=m&&j<ed;j++)
                cc++;
            printf("%d ",cc);
            for(int j = i;j< i+cc;j++)
                printf("%d ",ans[j]);
            i = i+cc;
            printf("\n");
        }
        ans.clear();
    }
    return 0;
}
