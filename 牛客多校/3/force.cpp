//
// Created by 赵婉如 on 2019-07-25.
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
char s[N];
int a[N],sum[N];
int b[2*N];
int cnt1,cnt2;
int ans;
int main()
{
    int n=read();
    scanf("%s",s+1);
    F(i,1,n){
        a[i]=s[i]-'0';
        if(a[i]==0){
            a[i]=-1;
            cnt1++;
        }
        else cnt2++;
        sum[i]=sum[i-1]+a[i];
        //cout<<sum+n<<' ';
    }
    F(i,1,n) F(j,i+1,n){
        if(sum[i]-sum[j-1]==0){
            ans=max(ans,j-i+1);
        }
    }
    //cout<<endl;
    //F(i,1,2*n)cout<<b[i]<<' ';cout<<endl;
    cout<<ans<<' ';
    //cout<<cnt1<<' '<<cnt2<<endl;
    cout<<min(cnt1,cnt2)*2<<endl;
    return 0;
}