//
// Created by 赵婉如 on 2019-08-31.
//

#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAXN=211;

int rob[211];
int d[211][211][211];
int id[211];

bool cmp(int i,int j){
    return rob[i]<rob[j];
}

int main(){
    int Tests;
    scanf("%d",&Tests);
    for(int cntT=1;cntT<=Tests;++cntT){
        memset(d,INF,sizeof(d));
        int N,Q;
        scanf("%d%d",&N,&Q);
        for(int i=1;i<=N;++i){
            id[i]=i;
            scanf("%d",&rob[i]);
        }
        sort(id+1,id+N+1,cmp);

        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                scanf("%d",&d[0][i][j]);
        for(int k=1;k<=N;++k){
            int rk=id[k];
            for(int i=1;i<=N;++i)
                for(int j=1;j<=N;++j) {
                    d[k][i][j]=min(d[k-1][i][j],d[k-1][i][rk]+d[k-1][rk][j]);
                }
        }
        printf("Case #%d:\n",cntT);
        for(int q=1;q<=Q;++q){
            int u,v,dan;
            scanf("%d%d%d",&u,&v,&dan);
            int k=0;
            for(int i=1;i<=N;++i)
                if(rob[id[i]]<=dan) k=i;
            printf("%d\n",d[k][u][v]);
        }
    }
    return 0;
}