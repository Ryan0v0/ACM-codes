//
// Created by 赵婉如 on 2019-08-17.
// 不用动态 所以不需要priority_queue
// 9:45-10:33 wa1
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
int s[N];//set
int main()
{
    while(~scanf("%d%d",&n,&m)){
        scanf("%s",str+1);
        int st=1,ed=n;
        int top=0,last=0;
        while(st<n && str[st]=='1') st++;top=st-1;
        while(ed>=st && str[ed]=='1') ed--;last=n-ed;//ed+1~n n-(ed+1)+1=n-ed
        if(m==0){
            cout<<top<<endl;
            continue;
        }
        int siz=0,len=0;
        F(i,st,ed){//保证最后一个一定能统计到
            if(str[i]=='1') len++;
            else if(len>0&&str[i]=='0'){
                s[++siz]=len;
                len=0;
            }
        }
        //cout<<st<<' '<<ed<<' '<<siz<<endl;
        sort(s+1,s+siz+1);
        int ans=0;
        while(m>2 && siz>=1){//从大到小
            ans+=s[siz];
            m-=2;
            siz--;
        }
        if(m==1) ans+=max(s[siz],top+last);
        else ans+=max(top+s[siz],max(top+last,last+s[siz]));//m==2
        cout<<ans<<endl;
    }
    return 0;
}
/*
14 0
01111111001111
14 0
10111100000011
14 1
11111111011111
10 4
0010111011
9 4
101101110
8 2
10110111

 */