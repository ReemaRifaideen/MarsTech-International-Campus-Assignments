/*--Password Validation--*/

#include <stdio.h> //handles standard input and output//
#include <string.h> //functions for string//
#include <ctype.h> //checks upper-case and lower-case//
#include <stdbool.h> //for boolean logic//
#include <conio.h> //for getch() function//

//function prototype (evaluate strength of the password)//
int check_password(char *password){
        int rank = 0;
        bool has_upper = false;
        int lower_count = 0;
        bool has_symbol = false;
        int digit_count = 0;
        bool has_sequencial = false;
        int symbol_count = 0;

        //check length//
        if(strlen(password)>=8){
                rank+=1;
        }else{
                printf("\nPASSWORD MUST BE AT LEAST 8 CHARACTERS\n");
        }

        //check upper-case//
        for(int i = 0; password[i]; i++) {
                if(isupper(password[i])) {
                        has_upper = true;
                        break;
                }
        }
        if(has_upper) {
                rank+=1;
        } else {
                printf("\nPASSWORD MUST HAVE ONE UPPERCASE\n");
        }

        // Check lower-case (need at least 3)
        for(int i = 0; password[i]; i++) {
                if(islower(password[i])) {
                        lower_count++;
                }
        }
        if(lower_count >= 3) {
                rank+=2;
        } else {
                printf("\nPASSWORD MUST HAVE THREE LOWERCASE CHARACTERS\n");
        }

        // Check symbols
        for(int i = 0; password[i]; i++) {
                //checks if the character is not alphanumeric(letter/digit)//
                if(!isalnum(password[i])) {
                        symbol_count++;
                }
        }
        if(symbol_count >= 1) {
                rank+=2;
        } else {
                printf("\nPASSWORD MUST HAVE ONE SYMBOL\n");
        }

        // Check digits (need at least 3 and not sequential)
            for(int i = 0; password[i]; i++) {
                //checks if the character is alphanumeric(letter/digit)//
                if(isdigit(password[i])) {
                    digit_count++;
                    if(i > 0 && isdigit(password[i-1]) &&
                       (password[i] == password[i-1]+1)) {
                        has_sequencial = 0;
                    }
                }
            }
            if(digit_count >= 3) {
                if(!has_sequencial) {
                    rank+=3;
                } else {
                    printf("\nNUMERIC CHARACTERS MUST NOT BE SEQUENTIAL\n");
                }
            } else {
                printf("\nPASSWORD MUST HAVE THREE NUMERIC CHARACTERS\n");
            }

            return rank;
        }

int main() {
    char password[90];
    printf("-------------------------------------------------------CONDITIONS-------------------------------------------------------\n\n");
    printf("1.Password must be minimum of 8 characters,else it is considered weak and can be ranked 0\n");
    printf("2.Password must have one Uppercase character\n");
    printf("3.Password must have three Lowercase character\n");
    printf("4.Password must have one symbol\n");
    printf("5.Password must have three Numeric Characters that are not sequential\n\n");
    printf("Enter your password: ");
    scanf("%99s", password);

int i = 0;
    char ch;
    while (i < 89) {
        ch = getch(); // Get a character without echoing
        if (ch == '\r') {
            break;
        } else if (ch == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';


    //check rank of password strength//
    int rank = check_password(password);
    if (rank == 9){
        printf("\nStrength: Strongest (All conditions done)\n");
    }
    else if (rank >= 6){
        printf("\nStrength: Strong (Has most of conditions)\n");
    }
    else if (rank >=3) {
        printf("\nStrength: Medium (Has some conditions)\n");
    }
    else if (rank >=1) {
        printf("\nStrength: Weak (Has few conditions)\n");
    }
    else {
        printf("\nStrength: Weakest (Password is invalid)\n");
    }
    return 0;
    }





