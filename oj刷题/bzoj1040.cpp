//
// Created by 赵婉如 on 2019-07-03.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>

using namespace std;
vector<int> G[1000010];
int f[1000010];
bool vis[1000010];
int hte[1000010];
long long dp[1000010][2];
int n;
int u, v;
int dep[1000010];
long long ans;

void dfs(int x, int p) {
    vis[x] = true;
    for (int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if (y == p)continue;
        if (vis[y]) {
            if (dep[y] < dep[x])u = x, v = y;
            continue;
        }
        dep[y] = dep[x] + 1;
        dfs(y, x);
    }
}

void solve(int x, int p) {
    dp[x][1] = f[x];
    dp[x][0] = 0;
    for (int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if ((x == u && y == v) || (x == v && y == u) || y == p)continue;
        solve(y, x);
        dp[x][0] += max(dp[y][0], dp[y][1]);
        dp[x][1] += dp[y][0];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d%d", f + i, hte + i);
        if (hte[hte[i]] == i)continue;
        G[hte[i]].push_back(i);
        G[i].push_back(hte[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i])continue;
        u = v = 0;
        dfs(i, 0);
        long long res;
        if (!u && !v) {
            solve(i, 0);
            res = max(dp[i][0], dp[i][1]);
        } else {
            solve(u, 0);
            res = dp[u][0];
            solve(v, 0);
            res = max(res, dp[v][0]);
        }
        ans += res;
    }
    printf("%lld", ans);
    return 0;
}
