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
typedef long long ll;
ll arr[100005];
int main()
{

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {

        ll N,K,sum=0,res=0;
        ll temp;
        scanf("%lld%lld", &N, &K);
        for(int i=0;i<N;i++)
        {

            scanf("%lld", &temp);
            sum+=temp;
            arr[i]=sum;
        }

        if(sum%K!=0)
        {
//            cout<<"Case #"<<t<<": -1"<<endl;
            printf("Case #%d: -1\n", t);
            continue;
        }
        ll block=sum/K;
        int pos=0;
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
        }

        //cout<<"Case #"<<t<<": "<<res<<endl;
        printf("Case #%d: %lld\n", t, res);
    }
    return 0;
}