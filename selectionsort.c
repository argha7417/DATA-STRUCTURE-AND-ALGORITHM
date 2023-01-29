#include <stdio.h>  

int main()
{
    int i,j,n,min,swap;
    printf("ENTER THE NUMBER OF ELEMENTS:-");
    scanf("%d",&n);
    int a[n];
    printf("ENTER THE ELEMENTS IN THE ARRAY:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        if(min!=i)
        {
            swap=a[i];
            a[i]=a[min];
            a[min]=swap;
        }
    }
    
    printf("THE SORTED ARRAY IS:");
    for(i=0;i<n;i++)
    printf("%d   ",a[i]);
    return 0;
}
