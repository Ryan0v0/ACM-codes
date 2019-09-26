//
// Created by 赵婉如 on 2019-08-10.
//

const int maxn = 1e4 + 5;
int a[maxn];
struct node {
    int fa, son[2], sz, val, lazy;
    void init() {
        sz = 1; lazy = 0;
        fa = son[0] = son[1] = 0;
    }
}t[maxn];
bool nroot(int x) {
    return t[t[x].fa].son[0] == x || t[t[x].fa].son[1] == x;
}
void pushup(int x) {
    t[x].sz = 1;
    int l = t[x].son[0], r = t[x].son[1];
    if(l) t[x].sz += t[l].sz;
    if(r) t[x].sz += t[r].sz;
}
void pushdown(int x) {
    if(t[x].lazy) {
        t[x].lazy = 0;
        swap(t[x].son[0], t[x].son[1]);
        t[t[x].son[0]].lazy ^= 1;
        t[t[x].son[1]].lazy ^= 1;
    }
}
void rot(int x) {
    int fa = t[x].fa, gfa = t[t[x].fa].fa;
    int k = (x == t[fa].son[1]);
    t[fa].son[k] = t[x].son[k^1];
    if(nroot(fa)) t[gfa].son[fa == t[gfa].son[1]] = x;
    if(t[x].son[k^1]) t[t[x].son[k^1]].fa = fa;
    t[x].son[k^1] = fa;
    t[fa].fa = x; t[x].fa = gfa;
    pushup(fa);
}
int stk[maxn], top;
void splay(int x) {
    top = 0; stk[++top] = x;
    for(int i = x ; nroot(i) ; i = t[i].fa) {
        stk[++top] = t[i].fa;
    }
    while(top) pushdown(stk[top--]);
    for(int fa ; nroot(x) ; rot(x)) {
        if(nroot(fa = t[x].fa))
            rot((t[x].son[0] == x) ^ (t[fa].son[0] == fa) ? fa : x);
    }
    pushup(x);
}
int access(int x) {
    int i;
    for(i = 0 ; x ; x = t[i = x].fa) {
        splay(x); t[x].son[1] = i;
        if (i) t[i].fa = x; pushup(x);
    }
    return i;
}
int lca(int x, int y) {
    access(x); return access(y);
}
void makeroot(int x){
    access(x); splay(x); t[x].lazy ^= 1;
}
int findroot(int x) {
    access(x); splay(x);
    while(t[x].son[0]) pushdown(x), x = t[x].son[0];
    return x;
}
void split(int x, int y) {
    makeroot(x); access(y); splay(y);
}
void link(int x, int y) {
    makeroot(x);
    if(findroot(y) != x) t[x].fa = y;
}
void cut(int x, int y) {
    makeroot(x);
    if(findroot(y) == x && t[x].fa == y && !t[x].son[1]){
        t[x].fa = t[y].son[0] = 0;
        pushup(y);
    }
}
int query(int x, int y) {
    split(x, y);
    return t[y].sz;
}
void solve() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1 ; i <= n ; i ++) {
        t[i].init();
    }
    while(q--) {
        char op[10]; int x, y;
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'C') link(x, y);
        else if (op[0] == 'D') cut(x, y);
        else {
            printf("%s\n", findroot(y) == findroot(x) ? "Yes": "No");
        }
    }
}