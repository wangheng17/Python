#include <stdio.h>
int main()
{
    int num={2,7,11,15};
    static int a[2]={0};
    int target=9,i,j;
    for(i=0;i<3;i++)
        for(j=1;j<4;j++)
        {
            if(num[i]+num[j]==target)
            {
                a[0]=i;
                a[1]=j;
                return a;
            }
        }
    return 0;
}