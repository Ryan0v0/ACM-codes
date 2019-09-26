//
// Created by 赵婉如 on 2019-08-25.
//

#include <iostream>
#include <time.h>
#include <map>
using namespace std;
long long an[] = {2,3,5,7,11,13,17,61};
map<long long,int> mp;//存因数和对应出现次数
int num = 0;
long long Random(long long n)//生成0到n之间的整数
{
    return (double) rand()/RAND_MAX*n+0.5;//(doubel)rand()/RAND_MAX生成0-1之间的浮点数
}


long long q_mod(long long a,long long n,long long p)//快速幂
{
    a = a%p;
    //首先降a的规模
    long long sum = 1;//记录结果
    while(n)
    {
        if(n&1)
        {
            sum = (sum*a)%p;//n为奇数时单独拿出来乘
        }
        a = (a*a)%p;//合并a降n的规模
        n /= 2;
    }
    return sum;
}


long long q_mul(long long a,long long b,long long p)//大数模
{
    long long sum = 0;
    while(b)
    {
        if(b&1)//如果b的二进制末尾是零
        {
            (sum += a)%=p;//a要加上取余
        }
        (a <<= 1)%=p;//不断把a乘2相当于提高位数
        b >>= 1;//把b右移
    }
    return sum;
}


//Miller-Rabin
bool witness(long long a,long long n)
{
    long long d = n-1;
    long long r = 0;
    while(d%2==0)
    {
        d/=2;
        r++;
    }//n-1分解成d*2^r，d为奇数
    long long x = q_mod(a,d,n);
    //cout << "d " << d << " r " << r << " x " << x << endl;
    if(x==1||x==n-1)//最终的余数是1或n-1则可能是素数
    {
        return true;
    }
    while(r--)
    {
        x = q_mul(x,x,n);
        if(x==n-1)//考虑开始在不断地往下余的过程
        {
            return true;//中间如果有一个余数是n-1说明中断了此过程，则可能是素数
        }
    }
    return false;//否则如果中间没有中断但最后是余数又不是n-1和1说明一定不是素数
}
bool miller_rabin(long long n)
{
    const int times = 50;//试验次数
    if(n==2)
    {
        return true;
    }
    if(n<2||n%2==0)
    {
        return false;
    }
    for(int i = 0;i<times;i++)
    {
        long long a = Random(n-2)+1;//1到(n-1)
        //cout << a << endl;
        if(!witness(a,n))
        {
            return false;
        }
    }
    return true;
}


//求gcd
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

//Pollard-rho
long long Pollard_rho(long long n,long long c)
{
    //cout << "n "  << n << " c " << c << endl;
    long long i = 1,k = 2;
    long long x = Random(n-1)+1;
    long long y = x;
    while(true)
    {
        i++;
        x = (q_mul(x,x,n)+c)%n;
        long long d = gcd(y-x,n);
        if(1<d&&d<n)
        {
            return d;
        }
        if(x==y)
        {
            return n;
        }
        if(i==k)
        {
            y = x;
            k<<=1;
        }
    }
}
void find(long long n,long long c)
{
    if(n==1)//找完了
    {
        return;
    }
    if(miller_rabin(n))//找到了质数
    {
        num++;
        mp[n]++;
        return;
    }
    long long p = n;
    while(p>=n)//找p的因数
    {
        p = Pollard_rho(p,c--);//返回p的因数或1或本身
    }
    find(p,c);//递归地找p的因子
    find(n/p,c);
}
LL num0,num1,num2,cnt;
int rho()
{
    long long n;
    n=read();
        num = 0;num0=1LL;bool flag=0;
        mp.clear();
        find(n,2137342);//随机选取的c
        //cout << n << " = ";
        if(mp.empty()){
            if(n==2) num2=1,num1=1;
            else num2=0,num1=2;
            //cout << n << endl;
        }else {
            for (auto ite = mp.begin(); ite != mp.end(); ite++) {
                num0 *= (1 + ite->second);
                if (ite->first == 2) {
                    num2 = ite->second;
                    flag = 1;
                }/*
                cout << ite->first << "^" << ite->second;
                auto i = ite;
                if (++i != mp.end()) //如果不是最后一个
                {
                    cout << "*";//输出乘号
                }*/
            }
            if (flag) num2 *= (1 << (mp.size() - 1));//2^cnt
            else num2 = 0;
            num1 = num0 - num2;
        }
        if(abs(num1-num2)<=2) return 1;
        else return 0;
}