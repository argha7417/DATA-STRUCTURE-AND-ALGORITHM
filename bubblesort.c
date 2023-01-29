#include <stdio.h>
int main()
{
    int a[100];
    int i, j,k,n, temp;  
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the array:");
    for(int k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }
    for (int l=0;l<n;l++)
    printf("%d   ",a[l]);
    return 0;     
}
