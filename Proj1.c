#include <stdio.h>
#include <stdlib.h>
//Proj 1
int main()
{
    int sid, crn1, crn2, crn1_cred, crn2_cred;
    float cred_cost = 120.25;
    float health = 35.00;
    printf("Enter the Students Id: ");
    scanf("%d", &sid);
    printf("Enter crn/credit hours for first course (like 5665/3): ");
    scanf("%d/%d", &crn1, &crn1_cred);
    printf("Enter crn/credit hours for Second course (like 5665/3): ");
    scanf("%d/%d", &crn2, &crn2_cred);
    printf("Thank You!");

    printf("\nVALENCE COMMUNITY COLLEGE \nORLANDO FL 10101 \n*************************\n");
    printf("\nFee Invoice Prepared for Student V%d\n", sid);
    printf("\n1 Credit Hour = $120.25\n");
    printf("\nCRN\t\tCREDIT HOURS\n");
    printf("%d\t\t%d\t\t$ %.2f", crn1, crn1_cred, (float)crn1_cred*cred_cost);
    printf("\n%d\t\t%d\t\t$ %.2f\n", crn2, crn2_cred, (float)crn2_cred*cred_cost);
    printf("\n\t\tHealth & id fees $ %.2f\n", health);
    float total = health + ((crn1_cred + crn2_cred) * cred_cost);
    printf("----------------------------------------\n\t\tTotal Payments $  %.2f", total);
    return 0;
}
