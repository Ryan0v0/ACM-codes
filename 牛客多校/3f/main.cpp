//
// Created by 赵婉如 on 2019-07-25.
//
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 100010;
const int inf = 0x3f3f3f3f;

int a[maxn];
int qmax[maxn],qmin[maxn];

int main() {
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        int l1 = 0, r1 = 0 , l2 = 0, r2 = 0 , pos = 0;
        for (int i = 1; i <= n; i++) {
            while (l1 < r1&& a[qmax[r1 - 1]] <= a[i]) { r1--; }
            qmax[r1++] = i;
            while (l2 < r2&& a[qmin[r2 - 1]] >= a[i]) { r2--; }
            qmin[r2++] = i;
            while (l1 < r1&&l2<r2&&a[qmax[l1]] - a[qmin[l2]]>k) {
                if (qmax[l1] < qmin[l2]) {
                    pos = qmax[l1++];
                }
                else {
                    pos = qmin[l2++];
                }
            }
            if (l1 < r1&&l2 < r2&&a[qmax[l1]] - a[qmin[l2]] >= m) {
                ans = max(ans, i - pos);
            }
        }
        printf("%d\n", ans);
    }
}
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int a[N],maxx[N],minn[N],n,m,k;//maxx数组维护单调递减序列，存的是下标，栈底元素最大，minn数组反之
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        //front为头指针，tail尾指针
        int front1=0,tail1=-1,front2=0,tail2=-1,flag=-1,ans=0;
        for(int i=0;i<n;i++)
        {
            //头指针小于尾指针且当前元素大于栈顶元素时让尾指针减一，即让使栈顶元素出栈，因为要维护一个单调递减序列
            while(front1<=tail1&&a[i]>a[maxx[tail1]]) tail1--;
            maxx[++tail1]=i;
            while(front2<=tail2&&a[i]<a[minn[tail2]]) tail2--;
            minn[++tail2]=i;
            //两个栈的栈顶元素，一个是存的是数组中最大的元素下标一个是数组中最小的元素下标
            //用最大的减去最小的分别跟m，k比较
            while(a[maxx[front1]]-a[minn[front2]]>k)
            {
                flag=min(maxx[front1],minn[front2]);//选择更小的下标让其++
                if(flag==maxx[front1]) front1++;
                if(flag==minn[front2]) front2++;
            }
            if(a[maxx[front1]]-a[minn[front2]]>=m)//记录答案
                ans=max(ans,i-flag);
        }
        printf("%d\n",ans);
    }
}
/*
5 -1 3
5 2 1 3 8
*/