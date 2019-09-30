//
// Created by 赵婉如 on 2019-09-29.
//

#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 3e5 + 10;
vector<int> v[N], tmp[N];
int n, m;
int sz, id[N];
LL t, cnt[10];

int main() {
    n = read();
    m = read();
    F(i, 1, m) {
        int x = read();
        int y = read();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    F(i, 1, n) {
        sort(v[i].begin(), v[i].end());
        bool ok = 0;
        for (int j = 0; j < sz && !ok; j++)
            if (v[i] == tmp[j]) {
                id[i] = j + 1;
                ok = 1;
            }
        if (!ok) {
            if (sz == 3) {
                puts("-1");
                return 0;
            }
            tmp[sz] = v[i];
            id[i] = ++sz;
        }
    }
    if (sz < 3) {
        puts("-1");
        return 0;
    }
    F(i, 1, n) cnt[id[i]]++;
    t = cnt[1] * (n - cnt[1]) + cnt[2] * (n - cnt[2]) + cnt[3] * (n - cnt[3]);
    if (t != m * 2) {
        puts("-1");
        return 0;
    }
    F(i, 1, n) cout << id[i] << ' ';
    cout << endl;
    return 0;
}