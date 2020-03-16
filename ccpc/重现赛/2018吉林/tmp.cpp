//
// Created by 赵婉如 on 2019-10-02.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int M=505;
struct Bign
{
    int len,s[M];
    Bign(){len=1,memset(s,0,sizeof(s));}
    Bign(int num){*this=num;}
    Bign(const char *num){*this=num;}
    void clear(){while(len>1&&!s[len-1])len--;}
    Bign operator = (const int num)
    {
        char s[M];
        sprintf(s,"%d",num);
        return *this=s;
    }
    Bign operator = (const char *num)
    {
        len=strlen(num);
        for(int i=0;i<len;i++)s[i]=num[len-i-1]-'0';
        return *this;
    }
    Bign operator - (const Bign& b)
    {
        Bign c;c.len=0;
        for(int i=0,g=0;i<len;i++)
        {
            int x=s[i]-g;
            if(i<b.len)x-=b.s[i];
            if(x>=0)g=0;else g=1,x+=10;
            c.s[c.len++]=x;
        }
        c.clear();return c;
    }
    Bign operator * (const Bign& b)
    {
        Bign c;
        c.len=len+b.len;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<b.len;j++)
                c.s[i+j]+=s[i]*b.s[i];
        }
        for(int i=0;i<c.len;i++)
            c.s[i+1]+=c.s[i]/10,c.s[i]%=10;
        c.clear();return c;
    }
    Bign operator * (const int& b)
    {
        Bign c;c.len=0;
        for(int i=0,g=0;g||i<len;i++)
        {
            int x;
            if(i<len)x=s[i]*b+g;else x=g;
            c.s[c.len++]=x%10,g=x/10;
        }
        return c;
    }
    Bign operator / (const Bign& b)
    {
        Bign c,f;
        for(int i=len-1;i>=0;i--)
        {
            f=f*10,f.s[0]=s[i];
            while(f>=b)
            {
                f=f-b;
                c.s[i]++;
            }
        }
        c.len=len,c.clear();return c;
    }
    Bign operator % (const Bign& b)
    {
        Bign c=*this/b;
        c=*this-c*b;return c;
    }
    bool operator < (const Bign& b)
    {
        if(b.len!=len)return len<b.len;
        for(int i=len-1;~i;i--)
            if(s[i]!=b.s[i])return s[i]<b.s[i];
        return 0;
    }
    bool operator >= (const Bign& b){return !(*this<b);}
    string str() const
    {
        string res;
        for(int i=0;i<len;i++)res=char(s[i]+'0')+res;
        return res;
    }
};
istream& operator >> (istream&in,Bign &x)
{
    string s;
    in>>s;x=s.c_str();
    return in;
}
ostream& operator << (ostream&out,Bign x)
{
    out<<x.str();
    return out;
}
const int N=1e6+5;
int pri[N],cnt=0;
bool jud[N];
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!jud[i])pri[++cnt]=i;
        for(int j=1;j<=cnt&&pri[j]*i<N;j++)
        {
            jud[pri[j]*i]=1;
            if(i%pri[j]==0)continue;
        }
    }
}
Bign gcd(Bign a,Bign b){return (b.len==1&&b.s[0]==0)?a:gcd(b,a%b);}
int main()
{
    init();
    int T;scanf("%d",&T);
    while(T--)
    {
        Bign n,x,resp,resq;
        x=1,resp=1,resq=1;
        cin>>n;
        for(int i=1;i<=cnt;i++)
        {
            x=x*pri[i];
            if(n<x)break;
            resp=resp*pri[i];
            resq=resq*(pri[i]+1);
            Bign tmp=gcd(resp,resq);
            resp=resp/tmp;
            resq=resq/tmp;
        }
        cout<<resp<<'/'<<resq<<endl;
    }
    return 0;
}