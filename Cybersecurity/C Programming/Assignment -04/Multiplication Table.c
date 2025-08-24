///////Multiplication Table\\\\\\\

#include<stdio.h>
int main()
{
        int a[15];
        int multiplication_table;
        printf("-----------------------------------Create a Multiplication Table-------------------------------------\n\n");
        printf("ENTER A NUMBER GREATER THAN 1.\n");
        scanf("%d",&multiplication_table);

        for (int m=0; m<15; m++)
        {
                a[m]=(m+1)*multiplication_table;
        }
        for (int p=0; p<15; p++)
        {
                printf("%dx%d=%d\n",p+1,multiplication_table,a[p]);
        }
}
