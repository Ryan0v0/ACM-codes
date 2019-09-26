//
// Created by 赵婉如 on 2019-08-05.
//

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 100;

struct Point {
    int x, y;
    int id;
} p[MAXN];
int f[MAXN];

bool cmp(const Point&a, const Point&b) {
    return a.id < b.id;
}
bool cmp2(const Point&a, const Point&b) {
    return a.x < b.x || (a.x == b.x && (a.y > b.y || (a.y == b.y && a.id < b.id)));
}

int b[MAXN * 2];
void upd(int p, int v) {
    //b[p] = v;
    //return ;
    for (; p < MAXN * 2; b[p] = max(b[p], v), p += p&-p);
}
void clr(int p) {
    //b[p] = 0;
    //return ;
    for (; p < MAXN * 2; b[p] = 0, p += p&-p);
}
int qry(int p) {
    int r = 0;
    //for (int i = 1; i <= p; ++i)
    //    r = max(r, b[i]);
    //return r;
    for (; 0 < p; r = max(r, b[p]), p -= p&-p);
    return r;
}

void cdq(int l, int r) {
    if (l == r) return ;
    int m = (l + r) >> 1;
    cdq(m + 1, r);
    sort(p + m + 1, p + r + 1, cmp2);
    sort(p + l, p + m + 1, cmp2);
    for (int i = m, j = r; l <= i; --i) {
        while (m < j && p[i].x <= p[j].x) upd(p[j].y, f[p[j].id]), --j;
        f[p[i].id] = max(f[p[i].id], 1 + qry(p[i].y));
    }
    for (int j = r; m < j; --j)
        clr(p[j].y);
    sort(p + l, p + m + 1, cmp);
    cdq(l, m);
}

int main() {
#ifdef lol
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
#endif

    int n;
    while (scanf("%d", &n) != EOF) {
        int c = 0, *t = new int[n * 2];
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i].y), t[c++] = p[i].y;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i].x), t[c++] = p[i].x;
        sort(t, t + c);
        for (int i = 1; i <= n; ++i) {
            p[i].x = lower_bound(t, t + c, p[i].x) - t + 1;
            p[i].y = lower_bound(t, t + c, p[i].y) - t + 1;
            p[i].id = i;
            f[i] = 1;
        }
        delete t;
        cdq(1, n);
        sort(p + 1, p + n + 1, cmp);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
        for (int i = 1, j = 0; i <= n; ++i)
            if (f[i] == ans && (j == 0 || (p[j].x <= p[i].x && p[i].y <= p[j].y))) {
                printf("%d%c", i, " \n"[(--ans) == 0]);
                j = i;
            }
    }
    return 0;
}