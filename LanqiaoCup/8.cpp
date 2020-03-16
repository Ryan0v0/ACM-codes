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

using namespace std;
int g[1010][1010];
char str[1010];
vector<pair<int,int>> v;
int dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", (str + 1));
        for (int j = 1; j <= m; j++) {
            if (str[j] == '.') g[i][j] = 0;
            if (str[j] == 'g') {
                g[i][j] = 1;
                v.push_back({i, j});
            }
        }
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (!g[i][j]){
                for (pair<int,int> p : v) if (dis(p.first, p.second, i, j) <= k){
                        g[i][j] = 1;
                    }
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j]) cout << 'g';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}