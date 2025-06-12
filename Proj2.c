#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Project 2
int main()
{
    int student_id;
    int course_uno = 0, course_dos = 0;
    int course_count;
    int course_4587_cred = 4;
    int course_4599_cred = 3;
    int course_8997_cred = 1;
    int course_9696_cred = 3;
    int course_uno_cred = 0;
    int course_dos_cred = 0;
    float cred_cost = 120.25;
    float health = 35.00;
    bool invalid = false;
    printf("Enter the Students Id: ");
    scanf("%d", &student_id);
    printf("\nEnter how may courses taken(up to 2): ");
    scanf("%d", &course_count);
    switch(course_count) {
        case 0: {
            break;
        }

        case 1: {
            printf("\nEnter the course number:");
            scanf("%d", &course_uno);
            break;
        }
        case 2: {
            printf("\nEnter the 2 course numbers separated by - :(like 2356-8954)");
            scanf("%d-%d", &course_uno, &course_dos);
            break;
        }
        default:{
            printf("\nSorry, we cant process your request this time-invalid number of courses.");
            invalid = true;
        }
    }
    if (invalid == false) {
        if (course_uno != 0) {
            switch(course_uno) {
                case 4587: {
                    course_uno_cred = course_4587_cred;
                    break;
                }
                case 4599: {
                    course_uno_cred = course_4599_cred;
                    break;
                }
                case 8997: {
                    course_uno_cred = course_8997_cred;
                    break;
                }
                case 9696: {
                    course_uno_cred = course_9696_cred;
                    break;
                }
                default: {
                    printf("\nSorry invalid entry!");
                    invalid = true;
                }
            }
        }
        if (course_dos != 0) {
            switch(course_dos) {
                case 4587: {
                    course_dos_cred = course_4587_cred;
                    break;
                }
                case 4599: {
                    course_dos_cred = course_4599_cred;
                    break;
                }
                case 8997: {
                    course_dos_cred = course_8997_cred;
                    break;
                }
                case 9696: {
                    course_dos_cred = course_9696_cred;
                    break;
                }
                default: {
                    printf("\nSorry invalid entry!");
                    invalid = true;
                }
            }

        }
        if (invalid == false) {
            printf("\nVALENCE COMMUNITY COLLEGE \nORLANDO FL 10101 \n*************************\n");
            printf("\nFee Invoice Prepared for Student V%d\n", student_id);
            if (course_count != 0) {
                printf("\n1 Credit Hour = $120.25\n");
                printf("\nCRN\t\tCREDIT HOURS\n");
            }
            int total_cred = 0;
            if (course_uno != 0){
                printf("%d\t\t%d\t\t$ %.2f", course_uno, course_uno_cred, (float)course_uno_cred*cred_cost);
                total_cred += course_uno_cred;
            }
            if (course_dos != 0){
                printf("\n%d\t\t%d\t\t$ %.2f\n", course_dos, course_dos_cred, (float)course_dos_cred*cred_cost);
                total_cred += course_dos_cred;
            }
            printf("\n\t\tHealth & id fees $ %.2f\n", health);
            float total = health + (total_cred * cred_cost);
            printf("----------------------------------------\n\t\tTotal Payments $  %.2f", total);
        }
        else {
            printf("\nTry again. Goodbye!");
        }
    }
    else {
        printf("\nTry again. Goodbye!");
    }
    return 0;
}
