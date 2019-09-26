//
// Created by 赵婉如 on 2019-07-25.
//

#include<cstdio>
using namespace std;

int T,b,w;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&b,&w);
        if(b<=w&&w<=3*b+1)
        {
            puts("YES");
            for(int i=1;i<=b;i++)
                printf("%d 3\n",i*2);
            for(int i=1;i<b;i++)
                printf("%d 3\n",i*2+1);
            w-=b-1;
            for(int i=1;i<=b&&i<=w;i++)
                printf("%d 4\n",i*2);
            w-=b;
            for(int i=1;i<=b&&i<=w;i++)
                printf("%d 2\n",i*2);
            w-=b;
            if(w>0)
                printf("1 3\n"),w--;
            if(w>0)
                printf("%d 3\n",b*2+1);
        }
        else if(b>w&&b<=3*w+1)
        {
            puts("YES");
            for(int i=1;i<=w;i++)
                printf("%d 4\n",i*2);
            for(int i=1;i<w;i++)
                printf("%d 4\n",i*2+1);
            b-=w-1;
            for(int i=1;i<=w&&i<=b;i++)
                printf("%d 5\n",i*2);
            b-=w;
            for(int i=1;i<=w&&i<=b;i++)
                printf("%d 3\n",i*2);
            b-=w;
            if(b>0)
                printf("1 4\n"),b--;
            if(b>0)
                printf("%d 4\n",w*2+1);
        }
        else
            puts("NO");
    }
    return 0;
}