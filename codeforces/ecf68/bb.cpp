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
char str[50010];
int a[500010];
int b[50010];
int c[50010];
int main()
{
    int q=read();
    while(q--) {
        int ans=1000000000;
        int n = read();
        int m = read();
        mec(b,0);
        mec(c,0);
        F(i, 1, n){
            scanf("%s",str+1);
            F(j,1,strlen(str+1)){
                a[i*m+j]=0;
                if(str[j]=='*'){
                    a[i*m+j]=1;
                }
            }
        }
        F(i,1,n) F(j,1,m) b[i]+=a[i*m+j];//hang
        F(i,1,m) F(j,1,n) c[i]+=a[j*m+i];//lie
        F(i,1,n) F(j,1,m){
                if(a[i*m+j]==1){
                    ans=min(ans,m+n-1-(b[i]+c[j]-1));
                }else{
                    ans=min(ans,m+n-1-(b[i]+c[j]));
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}