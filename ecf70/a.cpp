//
// Created by 赵婉如 on 2019-08-12.
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
char s1[N],s2[N];
int  n,m,tot=0,head[N];
struct edge{int fro,go,next;}e[N];
void add(int x,int y)
{
    e[++tot]=(edge){x,y,head[x]};head[x]=tot;
    e[++tot]=(edge){y,x,head[y]};head[y]=tot;
}
int main()
{
    int tt=read();
    while(tt--){
        //cin>>s1>>s2;
        scanf("%s%s",s1+1,s2+1);
        int len1=strlen(s1+1);
        int len2=strlen(s2+1);
        int p=len2;//quan 0?
        D(i,len2,1){
            if(s2[i]=='1'){
               p=len2-i+1;
               break;
            }
        }
        //cout<<"p="<<p<<endl;
        //cout<<len2-p+1<<endl;
        D(i,len1-p+1,1){
            //cout<<"i="<<i<<endl;
            if(s1[i]=='1'){
                cout<<len1-p+1-i<<endl;
                break;
            }
        }
        //cout<<i-(len2-p+1)+1<<endl;
    }
    return 0;
}