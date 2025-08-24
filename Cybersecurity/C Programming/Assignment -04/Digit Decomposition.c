#include <stdio.h>

void decomposeNumber(int num) {//function takes int and doesn't return

   if (num == 0) {
        printf("Please enter a number greater than 0.\n");
        return;
    }//if 0 input ,function exit


    printf("Decompose the number->%d\n\n",num);

    int place =1;//keeps track of digits(ones,tens,hundreds,and so on)
    while(num>0){//loops runs when num greater than 0
        int digit = num%10;//extracts the last digit of num
        if(digit >0){
           printf(" %d's = %d\n", place, digit);
        }//when digit greater than 0,prints place value
        num/=10;//removes last digit by division 10
        place*=10;//multiply by 10 gives next high place
        }
}

int main() {
    int num;
    printf("----------------------DECOMPOSE A NUMBER INTO INDIVIDUAL DIGITS---------------------------\n\n");
    printf("Enter a set of number: ");
    scanf("%d", &num);
    decomposeNumber(num);//function call
    return 0;
}
