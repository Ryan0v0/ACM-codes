//
// Created by 赵婉如 on 2019-09-12.
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
const int N=10;
char s[N];
char st[N];
int top;
int num[N],cnt;
int ans,cur;
//bool flag;
int main()
{
    int n=read();
    while(n--){
        scanf("%s",s+1);
        top=0;cnt=0;
        ans=0;
        int len=strlen(s+1);
        F(i,1,len){
            //cout<<top<<endl;
            if(s[i]>='0'&&s[i]<='9'){
                num[++cnt]=s[i]-'0';
            }
            //else{
                if(s[i]=='+'||s[i]=='-'||i==len){
                    cur=num[cnt--];
                    cout<<"top="<<top<<' '<<st[top]<<' '<<cur<<endl;
                    while(top>0&&(st[top]=='x'||st[top]=='/')){
                        if(st[top]=='x') cur=cur*num[cnt];
                        else cur=num[cnt]/cur;
                        cnt--;
                        top--;
                    }

                    if(top==0){
                        ans+=cur;
                    }
                    //cout<<"!!!"<<st[top]<<endl;
                    else if(st[top]=='+'){
                        //cout<<"cur="<<cur<<endl;
                        ans+=cur;
                        top--;
                    }
                    else if(st[top]=='-'){
                        ans-=cur;
                        top--;
                    }
                }
            //}
            if(!(s[i]>='0'&&s[i]<='9'))  st[++top]=s[i];
            cout<<"top="<<top<<endl;
            cout<<i<<' '<<ans<<endl;
        }
        if(ans==24) puts("Yes");
        else puts("No");
    }
    return 0;
}
/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5

*/