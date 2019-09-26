#include <sstream>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
#include <cassert>
#include <bitset>

using namespace std;
#define REP(I, N) for (I=0;I<N;I++)
#define rREP(I, N) for (I=N-1;I>=0;I--)
#define rep(I, S, N) for (I=S;I<N;I++)
#define rrep(I, S, N) for (I=N-1;I>=S;I--)
#define FOR(I, S, N) for (I=S;I<=N;I++)
#define rFOR(I, S, N) for (I=N;I>=S;I--)

#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define deputs(str) fprintf(stderr, "%s\n",str)
#else
#define debug(...)
#define deputs(str)
#endif // DEBUG
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
const LL M = 1e9 + 7;
const LL maxn = 5e2 + 107;
const double pi = acos(-1.0);
const double eps = 0.0000000001;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

template<typename T>
inline void pr2(T x, int k = 64) {
    ll i;
    REP(i, k) debug("%d", (x >> i) & 1);
    putchar(' ');
}

template<typename T>
inline void add_(T &A, int B, ll MOD = M) {
    A += B;
    (A >= MOD) && (A -= MOD);
}

template<typename T>
inline void mul_(T &A, ll B, ll MOD = M) { A = (A * B) % MOD; }

template<typename T>
inline void mod_(T &A, ll MOD = M) {
    A %= MOD;
    A += MOD;
    A %= MOD;
}

template<typename T>
inline void max_(T &A, T B) { (A < B) && (A = B); }

template<typename T>
inline void min_(T &A, T B) { (A > B) && (A = B); }

template<typename T>
inline T abs(T a) { return a > 0 ? a : -a; }

inline ll powMM(ll a, ll b, ll mod = M) {
    ll ret = 1;
    for (; b; b >>= 1ll, a = a * a % mod)
        if (b & 1) ret = ret * a % mod;
    return ret;
}

int startTime;

void startTimer() { startTime = clock(); }

void printTimer() { debug("/--- Time: %ld milliseconds ---/\n", clock() - startTime); }


namespace T_SAT {
    const static int maxn = 1e3 + 7;

    struct enode {
        int to, next;

        enode(int _to = 0, int _next = -1) : to(_to), next(_next) {};
    } edge[maxn * maxn * 3 / 2];

    int head[maxn], etot;

    void addedge(int u, int v) {
        edge[++etot] = enode(v, head[u]);
        head[u] = etot;
    }

    int dfn[maxn], low[maxn], belong[maxn];
    bool vis[maxn];
    int tot, cnt;
    int S[maxn], top;

    void dfs(int x) {
        dfn[x] = low[x] = ++tot;
        S[++top] = x;
        vis[x] = 1;
        for (int i = head[x]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (!dfn[v]) {
                dfs(v);
                low[x] = min(low[x], low[v]);
            } else if (vis[v])
                low[x] = min(low[x], dfn[v]);
        }
        if (dfn[x] == low[x]) {
            cnt++;
            while (1) {
                int now = S[top--];
                vis[now] = 0;
                belong[now] = cnt;
                if (now == x) break;
            }
        }
    }

    void init(int n) {
        memset(head, -1, sizeof(int) * n * 2);
        etot = 0;
    }

    void solve(int n) {
        int i;
        tot = cnt = 0;
        REP(i, n) dfn[i] = vis[i] = 0;
        REP(i, n) if (!dfn[i]) dfs(i);
    }
}
int A[maxn][maxn];
int val[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int i, j, k;
        REP(i, n) REP(j, n) {
                scanf("%d", &A[i][j]);
            }
        bool okay = 1;
        REP(i, n) val[i] = 0;
        REP(k, 31) {
            if (!okay) continue;//no use
            T_SAT::init(n);
            REP(i, n) REP(j, n) {
                    if (i == j && A[i][j]) okay = false;
                    if (i <= j) continue;//i<=j
                    int now = (A[i][j] >> k) & 1;
                    if ((i & 1) && (j & 1)) {//or
                        if (now) {
                            T_SAT::addedge(i + n, j);
                            T_SAT::addedge(j + n, i);
                        } else {
                            T_SAT::addedge(i, i + n);
                            T_SAT::addedge(j, j + n);
                        }
                    } else if (!(i & 1) && !(j & 1)) {//and
                        if (now) {
                            T_SAT::addedge(i + n, i);
                            T_SAT::addedge(j + n, j);
                        } else {
                            T_SAT::addedge(i, j + n);
                            T_SAT::addedge(j, i + n);
                        }
                    } else {
                        if (now) {
                            T_SAT::addedge(i, j + n);
                            T_SAT::addedge(j, i + n);
                            T_SAT::addedge(i + n, j);
                            T_SAT::addedge(j + n, i);
                        } else {
                            T_SAT::addedge(i, j);
                            T_SAT::addedge(j, i);
                            T_SAT::addedge(i + n, j + n);
                            T_SAT::addedge(j + n, i + n);
                        }
                    }
                }
            T_SAT::solve(n * 2);
            REP(i, n) val[i] |= (T_SAT::belong[i] < T_SAT::belong[i + n]) << k;
            REP(i, n) if (T_SAT::belong[i] == T_SAT::belong[i + n]) okay = false;
            // printf("%d : %d\n",k,okay);
        }
        if (!okay) puts("NO");
        else {
            puts("YES");
            // REP(i,n) printf("%d%c",val[i]," \n"[i==n-1]);
        }
    }
}
