//
// Created by 赵婉如 on 2019-08-23.
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
const int N=500010;
const int Block=710;
LL a[N];
LL ans[Block+10][Block+10];
int main()
{
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    int q=read();
    while(q--){
        int opt=read();int x=read();LL y=read();
        if(opt==1){
            a[x]+=y;
            F(i,1,Block) ans[i][x%i]+=y;
        }else if(opt==2){
            if(x<=Block) cout<<ans[x][y]<<endl;
            else{
                LL sum=0LL;
                for(int i=y;i<=500000;i+=x){
                    sum+=a[i];
                }
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
