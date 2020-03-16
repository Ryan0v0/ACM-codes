#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
map<LL,int> mp;
int n;
LL maxfloor,mxnum;
bool no;
LL x;
int main()
{
    n=read();
    maxfloor=0;
    F(k,1,n){
        x=read();//mp[x]++;
        if(no) puts("No");
        else if(x<maxfloor) puts("No");
        else if(x>maxfloor){
            mp[x]++;
            while(mp[x]>=2&&x>maxfloor) {
                mp[x]=0;
                x--;mp[x]++;
            }
            while(mp[maxfloor+1]>=1) maxfloor++;
            puts("Yes");
        }else if(x==maxfloor){
            bool flag=0;
            D(i,x,0) if(mp[i]<2){
                flag=1;
                break;
            }
            if(!flag) puts("Yes"),no=1;
            else if(mxnum<=maxfloor) puts("Yes"),no=1;
            else puts("No");
        }
        mxnum=max(mxnum,x);
        //cout<<"k="<<k<<endl;
    }
    return 0;
}
/*
10
4
4
4
4
4
4
4
4
1
4

 */