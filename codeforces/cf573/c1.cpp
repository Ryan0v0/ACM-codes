//
// Created by 赵婉如 on 2019-07-12.
//

//
// Created by 赵婉如 on 2019-07-12.
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
int a[1000010];
int main()
{
    LL n=read();LL m=read();LL k=read();
    LL pos=-1LL;
    LL cnt=0;
    LL ans=0;
    LL buf=0;
    LL x=read();
    int t=1;
    while(true){
        //cout<<"read="<<x<<endl;
        x-=cnt;
        /*cout<<"x="<<x<<endl;
        cout<<"pos="<<pos<<endl;
        cout<<"buff="<<buf<<endl;
        cout<<"cnt="<<cnt<<endl;
        cout<<"ans="<<ans<<endl;*/

        if(pos==-1LL) {
            //cout<<"~~~1"<<endl;
            pos=((x-1)/k)*k+1;
            buf++;
            if(t>=m) {
                ans++;
                break;
            }
            x=read();t++;
        }
        else if(x-pos<k){
            //cout<<"~~~2"<<endl;
            buf++;
            if(t>=m) {
                ans++;
                break;
            }
            x=read();t++;
            //if(!(~scanf("%lld",&x))) break;
        }
        else{
            //cout<<"~~~3"<<endl;x+=cnt;
            cnt+=buf;//cout<<"!!!cnt="<<cnt<<endl;
            buf=0;
            ans++;
            pos=-1LL;
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
16 6 4
6 7 13 14 15 16
 */