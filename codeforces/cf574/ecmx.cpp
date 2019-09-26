//
// Created by 赵婉如 on 2019-07-18.
//

#include<cstdio>
#include<algorithm>
using namespace std;
using LL=long long;

int n,m,a,b,g,x,y,z,h[3005][3005],mv[3005][3005];
LL ans;

template<class item>
class queue
{
public:
    int head,tail;
    item d[3005];

    item &front()
    {
        return d[head];
    }

    item &back()
    {
        return d[tail-1];
    }

    void push(item t)
    {
        d[tail++]=t;
    }

    bool empty()
    {
        return head==tail;
    }

    void pop()
    {
        ++head;
    }

    void pop_tail()
    {
        --tail;
    }

    void clear()
    {
        head=tail=0;
    }
};

queue<pair<int,int>> Q;

int main()
{
    scanf("%d%d%d%d%d%d%d%d",&n,&m,&a,&b,&g,&x,&y,&z);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            h[i][j]=g;
            g=((LL)g*x+y)%z;
        }
    for(int i=1;i<=n;i++)
    {
        Q.clear();
        for(int j=1;j<=b;j++)
        {
            while(!Q.empty()&&h[i][j]<=Q.back().first)
                Q.pop_tail();
            Q.push({h[i][j],j});
        }
        for(int j=1;j+b-1<=m;j++)
        {
            mv[i][j]=Q.front().first;
            if(Q.front().second==j)
                Q.pop();
            while(!Q.empty()&&h[i][j+b]<=Q.back().first)
                Q.pop_tail();
            Q.push({h[i][j+b],j+b});
        }
    }
    for(int j=1;j+b-1<=m;j++)
    {
        Q.clear();
        for(int i=1;i<=a;i++)
        {
            while(!Q.empty()&&mv[i][j]<=Q.back().first)
                Q.pop_tail();
            Q.push({mv[i][j],i});
        }
        for(int i=1;i+a-1<=n;i++)
        {
            ans+=Q.front().first;
            if(Q.front().second==i)
                Q.pop();
            while(!Q.empty()&&mv[i+a][j]<=Q.back().first)
                Q.pop_tail();
            Q.push({mv[i+a][j],i+a});
        }
    }
    printf("%lld",ans);
    return 0;
}