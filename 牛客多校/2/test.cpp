//
// Created by 赵婉如 on 2019-07-20.
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
#define N 2009

int n,m;
int M[N][N];
int h[N][N];
int ans;
int s[N],L[N],R[N];

void fin(int row){//相同不出栈
    s[0]=0;int top=0;
    h[row][m+1]=0;//用于得到最后没出栈元素的R
    for(int i=1;i<=m+1;i++){
        int ar=s[top];
        while(h[row][i]<h[row][ar]){
            R[ar]=i;top--;
            ar=s[top];
        }
        L[i]=ar;s[++top]=i;
    }
    for(int i=1;i<=m;i++)
        if(h[row][i])
            ans=max(ans,h[row][i]*(R[i]-L[i]-1));
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        mec(h,0);ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&M[i][j]);
                if(M[i][j])h[i][j]=h[i-1][j]+1;
            }
        }
        F(i,1,n){
            F(j,1,m) cout<<h[i][j]<<' ';
            cout<<endl;
        }
        for(int i=1;i<=n;i++)fin(i);
        printf("%d\n",ans);
    }
}

/*4 4
0 1 1 1
1 0 1 1
1 1 1 1
1 1 1 0*/