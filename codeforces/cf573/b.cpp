//
// Created by 赵婉如 on 2019-07-12.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
//fdasfjoajdsglf jgaldjgf
string s1,s2,s3;
int b[5][30];
int ans;
int main()
{
    cin>>s1>>s2>>s3;
    if(s1[1]=='s') {
        b[1][s1[0]-'0']++;
    }
    if(s1[1]=='p') {
        b[2][s1[0]-'0']++;
    }
    if(s1[1]=='m') {
        b[3][s1[0]-'0']++;
    }
//jdflajlgjfaldjisgflasdlgf
    if(s2[1]=='s') {
        b[1][s2[0]-'0']++;
    }
    if(s2[1]=='p') {
        b[2][s2[0]-'0']++;
    }
    if(s2[1]=='m') {
        b[3][s2[0]-'0']++;
    }

    if(s3[1]=='s') {
        b[1][s3[0]-'0']++;
    }
    if(s3[1]=='p') {
        b[2][s3[0]-'0']++;
    }
    if(s3[1]=='m') {
        b[3][s3[0]-'0']++;
    }
//jldasfjoisad jfiodsjvjcsdf
    for(int i=1;i<=3;i++){
        for(int j=3;j<=9;j++){
            if(b[i][j]>1){
                ans=max(ans,b[i][j]);
            }
                int sum = (b[i][j]>=1) + (b[i][j - 1]>=1) + (b[i][j - 2]>=1);
                ans = max(ans, sum);
        }
    }

    cout<<3-ans<<endl;
    return 0;
}