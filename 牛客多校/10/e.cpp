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
struct poi{
    int x;int y;
};//a[N];
vector<poi> a;
int pos(poi p,int k)
{
    int len=(1<<(30-k));
    if(p.x<=len&&p.y<=len) return 1;
    if(p.x>=len&&p.y<=len) return 2;
    if(p.x>=len&&p.y>=len) return 3;
    if(p.x<=len&&p.y>=len) return 4;
    else return -1;//
}
void dfs(int x,int y,int k,int typ,vector<poi> &v)
{
    if(v.empty()){
        return;
    }
    vector<poi> v1,v2,v3,v4;
    F(i,0,v.size()-1){
        switch(pos(v[i],k)){
            case 1:v1.push_back(v[i]);break;
            case 2:v2.push_back(v[i]);break;
            case 3:v3.push_back(v[i]);break;
            case 4:v4.push_back(v[i]);break;
        }
    }
    int len=(1<<(30-k));
    dfs(x,y,k+1,1,v1);
    dfs(x+len,y,k+1,2,v2);
    dfs(x+len,y+len,k+1,3,v3);
    dfs(x,y+len,k+1,4,v4);
    v.clear();
    //merge
    v.insert(v.end(),v1.begin(),v1.end());
    v.insert(v.end(),v2.begin(),v2.end());
    v.insert(v.end(),v3.begin(),v3.end());
    v.insert(v.end(),v4.begin(),v4.end());
}
int main()
{
    n=read();m=read();
    F(i,1,n){
        int x=read();int y=read();
        a.push_back((poi){x,y});
    }
    dfs(1,1,1,1,a);
    F(i,0,a.size()-1) cout<<a[i].x<<' '<<a[i].y<<endl;
    return 0;
}