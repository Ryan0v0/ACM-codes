//
// Created by 赵婉如 on 2019-10-02.
//

#include <algorithm>　　　 //STL通用算法
#include <bitset>　　　　　//STL位集容器
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>　　　　 //复数类
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>　　　　　 //STL双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream>
#include <functional>　　　//STL定义运算函数（代替运算符）
#include <limits>
#include <list>　　　　　　//STL线性列表容器
#include <map>　　　　　　 //STL 映射容器
#include <iomanip>
#include <ios>　　　　　　//基本输入／输出支持
#include<iosfwd>　　　　　//输入／输出系统使用的前置声明
#include <iostream>
#include <istream>　　　　 //基本输入流
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 //STL队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　//基于字符串的流
#include <stack>　　　　　 //STL堆栈容器　　　　
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　//底层输入／输出支持
#include <string>　　　　　//字符串类
#include <utility>　　　　 //STL通用模板类
#include <vector>　　　　　//STL动态数组容器
#include <cwchar>
#include <cwctype>
#define ll long long
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
int dx[]= {-1,1,0,0,-1,-1,1,1};
int dy[]= {0,0,-1,1,-1,1,1,-1};
const int maxn = 1000000+66;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
int n,m;
ll s[maxn];
int main()
{
    ll max1=100004;
    for(ll i=1; i<max1; i++)
    {
        s[i]=s[i-1]+1LL*i;
    }
    //前缀和
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll ha,hb,ta,tb;
        scanf("%lld %lld %lld %lld",&ha,&hb,&ta,&tb);
        ll last=lower_bound(s+1,s+max1,ha+hb)-s;
        //能打死两个的天数
        //先打A
        string str;
        string str1;
        ll pos=lower_bound(s+1,s+max1,ha)-s;//打A用的天数
        ll los=s[pos]-ha;//这一天可以打B
        ll s1=1LL*pos*ta+1LL*last*tb;
        if(s[last]-s[pos]>=hb)//可以后面直接放B
        {
            for(ll i=1; i<=pos; i++)
                str+='A';
        }
        else
        {
            for(ll i=1; i<=pos; i++)
            {
                if(i!=los)
                    str+='A';
                else
                    str+='B';
            }
        }
        for(ll i=pos+1; i<=last; i++)
            str+='B';
        //先打B
        pos=lower_bound(s+1,s+max1,hb)-s;
        ll s2=1LL*last*ta+1LL*pos*tb;
        ll locb=s[pos]-hb;//可以空闲的时间和
        ll lb1=upper_bound(s+1,s+max1,locb)-s-1;
        ll bac=s[last]-s[pos];
        if(bac+s[lb1]>=ha)
        {
            for(ll i=1;i<=lb1;i++)
            {
                str1+='A';
            }
            for(ll i=lb1+1;i<=pos;i++)
            {
                str1+='B';
            }
            for(ll i=pos+1;i<=last;i++)
            {
                str1+='A';
            }
        }else
        {
            ll left=ha-bac;//打死a还需要的
            for(ll i=1;i<=pos;i++)
            {
                if(left-i>i||left==i)
                {
                    left-=i;
                    str1+='A';
                }else
                {
                    str1+='B';
                }
            }
            for(ll i=pos+1;i<=last;i++)
            {
                str1+='A';
            }
        }
        if(s1>s2)
        {
            printf("%lld ",s2);
            cout<<str1<<endl;
        }else if(s1<s2)
        {
            printf("%lld ",s1);
            cout<<str<<endl;
        }else if(str<str1)
        {
            printf("%lld ",s1);
            cout<<str<<endl;
        }else
        {
            printf("%lld ",s2);
            cout<<str1<<endl;
        }
    }
}