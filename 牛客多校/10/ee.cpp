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
int pos(int x,int y,poi p,int k)
{
    int len=(1<<(m-k));
    if(p.x<x+len&&p.y<y+len) return 1;
    if(p.x>=x+len&&p.y<y+len) return 2;
    if(p.x>=x+len&&p.y>=y+len) return 3;
    if(p.x<x+len&&p.y>=y+len) return 4;
    else return -1;//
}
void dfs(int x,int y,int k,int aa[],vector<poi> &v)
{
    //cout<<"before"<<x<<' '<<y<<' '<<k<<' '<<v.size()<<endl;
    //cout<<"before"<<endl;
    //F(i,0,v.size()-1) cout<<v[i].x<<' '<<v[i].y<<endl;
    if(k>m||v.size()<=1){//m==k||
        return;
    }
    vector<poi> v1,v2,v3,v4;
    v1.clear();v2.clear();v3.clear();v4.clear();
    F(i,0,v.size()-1){
        //cout<<"%%%"<<v[i].x<<' '<<v[i].y<<' '<<pos(x,y,v[i],k)<<endl;
        switch(pos(x,y,v[i],k)){
            case 1:v1.push_back(v[i]);break;
            case 2:v2.push_back(v[i]);break;
            case 3:v3.push_back(v[i]);break;
            case 4:v4.push_back(v[i]);break;
        }
    }
    //cout<<"v1="<<v1.size()<<",v2="<<v2.size()<<",v3="<<v3.size()<<",v4="<<v4.size()<<endl;
    int len=(1<<(m-k));
    //cout<<"len="<<len<<' '<<m<<' '<<k<<endl;
    if(aa[0]==2||aa[0]==3)dfs(x,y,k+1,aa,v1);
    else if(aa[0]==1||aa[0]==4)
    {
        int bb[4]={aa[0],aa[3],aa[2],aa[1]};
        dfs(x,y,k+1,bb,v1);
    }
    if(aa[1]==2||aa[1]==3)dfs(x+len,y,k+1,aa,v2);
    else if(aa[1]==1||aa[1]==4)
    {
        int bb[4]={aa[2],aa[1],aa[0],aa[3]};
        dfs(x+len,y,k+1,bb,v2);
    }
    if(aa[2]==2||aa[2]==3) dfs(x+len,y+len,k+1,aa,v3);
    else if(aa[2]==1||aa[2]==4)
    {
        int bb[4]={aa[0],aa[3],aa[2],aa[1]};
        dfs(x+len,y+len,k+1,bb,v3);
    }
//    cout<<"@@@"<<aa[3]<<endl;
    if(aa[3]==2||aa[3]==3) dfs(x,y+len,k+1,aa,v4);
    else if(aa[3]==1||aa[3]==4)
    {
//        cout<<"~~~"<<endl;
        int bb[4]={aa[2],aa[1],aa[0],aa[3]};
        dfs(x,y+len,k+1,bb,v4);
    }
    v.clear();
    //merge
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<4;j++)
            if(aa[j]==i)
            {
                switch(j)
                {
                    case 0:v.insert(v.end(),v1.begin(),v1.end());break;
                    case 1:v.insert(v.end(),v2.begin(),v2.end());break;
                    case 2:v.insert(v.end(),v3.begin(),v3.end());break;
                    case 3:v.insert(v.end(),v4.begin(),v4.end());break;
                }
            }
    }
    //cout<<"after"<<x<<' '<<y<<' '<<k<<' '<<len<<' '<<v.size()<<endl;
    //cout<<"after"<<endl;
    //F(i,0,v.size()-1) cout<<v[i].x<<' '<<v[i].y<<endl;
}
int main()
{
    n=read();m=read();
    F(i,1,n){
        int x=read();int y=read();
        a.push_back((poi){x,y});
    }//cout<<a.size()<<endl;
    int aa[4]={1,2,3,4};
    dfs(1,1,1,aa,a);
    //cout<<a.size()<<endl;
    F(i,0,a.size()-1) cout<<a[i].x<<' '<<a[i].y<<endl;
    return 0;
}
/*
12 3
3 1
7 2
6 3
6 6
1 8
1 1
4 3
5 4
5 1
8 8
6 7
2 4

1 4
2 4
3 2
4 2
5 1
6 1
7 3
8 3
8 4

5 8
6 7

3 2
4 2

5 8
6 7

4 3
3 5
3 6
4 7
4 8

2 3
5 8
6 7

 */
