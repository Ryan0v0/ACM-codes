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
ll res=0;
struct p{
	ll a,b;
	bool operator<(const p&P)const{return a<P.a;}
}a[7070];
set<ll>st;
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lld",&a[i].a);
	for(i=0;i<n;i++)scanf("%lld",&a[i].b);
	sort(a,a+n);
	int r=0;
	for(i=0;i<n;i=r){
		r=i;
		ll tmp=0;
		while(r<n&&a[i].a==a[r].a)tmp+=a[r].b,r++;
		if(r>i+1)res+=tmp,st.insert(a[i].a);
	}
	for(i=0;i<n;i++){
		if(st.count(a[i].a)==0){
			for(auto j:st){
				if((a[i].a|j)==j){
					res+=a[i].b;
					break;
				}
			}
		}
	}
	printf("%lld",res);
	return 0;
}
