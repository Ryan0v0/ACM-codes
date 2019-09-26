//
// Created by 赵婉如 on 2019-07-25.
//
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
const int N=550;
int a[N][N],maxx[N],minn[N],n,m,k;//maxx数组维护单调递减序列，存的是下标，栈底元素最大，minn数组反之
int main()
{
    int tt=read();
    while(tt--){
        int n=read();int k=read();int m=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        F(i,0,n-1) F(j,0,n-1) a[i][j]=read();
        int front1=0,tail1=-1,front2=0,tail2=-1,flag=-1,ans=0;
        for(int i=0;i<n;i++){
            while(front1<=tail1&&a[i]>a[maxx[tail1]]) tail1--;
            maxx[++tail1]=i;
            while(front2<=tail2&&a[i]<a[minn[tail2]]) tail2--;
            minn[++tail2]=i;
            while(a[maxx[front1]]-a[minn[front2]]>k){
                flag=min(maxx[front1],minn[front2]);
                if(flag==maxx[front1]) front1++;
                if(flag==minn[front2]) front2++;
            }
            if(a[maxx[front1]]-a[minn[front2]]>=m) ans=max(ans,i-flag);
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))//[m,k]
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

            cout<<front1<<' '<<tail1<<' '<<front2<<' '<<tail2<<endl;
            for(int i=front1;i<=tail1;i++) cout<<maxx[i]<<' ';cout<<endl;
            for(int i=front2;i<=tail2;i++) cout<<minn[i]<<' ';cout<<endl;
            cout<<"------------------"<<endl;
        }
        printf("%d\n",ans);
    }
}*/
/*
5 -1 3
5 2 1 3 8
*/