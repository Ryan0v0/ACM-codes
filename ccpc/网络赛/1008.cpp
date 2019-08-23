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
const int N=100010;
int n;
LL k=0,ans;
int a[N];
int main()
{
    int tt=read();
    while(tt--){
        priority_queue<int> q;
        n=read();k=read();//ans=0;
        ans=(LL)n*k;
        F(i,1,n){
            a[i]=read();
            q.push(a[i]);
        }
        int cnt=1;
        while(cnt<n&&!q.empty()){
            LL x=q.top();q.pop();
            if(x>k) {
                x-=k;q.push(x);
            }
            cnt++;
        }
        while(!q.empty()){
            ans+=q.top();q.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
3 5
5 5 8
2 4
3 3

 */