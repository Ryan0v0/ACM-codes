//
// Created by 赵婉如 on 2019-09-29.
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
const int N=1e6+10;
LL a[N],b[N],b0[N],b1[N];
bool vis[N];
int n,m;
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case " << Case << ": ";
        n=read();m=read();mec(vis,0);
        mec(b0,0);mec(b1,0);
        F(i,1,n) a[i]=read();
        F(i,1,m) b[i]=read();
        int cnt0=0,cnt1=0;
        F(i,1,m){
            int x=read();
            if(x) b1[++cnt1]=b[i];
            else b0[++cnt0]=b[i];
        }
        sort(a+1,a+n+1);
        sort(b0+1,b0+cnt0+1);
        sort(b1+1,b1+cnt1+1);
        int posa = 1, posb = 1;
        LL ans1=0,ans2=0;
        while (posa <= n && posb <= cnt1) {
            if (b1[posb] <= a[posa]){
                vis[posa] = 1;
                posa++;posb++;
            }
            else posa++;
        }
        if (posb > cnt1) {
            posa = 1, posb = 1;
            while (posa <= n && posb <= cnt0) {
                if (!vis[posa] && b0[posb] <= a[posa]) {
                    vis[posa] = 1;
                    ans1 += a[posa] - b0[posb];
                    posa++; posb++;
                }
                else posa++;
            }
            if (posb > cnt0) {
                F(i,1,n) if(!vis[i]) ans1+=a[i];
            }
            else ans1 = 0;
        } else {
            posa = n, posb = 1;
            while (posa >= 1 && posb <= cnt0) {
                if (a[posa] >= b0[posb]) {
                    ans2 += a[posa] - b0[posb];
                    posa--;
                    posb++;
                }
                else break;
            }
            if (posb <= cnt0) ans2 = 0;
        }
        //cout<<ans1<<' '<<ans2<<endl;
        cout<<max(ans1,ans2)<<endl;
        //printf("Case %d: %d\n", Case, max(ans1, ans2));
    }
    return 0;
}
/*
10
5 4
5 10 10 15 20
2 5 12 18
0 0 1 0
4 2
10 10 10 20
5 15
0 1
4 2
10 10 10 20
5 25
0 1

 */