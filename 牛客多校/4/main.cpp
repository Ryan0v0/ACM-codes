#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
#define mak(a,b) make_pair(a,b)
#define pii pair<int,pair<int,int> >
const int N=10000+2;
const int M=50000+2;
int tot,K,s,t,n,m;
int head[N];LL d[N][11];
struct Edge{int to;LL len;int nex;}edge[M*2];
priority_queue<pii,vector<pii>,greater<pii> >q;
void add(int from,int to,LL len)
{
    edge[++tot]=(Edge){to,len,head[from]};head[from]=tot;
    edge[++tot]=(Edge){from,len,head[to]};head[to]=tot;
}
void dij()
{
    while(!q.empty()) q.pop();
    //mec(d,INF);
    F(i,0,n) d[i][0]=INF;//cout<<d[i][0]<<endl;
    q.push(mak(0,mak(s,0)));
    d[s][0]=0;
    F(i,0,n-1) cout<<d[i][0]<<endl;
    while(!q.empty())
    {
        int x=q.top().second.first,k=q.top().second.second;
        q.pop();
        for(int i=head[x];i;i=edge[i].nex)
        {
            int y=edge[i].to,l=edge[i].len;
            if(d[x][k]+l<d[y][k])
            {
                d[y][k]=d[x][k]+l;
                q.push(mak(d[y][k],mak(y,k)));
            }
            if(k+1<=K&&d[x][k]<d[y][k+1])
            {
                d[y][k+1]=d[x][k];
                q.push(mak(d[y][k+1],mak(y,k+1)));
            }
            //cout<<d[y][k]<<endll
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&K);
    while(m--){
        int from,to,len;
        scanf("%d%d%d",&from,&to,&len);
        add(from,to,len);
    }
    dij();
    LL ans=INF;
    //F(i,0,n-1) cout<<d[i][0]<<endl;
    for(int i=0;i<=K;i++){
        //cout<<"ans="<<ans<<' '<<d[t][i]<<endl;
        cout<<t<<' '<<i<<' '<<d[t][i]<<endl;
        ans=min(ans,d[t][i]);
    }
    printf("%lld\n",ans);
}