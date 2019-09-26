//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define INF 1000000000
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

LL ans;
stack<LL> st;
int n, p, q, m;
unsigned int SA, SB, SC;

unsigned int rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

void PUSH(LL x) {
    if (st.size() == 0) st.push(x);
    else if (x > st.top()) st.push(x);
    else st.push(st.top());
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (rng61() % (p + q) < p) PUSH(rng61() % m + 1);
        else {
            if (st.size() >= 1) st.pop();
            else continue;
        }
        if (st.size()) ans ^= i * st.top();
        //cout<<s.top()<<' '<<endl;
    }
}

int main() {
    int tt = read();
    F(Case, 1, tt) {
        cout << "Case #" << Case << ": ";
        while (st.size()) st.pop();
        ans = 0LL;
        scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
        //n=read();p=read();q=read();m=read();SA=read();SB=read();SC=read();
        solve();
        cout << ans << endl;
    }
    return 0;
}