//
// Created by 赵婉如 on 2019-08-29.
//

#include <bits/stdc++.h>
#define N 4005
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
struct Node
{
    int num[26];
    Node(){memset(num,0,sizeof(num));}
    bool operator < (Node A,Node B){
        for(int i=0;i<26;i++)
            if(A.num[i]!=B.num[i])return A.num[i]<B.num[i];
        return 0;
    }
};

unordered_set<Node> mp;
char a[N],b[N];
int main()
{
    scanf("%s%s",a,b);
    int n=strlen(a),m=strlen(b);
    for(int i=0;i<n;i++)
    {
        Node t;
        for(int j=i;j<n;j++)
            t.num[a[j]-'a']++,mp.insert(t);
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        Node t;int maxn=0;
        for(int j=i;j<m;j++)
        {
            t.num[b[j]-'a']++;
            if(mp.find()!=end())maxn=max(maxn,j-i+1);
        }
        ans=max(ans,maxn);
    }
    printf("%d\n",ans);
    return 0;
}