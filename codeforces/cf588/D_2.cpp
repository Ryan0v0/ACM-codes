#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<cstring>
typedef long long ll;
using namespace std;
#define N 7010
ll a[N],b[N];
vector<int>G[N];
int ind[N];
int sta[N],top,vis[N],n;
int col[N],num,val[N];//node count
ll cost[N];//sum in scc
int siz[N];//>1:can be added
int dfn[N],low[N],tot;
void tarjan(int p){
	int q;
	low[p]=dfn[p]=++tot;
	sta[++top]=p;vis[p]=1;
	for(auto q:G[p]){
		if(!dfn[q])tarjan(q),low[p]=min(low[p],low[q]);
		else if(vis[q])low[p]=min(low[q],low[p]);
	}
	if(dfn[p]==low[p]){
		num++;
		while(sta[top+1]!=p){
			q=sta[top];
			cost[num]+=b[q];
			col[q]=num;
			vis[q]=0;
			val[num]++;
			top--;
		}
		siz[num]=val[num];
	}
}
ll res=0;
queue<int>Q;
int can[N];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		if(i!=j&&(a[i]|a[j])==a[j])
			G[j].push_back(i);
	for(i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(i=1;i<=n;i++)G[i].clear();
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=j&&(a[i]|a[j])==a[j]){
		int u=col[i],v=col[j];
		if(u!=v) G[v].push_back(u),ind[u]++;
	}
	int temp,CNT=0;
	for(i=1;i<=num;i++)if(!ind[i])Q.push(i);
	while(!Q.empty()){
		int tp=Q.front();Q.pop();
		can[tp]=(siz[tp]>1);
		for(auto q:G[tp]){
			if(can[tp])siz[q]++;
			if(!--ind[q])Q.push(q);
		}
	}
	for(i=1;i<=num;i++)res+=can[i]*cost[i];
	printf("%lld",res);
	return 0;
}

