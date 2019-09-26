//
// Created by 赵婉如 on 2019-08-10.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#define LL long long
#define N 100005
using namespace std;
char s[N];
int cnt=0,ans=0;
struct Node
{
    char c;
    int len,lst,nxt;
}blo[N];
int main()
{
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        if(i==0||s[i]!=s[i-1])
        {
            blo[++cnt].c=s[i];
            blo[cnt].len=1;
            blo[cnt].nxt=cnt+1;
            blo[cnt].lst=cnt-1;
        }
        else blo[cnt].len++;
    }
    int head=1;
    for(int i=head;i<=cnt;i=blo[i].nxt)
    {
        if(blo[i].len>=3)
            ans+=blo[i].len/3;
        blo[i].len%=3;
        if(!blo[i].len)
        {
            if(!blo[i].lst)continue;
            if(blo[blo[i].nxt].c!=blo[blo[i].lst].c)
            {
                blo[blo[i].lst].nxt=blo[i].nxt;
                blo[blo[i].nxt].lst=blo[i].lst;
            }
            else
            {
                blo[blo[i].nxt].len+=blo[blo[i].lst].len;
                blo[blo[i].nxt].lst=blo[blo[i].lst].lst;
            }

        }
    }
    printf("%d\n",ans);
    return 0;
}