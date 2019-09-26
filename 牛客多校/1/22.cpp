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
const int N=100;
int n,m;
//int a[N][N];
int p[N];
bool vis[N];
char s1[N][N],s2[N][N];
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();bool next=0;
        mec(p,0);mec(vis,0);//-1
        F(i,1,n){
            scanf("%s",s1[i]+1);
            /*cout<<"!!!"<<endl;
            F(j,1,m) cout<<s1[i][j];cout<<endl;
            cout<<"!!!"<<endl;*/
            scanf("%s",s2[i]+1);
        }
        F(i,1,m) {
            bool check=0;
            F(j,1,m) if(!vis[j]){
                bool fail=0;
                F(k,1,n){
                    if(s1[k][i]!=s2[k][j]){
                        fail=1;
                        break;
                    }
                }
                if(!fail){
                    p[i]=j;
                    //cout<<i<<' '<<j<<endl;
                    vis[j]=1;
                    check=1;
                    break;//continue;
                }
            }
            if(!check){
                puts("-1");
                next=1;
                break;
            }
        }
        if(next) continue;
        F(i,1,m){
            cout<<p[i];
            if(i==m) cout<<endl;
            else cout<<' ';
        }
    }
    return 0;
}
/*
4
1 3
abc
bca
2 4
aaab
baaa
cdcc
cccd
3 3
aaa
aaa
bbb
bbb
ccc
ccc
1 1
a
z

 */