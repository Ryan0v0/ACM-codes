//
// Created by 赵婉如 on 2019-07-18.
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
#define mod 998244353
int n;
LL ans;
LL a[100010];
int b[20];
LL s1[100010][20],s2[100010][20];
int main()
{
    n=read();
    F(i,1,n) {
        a[i] = read();
        LL t=a[i];
        LL sum=0;
        LL pow=1LL;
        int cnt=0;
        s1[i][0]=t;
        while(t){
            //cout<<t%10<<' '<<sum<<endl;
            sum+=(t%10)%mod*pow%mod;
            t/=10;
            pow=pow%mod*100%mod;
            cnt++;
            s1[i][cnt]=(sum%mod+t%mod*pow%mod)%mod;
            s2[i][cnt]=s1[i][cnt-1]*10LL%mod;
            //cout<<"~~~"<<s1[i][cnt-1]<<' '<<s2[i][cnt]<<endl;
        }
        //cout<<"______"<<endl;
        b[cnt]++;
        F(j,cnt,10) s1[i][j]=s1[i][cnt-1];
        F(j,cnt+1,10) s2[i][j]=s2[i][cnt];
        //s[i]=sum%mod;
        //ans=(ans%mod+((sum%mod)%mod+sum%mod*10LL%mod)%mod*n%mod)%mod;
        //cout<<"ans="<<ans<<endl;
    }
    /*F(i,1,n) {
        F(j,0,10) cout<<s1[i][j]<<"-"<<s2[i][j]<<' ';
        cout<<endl;
    }*/
    //cout<<"~~~~~"<<endl;
    //F(i,0,10) cout<<b[i]<<endl;
    F(i,1,n) F(j,0,10){
        (ans+=s1[i][j]%mod*b[j]%mod+s2[i][j]%mod*b[j]%mod)%=mod;
        //cout<<s1[i][j]<<' '<<s2[i][j]<<' '<<b[j]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

/*
4
7777 888 33 44444
 */