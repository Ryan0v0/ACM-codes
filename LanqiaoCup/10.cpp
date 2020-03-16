//
// Created by 赵婉如 on 2020-03-16.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#define F(i, s, t) for (int i = s; i <= t; i++)
using namespace std;
int n, m;
int a[10010],f[10010][20];
map<int,int> mp;
void rmq()
{
    for(int i=1;i<=n;i++)f[i][0]=a[i];
    for(int i=1;i<=floor(log(n)/log(2));i++)
        for(int j=1;j<=n-(1<<i)+1;j++)
            f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
}
int query(int x,int y)
{
    int z=floor(log(y-x+1)/log(2));
    //cout<<x<<' '<<y<<' '<<z<<endl;
    return max(f[x][z],f[y-(1<<z)+1][z]);
}
int main()
{
    scanf("%d %d", &n, &m);
    F(i, 1, n) {
        scanf("%d", &a[i]);
        if (!mp.count(a[i])) mp[a[i]] = i;
    }
    rmq();
    //cout <<"here"<< endl;
    int last = 0;
    F(i, 1, m) {
        int ans = query(last + 1, n - m + i);
        last = mp[ans];
        cout << ans << ' ';
    }
    return 0;
}