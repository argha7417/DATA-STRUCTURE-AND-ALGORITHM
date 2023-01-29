#include <stdio.h>
int main()
{
    int a[100], n, n1, x, c=0,e=0;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
    {
        printf("Enter the elements of the array:\n");
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:\n");
    scanf("%d",&n1);
    printf("%d",&a);
    for(int j=0;j<=n-1;j++)
    {
        if(a[j]==n1)
        {
            c=c+1;
            printf("%d",a[j]);
        }
    }
    if(c==1)
    {
        printf("ELEMENT FOUND");
    }
    else
    {
        printf("ELEMENT NOT FOUND");
    }
    return 0;
}