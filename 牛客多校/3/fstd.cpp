//
// Created by 赵婉如 on 2019-07-26.
//

#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=510;
const int inf=1000000000;
int a[maxn][maxn],mn[maxn],mx[maxn];
int q1[maxn],q2[maxn],h1,t1,h2,t2,p;
int main()
{
    int T,N,M,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        ans=0;
        rep(i,1,N) rep(j,1,N)
                scanf("%d",&a[i][j]);
        rep(i,1,N) {
            rep(j,1,N) mx[j]=-inf,mn[j]=inf;
            rep(j,i,N) {
                rep(k,1,N) mx[k]=max(mx[k],a[j][k]),mn[k]=min(mn[k],a[j][k]);
                h1=h2=p=0; t1=t2=1;
                rep(k,1,N){
                    while(h1>=t1&&mx[k]>=mx[q1[h1]]) h1--;
                    q1[++h1]=k;
                    while(h2>=t2&&mn[k]<=mn[q2[h2]]) h2--;
                    q2[++h2]=k;
                    while(h1>=t1&&h2>=t2&&mx[q1[t1]]-mn[q2[t2]]>M){
                        p++;
                        if(h1>=t1&&q1[t1]<=p) t1++;
                        if(h2>=t2&&q2[t2]<=p) t2++;
                    }
                    ans=max(ans,(j-i+1)*(k-p));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}