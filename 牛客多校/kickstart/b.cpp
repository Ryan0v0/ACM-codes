//
// Created by 赵婉如 on 2019-07-28.
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
}
const int N=100010;
int h[N],ans[N];
bool dir[N];
int n;
vector<int> vis[N];
int v[N];
int main()
{
    int tt=read();
    F(Case,1,tt){
        n=read();int g=read();int m=read();
        mec(dir,0);mec(v,0);mec(ans,0);
        F(i,1,n) vis[i].clear();
        F(i,1,g){
            h[i]=read();
            vis[h[i]].push_back(i);
            char c=getchar();
            while(c!='A'&&c!='C'){
                c=getchar();
            }
            if(c=='A') dir[i]=true;
            if(c=='C') dir[i]=false;
        }
        //cout<<"!!!"<<endl;
        //F(i,1,g) cout<<dir[i]<<' '<<endl;
        //cout<<endl;
        cout<<"Case #"<<Case<<": ";
        F(tim,1,m){
            F(i,1,g){
                if(!dir[i]) h[i]=(h[i]==n)?1:(h[i]+1);//h[i]%n+1;
                else h[i]=(h[i]==1)?n:(h[i]-1);
                if(v[h[i]]<tim) vis[h[i]].clear();
                vis[h[i]].push_back(i);
                v[h[i]]=tim;
                //cout<<tim<<' '<<i<<' '<<h[i]<<endl;
            }
        }
        F(i,1,n){
            while(!vis[i].empty()){
                //cout<<"***"<<i<<' '<<vis[i][vis[i].size()-1]<<endl;
                ans[vis[i][vis[i].size()-1]]++;
                vis[i].pop_back();
            }
        }
        F(i,1,g){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
/*
4
5 3 2
5 C
2 A
1 A
2 4 0
1 A
1 C
1 A
1 C
3 2 10
3 C
2 A
6 1 6
4 A

 */