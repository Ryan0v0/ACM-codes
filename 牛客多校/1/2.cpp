
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
const int N=100;
int n,m;
char s1[N],s2[N];
vector<int> G[N];
int col[N];
int vis[N][N];
int ask[N],matched[N],p[N];

inline bool found(int x){
    for (int i = 1 ; i <= m ; i++)
        if (vis[x][i]){
            if (ask[i])
                continue;
            ask[i] = 1;
            if (!matched[i] || found(matched[i])) {
                matched[i] = x ;
                p[x]=i;
                return true;
            }
        }
    return false;
}
vector<int> s;
vector<int>::iterator iter;
inline void solve(){
    int cnt = 0;//cnt是计数器
    memset(matched,0,sizeof(matched));
    mec(p,-1);s.clear();
    D(i,m,1) s.push_back(i);
    for (int i = 1 ; i <= m ; i++){
        memset(ask,0,sizeof(ask));
        if (found(i)) {
            //cout<<"***"<<i<<' '<<p[i]<<endl;
            cnt++;  //找到了就加1
            //iter=std::find(s.begin(),s.end(),p[i]);
            //s.erase(iter);
        }
    }
    //ans = cnt;
    //F(i,1,m) cout<<"**"<<p[i]<<' ';cout<<endl;
    F(i,1,m){
        if(p[i]!=-1){
            cout<<p[i];
            iter=std::find(s.begin(),s.end(),p[i]);
            s.erase(iter);
        }
        else{
            int tp=s[s.size()-1];
            cout<<tp;
            s.pop_back();
        }
        if(i==m) cout<<endl;
        else cout<<' ';
    }
}
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();
        F(i,1,n) G[i].clear();
        mec(col,-1);mec(vis,0);
        while(n--){
            scanf("%s",s1+1);
            scanf("%s",s2+1);
            //bool ok=0;
            F(i,1,m){
                F(j,1,m){
                    if(s1[i]==s2[j]){
                        vis[i][j]=1;
                        cout<<"!"<<i<<' '<<j<<endl;
                        //col[i]=0;col[j]=0;
                        //G[i].push_back(j);
                        //G[j].push_back(i);
                    }
                }
            }
            solve();
        }
    }
    return 0;
}
/*
4
1 3
abc
bca
2 4
aaab
baaa
cdcc
cccd
3 3
aaa
aaa
bbb
bbb
ccc
ccc
1 1
a
z

 */