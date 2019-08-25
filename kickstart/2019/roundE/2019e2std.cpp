//
// Created by 赵婉如 on 2019-08-25.
//

#include <algorithm>
#include <cstdio>
struct node {
    int a, b, id;
    double rest;
} A[100005], B[100005];
int T, n, m, cas = 0, ans[100005];

bool cmp1(const node &x, const node &y) {
    return (long long) x.b * y.a > (long long) y.b * x.a;
}
bool cmp2(const node &x, const node &y) {
    return x.a > y.a;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d", &m, &n);
        long long totA = 0;
        double totB = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &A[i].a, &A[i].b);
            A[i].rest = 1;
            totA += A[i].a;
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &B[i].a, &B[i].b);
            B[i].id = i;
        }
        std::sort(A + 1, A + n + 1, cmp1);
        std::sort(B + 1, B + m + 1, cmp2);

        for (int i = 1, j = 1; j <= m; ++j) {
            while (i <= n && totA > B[j].a) {
                long long det = totA - B[j].a;
                if (det >= A[i].a * A[i].rest) {
                    totA -= A[i].a * A[i].rest;
                    totB += A[i].b * A[i].rest;
                    ++i;
                } else {
                    A[i].rest -= (double) det / A[i].a;
                    totA -= det;
                    totB += A[i].b * ((double) det / A[i].a);
                }
            }
            ans[B[j].id] = (totA >= B[j].a && totB >= B[j].b);
        }

        printf("Case #%d: ", ++cas);
        for (int i = 1; i <= m; ++i)
            printf(ans[i] ? "Y" : "N");
        printf("\n");
    }
}