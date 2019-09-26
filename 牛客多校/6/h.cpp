//
// Created by 赵婉如 on 2019-08-04.
//

#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;
int n,m,cnt,h[100007],sizeA,sizeB,A[27],B[27];
int disA[27][100007],disB[27][100007];
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
struct node {
    int to,ne;
}edge[200007];
void add(int x,int y) {
    edge[++cnt].to = y;
    edge[cnt].ne = h[x];
    h[x] = cnt;
    return;
}
//priority_queue<pair<int,int> >q;
queue <int> q;
void dijkstra(int s,int dis[]) {
    for(int i = 1; i <= n;i++) {
        dis[i] = 0x3f3f3f3f;
    }
    dis[s] = 0;
    q.push(s);

    while(!q.empty()){
        int tp = q.front();
        q.pop();

        for(int i = h[tp];i;i = edge[i].ne) {
            int to = edge[i].to;
            if(dis[tp] + 1 < dis[to]) {
                dis[to] = dis[tp] + 1;
                q.push(to);
            }
        }
    }

    return;
}

queue<int>que;
ll val[100007];
bool vis[100007];
ll calc(int a,int b) {
    for(int i = 1; i <= n;i++)  {
        val[i] = disA[a][i] + disB[b][i];
        vis[i] = true;
        que.push(i);
    }

    while(!que.empty()) {
        int tp = que.front();
        que.pop();
        vis[tp] = false;
        for(int i = h[tp] ;i;i =edge[i].ne) {
            int to = edge[i].to;
            if(val[to] > val[tp] + 1) {
                val[to] = val[tp] + 1;
                if(!vis[to]){
                    que.push(to);
                    vis[to] = true;
                }
            }
        }
    }
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        res += val[i];
    }
    return res;
}

void work(int Case) {
    n = read();
    m = read();
    cnt = 0;
    memset(h,0,sizeof(h));
    for(int i = 1,x,y; i <= m;i++) {
        x = read();
        y = read();
        add(x,y); add(y,x);
    }
    sizeA = read();
    for(int i = 1; i <= sizeA;i++) A[i] = read();
    sizeB = read();
    for(int i = 1; i <= sizeB;i++) B[i] = read();
    for(int i = 1;i <= sizeA;i++) dijkstra(A[i],disA[i]);
    for(int i = 1;i <= sizeB;i++) dijkstra(B[i],disB[i]);
    ll ans = 0;
    for(int i = 1; i <= sizeA; i++) {
        for(int j = 1; j <= sizeB;j++) {
            ans += calc(i,j);
        }
    }
    ll G = 1ll * sizeA * sizeB * n;
    if(__gcd(G,ans) == G) printf("Case #%d: %lld\n",Case,ans/__gcd(ans,G));
    else printf("Case #%d: %lld/%lld\n",Case,ans/__gcd(ans,G),G/__gcd(ans,G));
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1 ;i <= t;i++) {
        work(i);
    }
    return 0;
}