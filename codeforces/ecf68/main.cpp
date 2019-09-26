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
string str;
vector<string> v;
int a[10010][10010];
int b[10010];
int c[10010];
int main()
{
    int q=read();
    while(q--) {
        int ans=1000000000;
        int n = read();
        int m = read();
        mec(b,0);
        mec(c,0);
        v.clear();
        F(i, 1, n){
            //mec(a[i],0);
            //scanf("%s",str+1);
            cin>>str;
            cout<<str<<endl;
            v.push_back(str);
            //cout<<(str+1)<<endl;
            F(j,0,str.length()-1){
                if(str[j]=='*'){
                    //a[i][j]=1;
                    b[i]++;
                    c[j+1]++;
                }
            }
        }
        //F(i,1,n) cout<<b[i]<<' ';cout<<endl;
        //F(j,1,m) cout<<c[j]<<' ';cout<<endl;
        /*
        F(i,1,n) {
            F(j,1,m) cout<<str[i][j];
            cout<<endl;
        }*/
        //F(i,1,n) F(j,1,m) b[i]+=a[i][j];//hang
        //F(i,1,m) F(j,1,n) c[i]+=a[j][i];//lie
        //cout<<"???"<<endl;
        //cout<<v.size()<<endl;
        //cout<<q<<endl;
        F(i,1,n) F(j,1,m){
            //cout<<v[i][j-1]<<endl;
            if(v[i][j-1]=='*'){
                //cout<<"~~~"<<endl;
                ans=min(ans,m+n-1-(b[i]+c[j]-1));
            }else{
                ans=min(ans,m+n-1-(b[i]+c[j]));
            }
            //cout<<"~~~~!"<<endl;
        }
        //cout<<"~~~~!"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}