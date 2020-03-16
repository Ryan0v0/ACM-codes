#include<cstdio>
#include<vector>
#include<cstring>
#define M (L+R>>1)
using namespace std;
 
struct item
{
 int A,B,C,D,id;
}Q[10005],tQ1[10005],tQ2[10005];
 
int T,n,m,q,a[205][205],h[2005],t[205][205],ans[10005];
vector<int> V[205][205];
 
inline int query(int x, int y, int xx, int yy)
{
 return t[xx][yy]+t[x-1][y-1]-t[x-1][yy]-t[xx][y-1];
}
 
void solve(int L, int R, int l, int r)
{
 if(L==R)
 {
  for(int i=l;i<=r;i++)
   ans[Q[i].id]=L;
  return ;
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   t[i][j]=a[i][j]<=M;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
 int qn1=0,qn2=0;
 for(int i=1;i<=q;i++)
  if(query(Q[i].A,Q[i].B,Q[i].C,Q[i].D)>(Q[i].C-Q[i].A+1)*(Q[i].D-Q[i].B+1)/2)
   tQ1[++qn1]=Q[i];
  else
   tQ2[++qn2]=Q[i];
 for(int i=1;i<=q;i++)
  if(i<=qn1)
   Q[i]=tQ1[i];
  else
   Q[i]=tQ2[i-qn1];
 solve(L,M,l,qn1);
 solve(M+1,R,qn1+1,r);  
}
 
int main()
{
 freopen("important.in","r",stdin);
 scanf("%d",&T);
 for(int g=1;g<=T;g++)
 {
  scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    scanf("%d",&a[i][j]);
  for(int i=1;i<=q;i++)
   scanf("%d%d%d%d",&Q[i].A,&Q[i].B,&Q[i].C,&Q[i].D),Q[i].id=i;
  solve(1,2000,1,q);
  printf("Case %d:\n",g);
  for(int i=1;i<=q;i++)
   printf("%d\n",ans[i]);
 }
 return 0;
}
