//
// Created by 赵婉如 on 2019-08-29.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
const int N=4005;
struct Node
{
    int num[26];
    Node operator - (const Node &rhs)const{
        Node tmp;
        for(int i = 0; i < 26; ++i){
            tmp.num[i] = num[i] - rhs.num[i];
        }
        return tmp;
    }

}a[N],b[N];
bool operator < (Node A,Node B)
{
    for(int i=0;i<26;i++)
        if(A.num[i]!=B.num[i])return A.num[i]<B.num[i];
    return 0;
}
set<Node> s;
char str1[N],str2[N];
int main()
{
    scanf("%s%s",str1+1,str2+1);
    int len1=strlen(str1+1);
    int len2=strlen(str2+1);
    F(i,1,len1){
        a[i]=a[i-1];
        a[i].num[str1[i]-'a']++;
    }
    F(i,1,len2){
        b[i]=b[i-1];
        b[i].num[str2[i]-'a']++;
    }
    int n=min(len1,len2);
    D(i,n,1){
        s.clear();
        for(int j=1;i+j-1<=len1;j++)
            s.insert(a[i+j-1]-a[j-1]);
        for(int j=1;i+j-1<=len2;j++){
            if(s.count(b[i+j-1]-b[j-1])){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
    return 0;
}
/*
grandmother
anagram
 */