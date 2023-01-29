#include <stdio.h>
 
void towers(int num, char from, char to, char aux);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The moves involved in the ToH are :\n");
    towers(num, 'A', 'C', 'B');
    printf("\n");
    return 0;
}
 
void towers(int num, char from, char to, char aux)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from %c to %c", from, to);
        return;
    }
    towers(num - 1, from, aux, to);
    printf("\n Move disk %d from %c to %c", num, from, to);
    towers(num - 1, aux, to, from);
}
