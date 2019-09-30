//
// Created by 赵婉如 on 2019-09-27.
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
int n,m;
LL a[N];
LL sum,siz,ans;
int main()
{
    int tt=read();
    F(Case,1,tt){
        ans=0;sum=0;
        cout<<"Case #"<<Case<<": ";//<<solve()<<end;
        n=read();m=read();
        F(i,1,n){
            a[i]=read();
            sum+=a[i];
            a[i]+=a[i-1];
        }
        siz=sum/m;
        if(sum%m!=0){
            puts("-1");
            continue;
        }else{
            //cout<<"size="<<siz<<endl;
            /*LL last=0;
            for(int i=1;i<=K;i++)
            {
                while(arr[pos]<i*block)
                {
                    pos++;
                    res++;
                }
                if(arr[pos]!=i*block && i!=K)
                    res++;
                else pos++;
            }*/
            int pos=1;
            F(i,1,m){
                while(a[pos]<i*siz){
                    pos++;
                    ans++;
                }
                if(a[pos]!=i*siz) ans++;
                else pos++;
            }
            /*F(i,1,n){
                if((a[i]+last)%siz==0){
                    if(last) ans++;
                    ans+=(a[i]+last)/siz-1;
                    //if(!last) ans--;
                    last=0;
                    //cout<<"1!!!"<<endl;
                    //continue;
                }
                /*else if(a[i]+last>siz){
                    ans+=(a[i]+last)/siz;
                    last=(a[i]+last)%siz;
                }*/
                /*else if(a[i]+last<siz){
                    ans++;
                    last+=a[i];
                    //cout<<"2!!!"<<endl;
                }else{
                    ans+=(a[i]+last)/siz;
                    //if(last==0&&(a[i]+last)%siz==0) ans--;
                    last=(a[i]+last)%siz;
                    //cout<<"3!!!"<<endl;
                }
                //cout<<i<<' '<<ans<<' '<<last<<endl;
            }*/
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*
10
1 3
14
3 1
2 3 4
3 6
1 2 3
4 5
1 2 3 4
4 5
2 3 1 4
2 2
1 3

 */