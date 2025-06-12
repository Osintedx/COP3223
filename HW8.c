#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define maxStds 100

typedef struct
{
    int id;
    char name[50];
    int crns[4];
} student;
//______________________
void printAll (student *);
void printCrns ( int *);
int count9696 ( student *);
int searchById ( student *, int);
int searchByName ( student *, char *);
//______________________
int main()
{
    student A[maxStds] = { {1254,"Zayd Boustique", {9696}},
                           {6589,"Allal Bensouda", {4587,9696}},
                           {1587,"Neta  Benchrifa"},
                           {6089,"Anita Jones", {8974,6985,2359,70052}},
                           {7136,"John Smith", {5623,9696,58736}}
    };
    int id;
    int index;

    char name[50];

    printAll(A);

    printf("\n________________________\n");
    printf("9696 students enrolled %d\n", count9696(A));
    printf ("Enter the Name to search for: ");
    gets(name);



        index = searchByName ( A, name);

        if (index == -1 ) printf ("%d NOT found\n", id);
        else
        {
            printf ("Student found...\n");
            printf("[id: %d] <-->[Name: %s]", id, A[index].name);
        }

        printf("\n________________________\n");


    printf ("Now, enter the id to search for: ");
    scanf("%d", &id);

    index = searchById (A, id);


    if (index == -1 ) printf ("%d NOT found\n", id);
    else
    {
        printf ("Student found...\n");
        printf("[id: %d] <-->[Name: %s]", id, A[index].name);
        printCrns (A[index].crns);
    }
    printf("\n________________________\n");



    return 0;
}

void printCrns ( int * crnArray)
{
    for (int j =0; j<4; j++)
    {
        if (crnArray[j] != 0)
            printf("[%d] ", crnArray[j]);

    }

}
//______________________
void printAll (student * array)
{
    int i;
    for ( i= 0; i<maxStds; i++)
    {
        if ( array[i].id !=0 )
        {
            printf("\n\t\t%d\t%s\t\t", array[i].id , array[i].name);
            printCrns(array[i].crns);
            printf("\n");
        }
    }

}
//______________________
int count9696 ( student * array)
{
    int iter;
    int count96 = 0;
    for (iter=0; iter<maxStds; iter++){
        int class_iter;
        for (class_iter=0; class_iter<=3; class_iter++){
            if (array[iter].crns[class_iter] == 9696){
                count96++;
                break;
            }
        }

    }
    return count96;
}
//______________________
int searchById ( student * array, int id)
{
    int iter;
    bool student_found = false;
    for (iter=0; iter<maxStds; iter++){
        if (array[iter].id == id){
            student_found = true;
            return iter;
            break;
        }
    }
    if (!student_found) {
        return -1;
    }
}
//______________________
int strcicmp(char const *a, char const *b) //STRING COMPARE INSENSITIVE
{
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}
int searchByName ( student * array, char * name)
{
    {
        int iter;
        bool student_found = false;
        for (iter=0; iter<maxStds; iter++){
            if (strcicmp(array[iter].name, name) == 0){
                student_found = true;
                return iter;
                break;
            }
        }
        if (!student_found) {
            return -1;
        }
    }
}

