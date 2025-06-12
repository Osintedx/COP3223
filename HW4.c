#include <stdio.h>
#include <stdlib.h>
//Homework 4
int main()
{
    char choice = "d";
    int num;
    int tb_size, tb_iter;
    while (choice != 'Q' && choice != 'q') {
        printf("\nChoose from the following options: ");
        printf("\nA or a:  To display the divisors of a natural number ");
        printf("\nB or b: To display the multiplication table for a natural number ");
        printf("\nQ or q to Exit ");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case 'A' :
            case 'a' : {
                //Divisors
                printf("\nEnter your number: ");
                scanf(" %d", &num);
                if (num > 0) {
                    printf("The divisors of %d are: ", num);
                    int divisor = 1;
                    do {
                        if (divisor == 1){
                            printf("1");
                        }
                        else if (num%divisor == 0 && num != divisor){
                            printf(",%d", divisor);
                        }
                        if (num == 1){
                            break;
                        }
                        divisor++;
                    } while(divisor != num);
                    printf(" and %d", num);
                    break;
                }
                else {
                    printf("%d is not a natural number ", num);
                }
            }
            case 'B' :
            case 'b' : {
                //Multiple Table
                printf("\nEnter your number: ");
                scanf(" %d", &num);
                if (num > 0){
                    printf("\nEnter the size of the multiplication table (1,2...etc): ");
                    scanf(" %d", &tb_size);
                    for (tb_iter = 1; tb_iter <= tb_size; tb_iter++){
                        printf("\n%d x %d = %d", tb_iter, num, tb_iter*num);
                    }
                }
                else {
                    printf("%d is not a natural number ", num);
                }
                break;
            }
            case 'Q' :
            case 'q' : {
                choice = 'Q';
                //Quit
                break;
            }
            default: {
                printf("\nInvalid option! ");
            }
        }
    }

    printf("\nBye!");
    return 0;
}
