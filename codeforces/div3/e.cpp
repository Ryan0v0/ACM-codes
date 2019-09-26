//
// Created by 赵婉如 on 2019-07-24.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define inf 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int b,w;
int dx[5]={0,0,-1,1};
int dy[5]={-1,1,0,0};
int main()
{
    int q=read();
    while(q--){
        b=read();w=read();
        if(b<=w){
            if(w<=3*b+1){
                puts("YES");
                    int cnt = 0;
                    F(i, 1, b) {
                        int x = 3;
                        int y = 2 * i;
                        cout << x << ' ' << y << endl;
                        F(k, 0, 3) {
                            if(i!=1&&k==0) continue;
                            if (cnt == w) {
                                break;
                            }
                            ++cnt;
                            cout << x + dx[k] << ' ' << y + dy[k] << endl;
                        }
                    }
            }else{
                puts("NO");
            }
        }else{
            if(b<=3*w+1){
                puts("YES");
                int cnt=0;
                F(i,1,w){
                    int x=2;
                    int y=2*i;
                    cout<<x<<' '<<y<<endl;
                    F(k,0,3){
                        if(i!=1&&k==0) continue;
                        if(cnt==b){
                            break;
                        }
                        ++cnt;
                        cout<<x+dx[k]<<' '<<y+dy[k]<<endl;
                    }
                }
            }else{
                puts("NO");
            }
        }
    }
    return 0;
}