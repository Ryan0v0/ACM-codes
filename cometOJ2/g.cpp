//
// Created by 赵婉如 on 2019-08-29.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
int T;

map<int,int>mp;
int n;

void init(){
    mp.clear();
}


int main(){

    scanf("%d",&n);
    int fa = 0,flag = 0,mmax = 0;
    init();
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(flag==1) printf("No\n");
        //cout<<"fa="<<fa<<endl;
        else if(x>fa){
            cout<<x<<' '<<fa<<endl;
            printf("Yes\n");
            mp[x]++;
            int cur=x;
            while(mp[cur]>1&&cur>fa){
                mp[cur]=0;
                cur--;
                mp[cur]++;
            }
            while(mp[fa+1]>=1)  fa++;
        }else if(x==fa){
            int f = 0;
            for(int i=x;i>=0;i--){
                if(mp[i]<2) f = 1;
            }
            if(mmax>fa&&f)  printf("No\n");
            else{
                printf("Yes\n");
                flag=1;
            }
        }else   printf("No\n");
        mmax = max(mmax,x);
    }

    return 0;
}
/*
6
2
3
1
1
4
2

 */