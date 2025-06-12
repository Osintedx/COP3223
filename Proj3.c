#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Project 3
int crn_credit(int crn_num){
    int result;
    switch (crn_num){
        case 4587:{
            result = 4;
            break;
        }
        case 4599:{
            result = 3;
            break;
        }
        case 8997:{
            result = 1;
            break;
        }
        case 9696:{
            result = 5;
            break;
        }
        case 4580:{
            result = 3;
            break;
        }
        case 4581:{
            result = 4;
            break;
        }
        case 4582:{
            result = 2;
            break;
        }
        case 4583:{
            result = 2;
            break;
        }
        case 3587:{
            result = 4;
            break;
        }
        case 4519:{
            result = 3;
            break;
        }
        case 6997:{
            result = 1;
            break;
        }
        case 9494:{
            result = 3;
            break;
        }
        default: {
            printf("\nSorry invalid crn! %d", crn_num);
            result = 0;
        }
    }
    return result;
}
void print_crn_prefix(int crn_num){
    //Prints the prefix for a crn number
    switch (crn_num){
        case 4587:{
            printf("MAT 236");
            break;
        }
        case 4599:{
            printf("COP 220");
            break;
        }
        case 8997:{
            printf("GOL 124");
            break;
        }
        case 9696:{
            printf("COP 100");
            break;
        }
        case 4580:{
            printf("MAT 230");
            break;
        }
        case 4581:{
            printf("MAT 231");
            break;
        }
        case 4582:{
            printf("MAT 232");
            break;
        }
        case 4583:{
            printf("MAT 233");
            break;
        }
        case 3587:{
            printf("MAT 256");
            break;
        }
        case 4519:{
            printf("COP 420");
            break;
        }
        case 6997:{
            printf("GOL 127");
            break;
        }
        case 9494:{
            printf("COP 101");
            break;
        }
        default: {
            printf("\nINVALID CRN");
        }
    }
}
int main()
{
    char choice = 'Y';
    while (choice == 'Y') {
        bool invalid = false;
        int student_id=0, course_count=0;
        int crn1 = 0, crn2 = 0, crn3 = 0;
        int crn_iter=1;
        int total_cred = 0;
        printf("Enter the Students Id: ");
        scanf("%d", &student_id);
        bool contiune_asking_count = false;
        printf("\nEnter how many courses-up to 3 : ");
        scanf("%d", &course_count);
        while (course_count < 0 || course_count > 3){
            printf("\nInvalid number of courses (up to 3)");
            scanf("%d", &course_count);
        }
        switch(course_count){
            case 0: {
                break;
            }
            case 1:{
                printf("\nEnter the course number:");
                scanf("%d", &crn1);
                break;
            }
            case 2:{
                printf("\nEnter the 2 course numbers:");
                scanf("%d %d", &crn1, &crn2);
                break;
            break;
            }
            case 3:{
                printf("\nEnter the 3 course numbers:");
                scanf("%d %d %d", &crn1, &crn2, &crn3);
                break;
            }
            default:{
                printf("\nSorry, we cant process your request this time-invalid number of courses.");
                invalid = true;
                break;
            }
        }
        if (invalid == false){
            if (course_count != 0) {
                for (crn_iter = 1; crn_iter <= course_count; crn_iter++){
                    if (crn_iter == 1 && crn1 != 0){
                        total_cred += crn_credit(crn1);
                    }
                    else if (crn_iter == 2 && crn2 != 0){
                        total_cred += crn_credit(crn2);
                    }
                    else if (crn_iter == 3 && crn3 != 0){
                        total_cred += crn_credit(crn3);
                    }
                }
            }
            if (total_cred > 7){
                printf("\nSorry we cant process more than 7 credit hours!");
                invalid = true;
            }
        }
        if (invalid == false) {
            float cred_cost = 120.25;
            float health = 35;
            printf("\nVALENCE COMMUNITY COLLEGE \nORLANDO FL 10101 \n---------------------\n");
            printf("\nFee Invoice Prepared for Student V%d\n", student_id);
            printf("\n1 Credit Hour = $120.25\n");
            printf("\nCRN\tCR_PREFIX\tCR_HOURS\n");
            for (crn_iter = 1; crn_iter <= course_count; crn_iter++){
                if (crn_iter == 1 && crn1 != 0){
                    printf("\n%d\t", crn1);
                    print_crn_prefix(crn1);
                    printf("\t\t%d\t\t$ %.2f", crn_credit(crn1), (float)crn_credit(crn1)*cred_cost);
                }
                else if (crn_iter == 2 && crn2 != 0){
                    printf("\n%d\t", crn2);
                    print_crn_prefix(crn2);
                    printf("\t\t%d\t\t$ %.2f", crn_credit(crn2), (float)crn_credit(crn2)*cred_cost);
                }
                else if (crn_iter == 3 && crn3 != 0){
                    printf("\n%d\t", crn3);
                    print_crn_prefix(crn3);
                    printf("\t\t%d\t\t$ %.2f", crn_credit(crn3), (float)crn_credit(crn3)*cred_cost);
                }
            }
            printf("\n\n\t\t\tHealth & id fees $ %.2f\n\n", health);
            float total = health + (total_cred * cred_cost);
            printf("------------------------------------------------\n\t\t\tTotal Payments $  %.2f", total);
        }
        else {
            printf("\nTry again. Goodbye!");
        }
        printf("\nWould you like to print another invoice? Y=yes, N=No : ");
        scanf(" %c", &choice);
        while (!(choice == 'Y' || choice == 'N')){
            printf("\nInvalid Entry (it has to be Y or N):");
            scanf(" %c", &choice);
        }

    }
    printf("\nBye!");
    return 0;
}

