//
// Created by 赵婉如 on 2019-08-27.
//

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<bitset>
#pragma comment(linker, "/STACK:1024000000,1024000000")
template <class T>
bool scanff(T &ret){ //Faster Input
    char c; int sgn; T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n'){ ret*=sgn; return 1; }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}
#define inf 1073741823
#define llinf 4611686018427387903LL
#define PI acos(-1.0)
#define lth (th<<1)
#define rth (th<<1|1)
#define rep(i,a,b) for(int i=int(a);i<=int(b);i++)
#define drep(i,a,b) for(int i=int(a);i>=int(b);i--)
#define gson(i,root) for(int i=ptx[root];~i;i=ed[i].next)
#define tdata int testnum;scanff(testnum);for(int cas=1;cas<=testnum;cas++)
#define mem(x,val) memset(x,val,sizeof(x))
#define mkp(a,b) make_pair(a,b)
#define findx(x) lower_bound(b+1,b+1+bn,x)-b
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define NN 100100

struct node{
    double x,y;
}a[NN];

int n;
double len[NN];
double r[NN];
double caldis(int x,int y){
    return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
double cal(int idx,double lx){
    double temp=lx;
    double s=0.0;
    rep(i,1,n){
        s+=lx*lx;
        r[idx]=lx;
        if(lx<0.0||lx>len[idx]||lx>len[idx==1?n:idx-1])return -1.0;
        lx=len[idx]-lx;
        idx++;
        if(idx>n)idx=1;
    }
    if(fabs(temp-lx)>1e-7)return -1.0;
    return s;
}
int main(){
    tdata{
        scanff(n);
        rep(i,1,n){
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        rep(i,1,n){
            if(i!=n)len[i]=caldis(i,i+1);
            else len[i]=caldis(i,1);
        }
        int idx;
        if(n&1){
            double lenx=0.0;
            idx=1;
            rep(i,1,n){
                if(i&1)lenx+=len[idx];
                else lenx-=len[idx];
                idx++;
                if(idx>n)idx=1;
            }
            lenx/=2.0;
            double ans=cal(1,lenx);
            if(ans>=0.0){
                printf("%.2f\n",ans*PI);
                rep(i,1,n){
                    printf("%.2f\n",r[i]);
                }
            }
            else printf("IMPOSSIBLE\n");
        }
        else{

            double lx=0.0,rx=len[1],t=0.0;
            idx=1;
            rep(i,1,n){
                t=len[idx]-t;
                if(i&1)rx=min(rx,t);
                else lx=max(lx,-t);
                idx++;
                if(idx>n)idx=1;
            }
            if(lx>rx){
                printf("IMPOSSIBLE\n");
                continue;
            }
            rep(i,1,250){
                double d=(rx-lx)/3.0;
                double d1=lx+d;
                double d2=rx-d;
                if(cal(1,d1)<cal(1,d2))rx=d2;
                else lx=d1;
            }
            double ans=cal(1,lx);
            if(ans<0.0){
                printf("IMPOSSIBLE\n");
                continue;
            }
            printf("%.2f\n",ans*PI);
            rep(i,1,n){
                printf("%.2f\n",r[i]);
            }
        }
    }
    return 0;
}
/*
100
5
6 5
1 4
8 1
9 4
1 4

 */