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
LL a[2000010];//
int b[2000010];
int main()
{
    int q=read();
    while(q--){
        int n=read();int k=read();
        int cnt=0;
        F(i,1,n){
            a[i]=read();
            if(a[i]%2==1) b[++cnt]=i;
        }
        if(cnt>=k && (cnt%2)==(k%2)){
            puts("YES");
            F(i,1,k-1){
                cout<<b[i]<<' ';
            }
            cout<<n<<endl;
        } else{
            puts("NO");
        }
    }
    return 0;
}
/*
3
6 2
1 2 8 4 10 2
5 3
7 18 3 14 1
5 4
1 2 3 4 5

 */