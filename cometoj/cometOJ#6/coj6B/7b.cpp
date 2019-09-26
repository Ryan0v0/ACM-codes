//
// Created by 赵婉如 on 2019-07-17.
//

#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
    x = 0; int f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

int a, b, c, d;
int ans = 100;

bool check(){
    if(a < b && b < c && c < d) return true;
    if(b < c && c < d && d < a) return true;
    if(c < d && d < a && a < b) return true;
    if(d < a && a < b && b < c) return true;
    return false;
}

void dfs(int u){
    if(u == 10) return ;
    if(check()) return (void) (ans = min(ans, u));
    swap(a, d), dfs(u + 1), swap(a, d);
    swap(a, b), dfs(u + 1), swap(a, b);
    swap(b, c), dfs(u + 1), swap(b, c);
    swap(c, d), dfs(u + 1), swap(c, d);
}

int main(){
    rd(a), rd(b), rd(c), rd(d);
    dfs(0);
    printf("%d\n", ans);
    return 0;
}