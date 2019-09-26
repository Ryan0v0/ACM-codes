//
// Created by 赵婉如 on 2019-08-07.
//

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
}//imitate cmx
const int N=1e5+10;
int n,m;
set<int> sv,se,sv2;
vector<int> g[3*N];
pair<int,int> e[3*N];
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();
        sv.clear();sv2.clear();se.clear();
        F(i,1,3*n) g[i].clear();
        F(i,1,m){
            int x=read();int y=read();
            g[x].push_back(y);
            g[y].push_back(x);
            e[i]={x,y};
        }
        F(i,1,m){
            if(!sv.count(e[i].first) && !sv.count(e[i].second)){
                sv.insert(e[i].first);
                sv.insert(e[i].second);
                se.insert(i);
                if(se.size()==n) break;
            }
        }
        if(se.size()==n){
            puts("Matching");
            for(int j:se) cout<<j<<' ';
            cout<<endl;
        }else{
            puts("IndSet");
            int p=0;
            while(sv2.size()<n){
                sv2.clear();
                sv.clear();
                p++;
                F(i,p,n*3)if(!sv.count(i)){
                    sv2.insert(i);
                    for(int j:g[i]) sv.insert(j);
                    if(sv2.size()==n) break;
                }
            }
            for(int j:sv2) cout<<j<<' ';
            cout<<endl;
        }
    }
    return 0;
}