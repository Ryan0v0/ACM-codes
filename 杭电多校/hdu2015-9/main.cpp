#include<bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
	return x*f;
}
const int N=100010;
int n;
int a[N],p[N];
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
//vector<vector<int> > g;//g[x] 权值为x的点的集合
vector<int> g[N];
int main()
{
	int tt=read();
	while(tt--){
		n=read();LL ans=0LL;
		F(i,1,n) a[i]=read();
		F(i,1,n) p[i]=i;
		sort(a+1,a+n+1);
		F(i,1,a[n]) g[i].clear();
		F(i,1,n){
//			cout<<a[i]<<' '<<i<<endl;
			g[a[i]].push_back(i);
//			cout<<"!!!"<<endl;
		}
		/*debug
		F(i,1,n)cout<<a[i]<<' ';cout<<endl;
		F(i,1,n)cout<<g[a[i]].size()<<' ';cout<<endl; */
		bool start=0;
		int x,y;
		D(i,a[n],1){
//			start=0;
//			if(g[i].size()>0) =find(g[i][0]);
			for(int j=1;i*j<=a[n];j++) if(g[i*j].size()>0){x=find(g[i*j][0]);break;}
			for(int j=1;i*j<=a[n];j++) if(g[i*j].size()>0){//if((!start && g[i*j].size()>1)||(start && g[i*j].size()>0)){
//					if(!start) {x=find(g[i*j][0]),start=1;}
					for(int k=0;k<g[i*j].size();k++){
						y=find(g[i*j][k]);
						if(x!=y) {
//							cout<<x<<"**"<<a[x]<<" & "<<g[i*j][k]<<"**"<<a[y]<<"|"<<g[i*j].size()<<endl;
							ans+=(LL)i;
							p[y]=x;
						}
					}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}