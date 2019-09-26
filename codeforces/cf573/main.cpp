#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
/////???????????????
/////!!!!!!!!!!!!!!
int main()
{
    int x=read();
    if(x%4==1){
        cout<<0<<" A"<<endl;
    }
    if(x%4==3){
        cout<<2<<" A"<<endl;
    }
    if(x%4==2){
        cout<<1<<" B"<<endl;
    }
    if(x%4==0){
        cout<<1<<" A"<<endl;
    }
    return 0;
}
///hdfajadsofjldaisjfosa