//
// Created by 赵婉如 on 2019-08-17.
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
const int N=100010;
int n,m;
char str[N];
//set<int> s;
priority_queue<int> s;
int main()
{
    while(~scanf("%d%d",&n,&m)){
        scanf("%s",str+1);
        int len=0;
        F(i,1,n){
            if(str[i]=='1') {
                len++;
            }
            else if(str[i]=='0') {
                s.push(len);
                len=0;
            }
        }
        int cnt=0,ans=0;/*
        D(i,s.size()-1,1){
            cnt++;
            if(cnt>m+1) break;
            ans+=s.top();
        }*/
        //(s.size()-1)*2;
        if(str[0]=='0') cnt++;
        while(!s.empty()){
            cnt+=2;
            if(cnt>m+1) break;
            ans+=s.top();
            s.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
5 1
11010
5 2
11010


1 0
2 2
3 4
 */