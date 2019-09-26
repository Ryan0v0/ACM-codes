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
char s[N];
int a[N];
int b[2*N];
int sum;
int cnt1,cnt2;
int ans;
int main()
{
    int n=read();
    mec(b,-1);b[n]=0;
    scanf("%s",s+1);
    F(i,1,n){
        a[i]=s[i]-'0';
        if(a[i]==0){
            a[i]=-1;
            cnt1++;
        }
        else cnt2++;
        sum+=a[i];
        //cout<<sum<<' ';
        if(b[sum+n]==-1){
            b[sum+n]=i;
        }else{
            ans=max(ans,i-b[sum+n]);
        }
    }//cout<<endl;
    //F(i,1,2*n)cout<<b[i]<<' ';cout<<endl;
    cout<<ans<<' ';
    //cout<<cnt1<<' '<<cnt2<<endl;
    cout<<min(cnt1,cnt2)*2<<endl;
    return 0;
}