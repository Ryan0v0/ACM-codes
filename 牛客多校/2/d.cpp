//
// Created by 赵婉如 on 2019-07-20.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
//#include <ext/pb_ds/priority_queue.hpp>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define max(a,b) ((a)<(b)?(b):(a))
#define swap(a,b) a^=b^=a^=b
#define lb(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f3f3f3f3fll
int n,m,S,T,k;
struct Dinic{
    static const int N=55,M=3050;
    int cnt,head[N],nxt[M],to[M],d[N],cur[N],q[N],l,r;
    LL cap[M];
    Dinic(){cnt=1;}
    inline void add(int a,int b,int c){
        to[++cnt]=b,cap[cnt]=c,nxt[cnt]=head[a],head[a]=cnt;
        to[++cnt]=a,cap[cnt]=0,nxt[cnt]=head[b],head[b]=cnt;
    }
    inline bool bfs(int s,int t){
        mset(d,-1),l=0,r=-1;
        q[++r]=s,d[s]=0;
        while(l<=r){
            int he=q[l++];
            for(int i=head[he];i;i=nxt[i])
                if(cap[i]>0&&d[to[i]]<0)q[++r]=to[i],d[to[i]]=d[he]+1;
        }
        return d[t]>=0;
    }
    inline LL dfs(int t,int x,LL a){
        if(x==t||a==0)return a;
        LL ret=0,f;
        for(int i=cur[x];i;i=nxt[i])
            if(d[to[i]]==d[x]+1&&cap[i]>0){
                f=dfs(t,to[i],min(a,cap[i]));
                if(!f){d[to[i]]=-1;continue;}
                cap[i]-=f,cap[i^1]+=f,ret+=f,a-=f;
                if(!a)return ret;
            }
        return ret;
    }
    inline LL dinic(int s,int t){
        if(s==t)return inf;
        LL ret=0;
        while(bfs(s,t)){
            mcpy(cur,head),ret+=dfs(t,s,inf);
            if(ret>inf)return ret;
        }
        return ret;
    }
}g,t1,t2;
namespace solve3{
    const int N=55,M=1505;
    int a[M],b[M],c[M],no[M];
    LL d1[N],d2[N];
    bool vis1[N],vis2[N];
    struct data{
        LL v,mi;
        int pos;
        bool s1[M],s2[M];
        bool operator <(const data& b)const{return v>b.v;}
        inline void build(){
            v=0,t1=g,mset(vis1,0),mset(vis2,0),mi=inf,pos=0;
            for(int i=1;i<=m;i++)
                if(s1[i])v+=c[i],t1.cap[no[i]]=t1.cap[no[i]-1]=0;
                else if(s2[i])t1.cap[no[i]-1]=inf,t1.cap[no[i]]=0;
            v+=t1.dinic(S,T),t1.bfs(S,T);
            for(int i=1;i<=m;i++)if(!s1[i]&&!s2[i]){
                    if(t1.d[a[i]]>=0&&t1.d[b[i]]<0){
                        if(!vis1[a[i]])vis1[a[i]]=1,t2=t1,d1[a[i]]=t2.dinic(S,a[i]);
                        if(!vis2[b[i]])vis2[b[i]]=1,t2=t1,d2[b[i]]=t2.dinic(b[i],T);
                        if(d1[a[i]]<mi)mi=d1[a[pos=i]];
                        if(d2[b[i]]<mi)mi=d2[b[pos=i]];
                    }else if(c[i]<mi)mi=c[pos=i];
                }
            v+=mi;
        }
    }x,y;
//	struct cmp{bool operator ()(const data& a,const data& b)const{return a.v>b.v;};};
    priority_queue<data> q;
    inline void main(){
        //for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]),g.add(a[i],b[i],c[i]),no[i]=g.cnt;
        n=read();k=read();
        S=0;T=2*n+1;
        F(i,1,n){
            int val=read();
            if(val>=0){
                g.add(S,i,val);
            }else{
                g.add(i+n,T,-val);
            }
        }
        F(i,1,n) {
            F(j,1,n) {
                int xx = read();
                if (xx) g.add(i, n + j, 1);
            }
        }
        k--,t1=g,printf("%lld\n",t1.dinic(S,T));
//		printf("%d\n",g.dinic(S,T));return;
        x.build();if(x.v<inf)q.push(x);
        while(k&&!q.empty()){
            x=y=q.top();q.pop();
            printf("%lld\n",x.v);
            x.s1[x.pos]=1,x.build();if(x.v<inf)q.push(x);
            y.s2[y.pos]=1,y.build();if(y.v<inf)q.push(y);
            k--;
        }
        if(k)puts("-1");
    }
}
int main(){
    solve3::main();
    return 0;
}