//
// Created by 赵婉如 on 2019-08-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int mian[6][4]=
        {
                {0,1,2,3},
                {4,5,10,11},
                {6,7,12,13},
                {8,9,14,15},
                {16,17,18,19},
                {20,21,22,23}
        };
int n,ans;
int col[30];
void rotate1(int d)
{
    if(d==1)
    {
        int p1 = col[23],p2 = col[22];
        col[23] = col[8],col[22] = col[9];
        col[8] = col[6],col[9] = col[7];
        col[6] = col[4],col[7] = col[5];
        col[4] = p1,col[5] = p2;
    }
    else
    {
        int p1 = col[23],p2 = col[22];
        col[23] = col[4],col[22] = col[5];
        col[4] = col[6],col[5] = col[7];
        col[6] = col[8],col[7] = col[9];
        col[8] = p1,col[9] = p2;
    }
}
void rotate2(int d)
{
    if(d==1)
    {
        int p1 = col[21],p2 = col[20];
        col[21] = col[14],col[20] = col[15];
        col[14] = col[12],col[15] = col[13];
        col[12] = col[10],col[13] = col[11];
        col[10] = p1,col[11] = p2;
    }
    else
    {
        int p1 = col[21],p2 = col[20];
        col[21] = col[10],col[20] = col[11];
        col[10] = col[12],col[11] = col[13];
        col[12] = col[14],col[13] = col[15];
        col[14] = p1,col[15] = p2;
    }
}
void rotate3(int d)
{
    if(d==1)
    {
        int p1 = col[20],p2 = col[22];
        col[20] = col[0],col[22] = col[2];
        col[0] = col[6],col[2] = col[12];
        col[6]  = col[16],col[12] = col[18];
        col[16] = p1,col[18] = p2;
    }
    else
    {
        int p1 = col[20],p2 = col[22];
        col[20] = col[16],col[22] = col[18];
        col[16] = col[6],col[18] = col[12];
        col[6]  = col[0],col[12] = col[2];
        col[0] = p1,col[2] = p2;
    }
}
void rotate4(int d)
{
    if(d==1)
    {
        int p1 = col[21],p2 = col[23];
        col[21] = col[1],col[23] = col[3];
        col[1] = col[7],col[3] = col[13];
        col[7]  = col[17],col[13] = col[19];
        col[17] = p1,col[19] = p2;
    }
    else
    {
        int p1 = col[21],p2 = col[23];
        col[21] = col[17],col[23] = col[19];
        col[17] = col[7],col[19] = col[13];
        col[7]  = col[1],col[13] = col[3];
        col[1] = p1,col[3] = p2;
    }
}
void rotate5(int d)
{
    if(d==1)
    {
        int p1 = col[5],p2 = col[11];
        col[5] = col[3],col[11] = col[2];
        col[3] = col[14],col[2] = col[8];
        col[14]  = col[16],col[8] = col[17];
        col[16] = p1,col[17] = p2;
    }
    else
    {
        int p1 = col[5],p2 = col[11];
        col[5] = col[16],col[11] = col[17];
        col[16] = col[14],col[17] = col[8];
        col[14]  = col[3],col[8] = col[2];
        col[3] = p1,col[2] = p2;
    }
}
void rotate6(int d)
{
    if(d==1)
    {
        int p1 = col[4],p2 = col[10];
        col[4] = col[18],col[10] = col[19];
        col[18] = col[15],col[19] = col[9];
        col[15]  = col[1],col[9] = col[0];
        col[1] = p1,col[0] = p2;
    }
    else
    {
        int p1 = col[4],p2 = col[10];
        col[4] = col[1],col[10] = col[0];
        col[1] = col[15],col[0] = col[9];
        col[15]  = col[18],col[9] = col[19];
        col[18] = p1,col[19] = p2;
    }
}
void dfs(int dep)
{
    int cnt = 0;
    for(int i = 0;i<6;i++)
    {
        bool flag = false;
        if(col[mian[i][0]]==col[mian[i][1]]&&col[mian[i][0]]==col[mian[i][2]]&&col[mian[i][0]]==col[mian[i][3]])
            flag = true;
        cnt+=flag;
    }
    ans = max(ans,cnt);
    if(dep>n)return ;
    rotate1(1);
    dfs(dep+1);
    rotate1(-1);
    rotate2(1);
    dfs(dep+1);
    rotate2(-1);
    rotate3(1);
    dfs(dep+1);
    rotate3(-1);
    rotate4(1);
    dfs(dep+1);
    rotate4(-1);
    rotate5(1);
    dfs(dep+1);
    rotate5(-1);
    rotate6(1);
    dfs(dep+1);
    rotate6(-1);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ans = 0;
        for(int i = 0;i<24;i++)scanf("%d",&col[i]);
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
0 0 0 0 1 1 2 2 3 3 1 1 2 2 3 3 4 4 4 4 5 5 5 5
1
0 4 0 4 1 1 2 5 3 3 1 1 2 5 3 3 4 0 4 0 5 2 5 2

 */