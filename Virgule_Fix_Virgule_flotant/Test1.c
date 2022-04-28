/*#include<stdio.h>
#include<stdlib.h>
int main(){
int a[200],n,i;
system ("cls");
printf("Enter the number to convert: ");
scanf("%d",&n);
for(i=0;n>0;i++)
{
a[i]=n%2;
n=n/2;
}
printf("\nBinary of Given Number is=");
for(i=i-1;i>=0;i--)
{
printf("%d",a[i]);
}
return 0;
}*/




#include <conio.h>
void main()
{
    // declaration of variables
    int num, binary_num, decimal_num = 0, base = 1, rem;
    printf (" Enter a binary number with the combination of 0s and 1s \n");
    scanf (" %d", &num); // accept the binary number (0s and 1s)

    binary_num = num; // assign the binary number to the binary_num variable


    while ( num > 0)
    {
        rem = num % 10; /* divide the binary number by 10 and store the remainder in rem variable. */
        decimal_num = decimal_num + rem * base;
        num = num / 10; // divide the number with quotient
        base = base * 2;
    }

    printf ( " The binary number is %d \t", binary_num); // print the binary number
    printf (" \n The decimal number is %d \t", decimal_num); // print the decimal
    getch();
}
