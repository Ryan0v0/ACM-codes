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
int fir,sec;
int s[N],L[N],R[N];
int ans;
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
        if(h[row][i]){
            int t=h[row][i]*(R[i]-L[i]-1);
            if(t>=fir){
                sec=fir;
                fir=t;
            }
            else if(t>=sec){
                sec=t;
            }
            if(h[row][i]*(R[i]-L[i]-2)>=sec){
                sec=h[row][i]*(R[i]-L[i]-2);
            }
        }
}
/*
void fin_(int row){//相同出栈
    s[0]=0;int top=0;
    h[row][m+1]=0;
    for(int i=1;i<=m+1;i++){
        int ar=s[top];
        while(h[row][i]<=h[row][ar]){
            R[ar]=i;top--;
            if(top<0)break;//最后m+1的时候把s[0]也出栈了
            ar=s[top];
        }
        L[i]=ar;s[++top]=i;
    }
    for(int i=1;i<=m;i++)
        if(h[row][i])
            ans=max(ans,h[row][i]*(R[i]-L[i]-1));
}*/
const int maxn=100010;
char str[maxn];
int main(){
    //while(scanf("%d%d",&n,&m)!=EOF){
     n=read();m=read();
        mec(h,0);fir=sec=0;
        F(i,1,n){
            scanf("%s",str+1);
            F(j,1,strlen(str+1)){
                M[i][j]=str[j]-'0';
                if(M[i][j])h[i][j]=h[i-1][j]+1;
            }
        }
        /*F(i,1,n){
            F(j,1,m) cout<<M[i][j]<<' ';
            cout<<endl;
        }*/
        for(int i=1;i<=n;i++)fin(i);
        printf("%d\n",sec);
//    }
}/*
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
}*/
/*
3 4
0110
1111
1010

3 4
0110
1111
1010

4 4
0000
0110
0110
0000

4 4
0101
1011
0000
1110

 */