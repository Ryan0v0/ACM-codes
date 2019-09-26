
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);i++)
const int maxn = 33000;
struct node
{
    int x,y;
    bool operator<(const node& a)const
    {
        if(x==a.x)return y<a.y;
        return x<a.x;
    }
}a[maxn];
int n,c[maxn],ans[maxn],b[maxn];
int lowbit(int x)
{
    return x&-x;
}
void insert(int x)
{
    while(x<=n) {
        c[x]++;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int now = 0;
    while(x>0) {
        now+=c[x];
        x-=lowbit(x);
    }
    return now;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    F(i, 1, n) {
        scanf("%d%d", &a[i].x, &a[i].y);
        b[i] = a[i].y;
    }
    sort(b + 1, b + 1 + n);
    int cnt = unique(b + 1, b + 1 + n) - b;
    sort(a + 1, a + 1 + n);
    F(i, 1, n) {
        int k = lower_bound(b + 1, b + 1 + cnt, a[i].y) - b;
        int now = sum(k);
        ans[now]++;
        insert(k);
    }
    F(i, 0, n - 1)printf("%d\n", ans[i]);
    return 0;
}