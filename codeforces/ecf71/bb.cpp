#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
using namespace std;
int g[100][100];
int f[100][100];
bool flag;
vector<pair<int,int>> v;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);flag=1;
    int cnt=0;
    F(i,1,n){
        F(j,1,m){
            scanf("%d",&g[i][j]);
            if(g[i][j]) cnt++;
        }
    }
    F(i,1,n-1) F(j,1,m-1){
        if(g[i][j]==1&&g[i+1][j]==1&&g[i][j+1]==1&&g[i+1][j+1]==1){
            f[i][j]=1;f[i+1][j]=1;f[i][j+1]=1;f[i+1][j+1]=1;
            //flag=1;
            v.push_back(make_pair(i,j));
        }
    }
    F(i,1,n) F(j,1,m){
        if(f[i][j]!=g[i][j]){
            flag=0;
            break;
        }
    }
    if(!flag){
        puts("-1");
    }else{
        cout<<v.size()<<endl;
        if(v.size()!=0) F(i,0,v.size()-1) cout<<v[i].first<<' '<<v[i].second<<endl;
    }
    return 0;
}
/*
3 4
0 1 0 0
0 0 0 0
0 0 0 0

 */