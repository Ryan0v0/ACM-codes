//
// Created by 赵婉如 on 2019-08-22.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef double DB;
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define MIT (2147483647)
#define INF (1000000001)
#define MLL (1000000000000000001LL)
#define sz(x) ((int) (x).size())
#define clr(x, y) memset(x, y, sizeof(x))
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define ft first
#define sd second
#define mk make_pair

inline int Getint()
{
    int Ret = 0;
    char Ch = ' ';
    bool Flag = 0;
    while(!(Ch >= '0' && Ch <= '9'))
    {
        if(Ch == '-') Flag ^= 1;
        Ch = getchar();
    }
    while(Ch >= '0' && Ch <= '9')
    {
        Ret = Ret * 10 + Ch - '0';
        Ch = getchar();
    }
    return Flag ? -Ret : Ret;
}

const int N = 200010, M = 400010;
int n, m;
int cnt[N];
vector<int> fa[N];
priority_queue<int> ranks;
vector<int> ans;

inline void Input()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        fa[y].pub(x), cnt[x]++;
    }
}

inline void Solve()
{
    for(int i = 1; i <= n; i++)
        if(!cnt[i]) ranks.push(i);
    F(i,1,n) cout<<cnt[i]<<' ';cout<<endl;
    for(int index = n; index >= 1; index--){
        int u = ranks.top();
        ranks.pop();
        ans.pub(u);
        cout<<u<<endl;
        int length = sz(fa[u]);
        for(int i = 0, v; i < length; i++) {
            cout<<u<<' '<<fa[u][i]<<endl;
            if (!(--cnt[v = fa[u][i]]))
                ranks.push(v);
        }
    }

    int length = sz(ans);
    for(int i = length - 1; i > 0; i--)
        printf("%d ", ans[i]);
    printf("%d\n", ans[0]);
}

int main()
{
    Input();
    Solve();
    return 0;
}
/*
6 3
6 1
4 6
5 1

 */