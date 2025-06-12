#include <stdio.h>
#include <stdlib.h>
//HW5
int main()
{
    int *x, *y;
    char *c;
    x = malloc(sizeof(int));
    y = malloc(sizeof(int));
    c = malloc(sizeof(char));
    printf("Enter your two integers: ");
    scanf("%d %d", x, y);
    printf("\nNow, enter a or A to show the sum, p or P to show the product or d or D to show the division of the first by the second: ");
    scanf(" %c", c);
    switch (*c){
        case 'A':
        case 'a':{
            printf("%d+%d = %.2f", *x, *y, (float) *x + *y);
            break;
        }
        case 'p':
        case 'P':{
            printf("%d*%d = %.2f", *x, *y, (float) *x * *y);
            break;
        }
        case 'd':
        case 'D':{
            if (*y != 0){
                printf("%d/%d = %.2f", *x, *y, (float) *x / *y);
            }
            else{
                printf("Cant divide by 0");
            }
            break;
        }
        default:
            printf("\nSorry invalid option.");
    }
    printf("\nGoodbye!");
    return 0;
}
