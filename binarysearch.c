#include <stdio.h>
int main()
{
int i, low, high, mid, n, key, array[100];
printf("ENTER THE NUMBER OF ELEMENTS:-   ");
scanf("%d",&n);
printf("ENTER %d INTEGERS IN SORTED ORDER:-   ", n);
for(i = 0; i < n; i++)
scanf("%d",&array[i]);
printf("ENTER THE VALUE TO FIND:-   ");
scanf("%d", &key);
low = 0;
high = n - 1;
mid = (low+high)/2;
while (low <= high)
{
    if(array[mid] < key)
    low = mid + 1;
    else if (array[mid] == key)
    {
        printf("%d FOUND AT LOCATION %d.n", key, mid+1);
        break;
    }
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("NOT FOUND!!! %d ISN'T PRESENT IN THE LIST", key);
return 0;
}
