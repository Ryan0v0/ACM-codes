//
// Created by 赵婉如 on 2019-08-24.
//


#include <bits/stdc++.h>
using namespace std;

int X[500010];
int S[500010];
long long sum[500010];
const long long INF = 1e17;

int main() {
    int T;
    int iCase = 0;
    scanf("%d", &T);
    while (T--) {
        iCase++;
        int N, O;
        long long D;
        scanf("%d%d%lld", &N, &O, &D);
        int A, B, C, M, L;
        scanf("%d%d%d%d%d%d%d", &X[1], &X[2], &A, &B, &C, &M, &L);
        for (int i = 3; i <= N; i++) {
            X[i] = ((long long)A * X[i-1] + (long long)B * X[i-2] + C) % M;
        }
        for (int i = 1; i <= N; i++) {
            S[i] = X[i] + L;
        }
        sum[0] = 0;
        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i-1] + S[i];
        }

        int r = 1;
        int on = 0;
        multiset<long long> mt;
        long long ans =  -INF;
        for (int i = 1; i <= N; i++) {
            while (r <= N && on + (S[r]&1) <= O) {
                mt.insert(sum[r]);
                on += (S[r++]&1);
            }

            if (r <= i) {
                r = i+1;
            } else {
                multiset<long long>::iterator it = mt.lower_bound(D+sum[i-1]+1);
                if (it != mt.begin()) {
                    it--;
                    ans = max(ans, (*it) - sum[i-1]);
                }
                mt.erase(mt.find(sum[i]));
                on -= (S[i]&1);
            }
        }
        if (ans == -INF) {
            printf("Case #%d: IMPOSSIBLE\n", iCase);
        } else {
            printf("Case #%d: %lld\n", iCase, ans);
        }
    }
    return 0;
}