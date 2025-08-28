#include <stdio.h>

int main() {
    int num, reversedNum = 0;

    printf("-----------------------------------------REVERSE NUMBER FOR THE GIVEN INPUT NUMBER-------------------------\n\n");
    printf("Enter A Number= ");
    scanf("%d", &num);

    // Reverse the number
    while (num !=0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }


    printf("Reversed Number-> %d\n", reversedNum);

    return 0;
}

