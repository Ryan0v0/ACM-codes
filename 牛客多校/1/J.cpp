//
// Created by 赵婉如 on 2019-08-18.
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
const int N=10010;
double sx,sy,fx,fy;
double xx,yy;
int t[N];
double wx[N],wy[N];
int main()
{
    freopen("joy.in","r",stdin);
    freopen("joy.out","w",stdout);
    scanf("%lf%lf%lf%lf",&sx,&sy,&fx,&fy);
    int n=read();int k=read();double vm,v;scanf("%lf",&vm);
    int pos=0;
    F(i,1,n){
        t[i]=read();
        double wxx,wyy;
        scanf("%lf%lf",&wxx,&wyy);
        //xx+=(double)(t[i]-t[i-1])*wxx;
        //yy+=(double)(t[i]-t[i-1])*wyy;
        F(j,pos+1,t[i]-1) wx[j]=wx[pos],wy[j]=wy[pos];
        wx[t[i]]=wxx;
        wy[t[i]]=wyy;
        pos=t[i];
    }
    //F(i,0,k-1) cout<<wx[i]<<' ';cout<<endl;
    //F(i,0,k-1) cout<<wy[i]<<' ';cout<<endl;
    xx=0;yy=0;
    F(i,0,k-1){
        xx+=wx[i];
        yy+=wy[i];
    }
    double nx=(fabs(fx-sx)-xx<0)?0:fabs(fx-sx)-xx;
    //cout<<"!!!"<<fy<<' '<<sy<<' '<<yy<<endl;
    double ny=(fabs(fy-sy)-yy<0)?0:fabs(fy-sy)-yy;
    double tmp=vm*(double)k;
    if(tmp*tmp<nx*nx+ny*ny) {
        puts("No");
        return 0;
    }
    puts("Yes");
    double len=sqrt(nx*nx+ny*ny);
    v=len/(double)k;
    //cout<<nx<<' '<<ny<<' '<<nx*nx+ny*ny<<' '<<len<<endl;
    double vx=v/len*nx;
    double vy=v/len*ny;
    double nowx=sx;double nowy=sy;
    F(i,0,k-1){
        //cout<<i<<' '<<nowy<<endl;
        if(fx<sx) {
            nowx -= (wx[i] + vx);
            printf("%.10lf ", max(nowx, fx));
        }else {
            nowx+=wx[i]+vx;
            printf("%.10lf ", min(nowx, fx));
        }
        if(fy<sy){
            nowy-=(wy[i]+vy);
            printf("%.10lf\n", max(nowy, fy));
        }
        else {
            nowy+=wy[i]+vy;
            printf("%.10lf\n", min(nowy, fy));
        }
        //printf("%.10lf %.10lf\n",min(sx,fx),min(sy,fy));
        //cout<<sx<<' '<<sy<<endl;
    }
    return 0;
}
/*
1 1 7 4
2 3 10
0 1 2
2 2 0

7 4 1 1
2 3 10
0 1 2
2 2 0

7 4 -1 -2
2 3 10
0 1 2
2 2 0

 */