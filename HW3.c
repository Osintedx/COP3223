#include <stdio.h>
#include <stdlib.h>
//Homework 3
int main()
{
    int uno, dos, tres;
    char choice = "X";
    printf("Enter three integers separated by spaces : ");
    scanf("%d %d %d", &uno, &dos, &tres);
    printf("\nYou have entered the numbers: %d, %d, and %d", uno, dos, tres);
    printf("\nChoose one of the options:");
    printf("\n\t A,  Print the lowest number entered");
    printf("\n\t B, Print the highest number entered");
    printf("\n\t C,  Print whether the first number entered is an even or an odd number");
    printf("\n\t D, Print the division of third number entered by the sum of the first two numbers entered \nMake your selection: ");
    scanf(" %c", &choice);
    switch(choice) {
        case 'A': {
            if (uno < dos && uno < tres){
                printf("\nLowest number %d", uno);
            }
            else if (dos < uno && dos < tres){
                printf("\nLowest number %d", dos);
            }
            else if (tres < uno && tres < dos){
                printf("\nLowest number %d", tres);
            }
            break;
        }
        case 'B': {
            if (uno > dos && uno > tres){
                printf("\nHighest number %d", uno);
            }
            else if (dos > uno && dos > tres){
                printf("\nHighest number %d", dos);
            }
            else if (tres > uno && tres > dos){
                printf("\nHighest number %d", tres);
            }
            break;
        }
        case 'C': {
            if ( uno % 2 == 0){
                printf("\nFirst number %d is even", uno);
            }
            else{
                printf("\nFirst number %d is odd", uno);
            }
            break;
        }
        case 'D': {
            int divisor = uno + dos;
            if (divisor == 0){
                printf("Can't divide by zero");
            }
            else {
                printf("%d divided by %d is %.2f", tres, divisor, (float)tres/divisor);
            }
            break;
        }
        default: {
            printf("Invalid selection!\n" );
        }
    }
    printf("\nGoodbye!");
    return 0;
}
