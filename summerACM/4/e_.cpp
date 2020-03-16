//
// Created by 赵婉如 on 2019-08-13.

//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e5+10,M=2e5+10;
int  n,m,tot=1,head[N];
struct edge{int fro,go,next;LL v;}e[M];
void add(int x,int y,LL v)
{
    e[++tot]=(edge){x,y,head[x],v};head[x]=tot;
    e[++tot]=(edge){y,x,head[y],v};head[y]=tot;
}
int p[N];
int find(int x) { return x==p[x]?x:p[x]=find(p[x]); }
bool notPrime[N],ok[N];
int pri[N],pct=0;
void get_prime()
{
    F(i,2,N) if(!notPrime[i]){
        pri[++pct]=i;
        for(int j=i+i;j<=N;j+=i) notPrime[j]=1;
    }
    F(i,6,N) for(int j=1;pri[j]*pri[j]<i;j++)
        if(i%pri[j]==0 && !notPrime[i/pri[j]]){
            ok[i]=true;
            break;
        }
}
LL ans;
int u[N],v[N],w[N],siz[N];
vector<pair<int,int>> vec;
void init()
{
    tot=0;mec(head,0);ans=0;
    F(i,1,n) siz[i]=1,p[i]=i;
}
void debug()
{
    puts("-----debug-----");
    F(i,1,tot){
        cout<<e[i].fro<<' '<<e[i].go<<' '<<e[i].v<<endl;
    }
    puts("-----debug-----");
}
int main()
{
    get_prime();
    freopen("evaluations.in", "r", stdin);
    freopen("me.txt","w",stdout);
    //cout<<"pct="<<pct<<endl;
    int tt = read();
    F(Case, 1, tt) {
        n = read();
        init();
//        F(i,1,n) cout<<p[i]<<' ';cout<<endl;
//        F(i,1,n) cout<<siz[i]<<' ';cout<<endl;
        F(i, 1, n - 1) {
            u[i] = read();v[i] = read();w[i] = read();
            int fx=find(u[i]),fy=find(v[i]);
            //cout<<"fx="<<fx<<' '<<"fy="<<fy<<endl;
            if(w[i]==1){
                if(fx!=fy){
                    p[fy]=fx;
                    siz[fx]+=siz[fy];
                }
            }
            //add(x, y, w);
        }
        //cout<<"tot="<<tot<<endl;
        //debug();
        F(i,1,n-1){
        //for(int i=1;i<=tot;i+=2){
            //int x=e[i].fro,y=e[i].go;
            int x=u[i],y=v[i];
            int fx=find(x),fy=find(y);
            //cout<<x<<' '<<y<<' '<<fx<<' '<<fy<<endl;
            //cout<<x<<' '<<y<<' '<<fx<<' '<<fy<<' '<<e[i].v<<endl;
            if(fx!=fy){
                add(fx,fy,w[i]);
                if(ok[w[i]]) ans+=1LL*siz[fx]*siz[fy];
            }
        }
        //cout<<"ans="<<ans<<endl;

        //cout<<"ans="<<ans<<endl;
        F(x,1,n){
            vec.clear();
            R(i,x){
                int y=e[i].go;
                int w=e[i].v;
                if(!notPrime[w]) vec.push_back(make_pair(w,y));
                //cout<<y<<' '<<w<<endl;
            }
            //cout<<vec.size()<<endl;
            sort(vec.begin(),vec.end());
            int sum=0;
            for(int j=0,k;j<vec.size();j=k){
                int sum2=0;k=j;
                while(k<vec.size() && vec[k].first==vec[j].first){
                    //cout<<"**"<<vec[k].first<<endl;
                    sum2+=siz[vec[k].second];
                    k++;
                }
                ans+=1LL*sum2*sum;
                sum+=sum2;
                //cout<<x<<' '<<sum2<<' '<<sum<<' '<<ans<<endl;
            }
        }
        cout << "Case " << Case << ": " << ans << endl;
    }
    return 0;
}
/*
1000
3
2 1 1
3 1 10

 */
