//
// Created by 赵婉如 on 2019-08-26.
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
const int N=2e6+10;
LL a[N];
int main()
{
    int n=read();
    F(i,1,n) a[i]=read();
    int ans=n-1;
    map<int,int> freq;
    F(i,1,n){
        bool validPre=true;
        F(j,1,i-1){
            freq[a[j]]++;
            if(freq[a[j]]==2){
                validPre=false;
                break;
            }
        }
        int minSuf=n+1;
        D(j,n,i){
           freq[a[j]]++;
           if(freq[a[j]]==1){
               minSuf=j;
           }else break;
        }
        if(validPre){
            ans=min(ans,minSuf-i);
        }
        freq.clear();
    }
    cout<<ans<<endl;
    return 0;
}
/*
8
1 3 3 4 3 2 3 1

 */