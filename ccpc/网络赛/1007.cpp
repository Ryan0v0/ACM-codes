#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
bool s[2049][2049];
void init()
{
    s[0][0]=0,s[0][1]=0,s[1][0]=1,s[1][1]=0;
    for(int i=2;i<=10;i++)
    {
        int len=(1<<(i-1));
        for(int j=0;j<len;j++)
        for(int k=0;k<len;k++)
        s[j+len][k]=(!s[j][k]),s[j][k+len]=s[j+len][k+len]=s[j][k];
    }
}
int main()
{
    int T;init();
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<(1<<n);j++)
            putchar(s[i][j]?'P':'C');
            putchar('\n');
        }
    }
    return 0;
}
