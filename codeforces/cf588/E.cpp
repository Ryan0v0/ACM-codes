#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<unordered_map>
#include<vector>
typedef long long ll;
using namespace std;
#define N 100010
int n;
ll x[N];
struct Edge{
	int e,n;
}e[N<<1];
int hd[N],cnt;
void add(int a,int b){
	e[++cnt].e=b;e[cnt].n=hd[a];hd[a]=cnt;
}
map<ll,int>S[N];
ll res;
ll xgcd(ll a,ll b){
	if(!a)return b;
	if(!b)return a;
	return  __gcd(a,b);
}
ll mod=1000000007;
void dfs(int p,int fa){
	int i;
	S[p][x[p]]++;
	for(auto j:S[p])(res+=j.second*(j.first%mod)%mod)%=mod;
	for(i=hd[p];i;i=e[i].n){
		int q=e[i].e;
		if(q==fa)continue;
		for(auto j:S[p])S[q][xgcd(j.first,x[q])]+=j.second;
		dfs(q,p);
	}
}
int main(){
	int i,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,0);
	printf("%lld\n",res%mod);
	return 0;
}
