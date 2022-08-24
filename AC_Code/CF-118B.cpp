#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        for(j=0; j<(n-i)*2; j++)
            printf(" ");
        if(i==0)
            printf("0");
        else
        {
            int s=0;
            for(j=0; j<=i; j++)
                printf("%d ",s++);
            s--;
            for(j=0; j<i; j++)
            {
                if(j==i-1)
                    printf("%d",--s);
                else
                    printf("%d ",--s);
            }
        }
        printf("\n");
    }
    for(i=n-1; i>=0; i--)
    {
        for(j=(n-1)*2+1; j>=i*2; j--)
            printf(" ");
        if(i==0)
            printf("0");
        else
        {
            int s=0;
            for(j=0; j<=i; j++)
                printf("%d ",s++);
            s--;
            for(j=0; j<i; j++)
            {
                if(j==i-1)
                    printf("%d",--s);
                else
                    printf("%d ",--s);
            }
        }
        printf("\n");
    }
    return 0;
}
