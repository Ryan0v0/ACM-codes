//
// Created by 赵婉如 on 2019-08-05.
//

#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=50010;
int q[maxn],Mx[maxn],x[maxn],y[maxn],b[maxn],tot,ans[maxn],res;
bool cmp(int w,int v){ if(y[w]==y[v]) return w<v;return y[w]<y[v];}
int query(int x){int res=0; while(x){ res=max(res,Mx[x]);x-=(-x)&x;} return res;}
void add(int x,int y){while(x<=tot){ Mx[x]=max(y,Mx[x]);x+=(-x)&x; }}
void update(int x){while(x<=tot){ Mx[x]=0;x+=(-x)&x;}}
void cdq(int L,int R)
{

    if(L==R) { ans[L]=max(ans[L],1); return ;}
    int Mid=(L+R)>>1;
    cdq(Mid+1,R);
    int num=0; rep(i,L,R) q[++num]=i;
    sort(q+1,q+num+1,cmp);
    for(int i=num;i>=1;i--){
        if(q[i]>Mid) add(x[q[i]],ans[q[i]]);
        else ans[q[i]]=max(ans[q[i]],query(x[q[i]])+1);
    }
    for(int i=num;i>=1;i--)
        if(q[i]>Mid) update(x[q[i]]);
    cdq(L,Mid);
}
int main()
{
    int N;
    while(~scanf("%d",&N)){
        rep(i,1,N) Mx[i]=ans[i]=0; res=0;
        rep(i,1,N) scanf("%d",&x[i]),b[i]=x[i];
        rep(i,1,N) scanf("%d",&y[i]);
        sort(b+1,b+N+1);
        tot=unique(b+1,b+N+1)-(b+1);
        rep(i,1,N) x[i]=lower_bound(b+1,b+tot+1,x[i])-b;
        cdq(1,N);
        rep(i,1,N) res=max(res,ans[i]);
        printf("%d\n",res);
        int X,Y; tot=res;
        rep(i,1,N){
            if(ans[i]==tot){
                if(tot==res) {
                    X=x[i]; Y=y[i]; tot--;
                    printf("%d",i);
                }
                else if(x[i]<=X&&y[i]>=Y){
                    X=x[i]; Y=y[i]; tot--;
                    printf(" %d",i);
                }
            }
        }
        puts("");
    }
    return 0;
}