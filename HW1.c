#include <stdio.h>

//Answer to question 1...
/*
It's
ormal to        ake C! 1o you like it!
*/
//Answer to question 2...
/*
3
0.00
1.50
1  2
*/

//Answer to question 3...
//$   36


//Below is the code for question 4
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float input;
    printf("Enter your distance in Miles:");
    scanf("%f", &input);
    printf("Thanks!\n");
    printf("%.2f Miles = %.2f Kms ", input, input*1.609);
    return 0;
}
