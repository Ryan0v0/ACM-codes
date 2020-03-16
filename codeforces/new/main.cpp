#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
char s[10];
int n;
int main()
{
    //fgets(s,100,stdin);
    //puts(s);
    char c1,c2;
    scanf("%c %c",&c1,&c2);
    cout<<c1<<' '<<c2<<endl;
    //cout<<n<<endl;
    return 0;
}