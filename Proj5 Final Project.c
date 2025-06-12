#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//Final Project

typedef struct student {
    int sid;
    char name[100];
    int classes[4];
} student;
bool check_for_id(int id, student students[], int student_len){
    int iter;
    bool exists = false;
    for (iter=0; iter<student_len; iter++){
        if (students[iter].sid == id){
            exists = true;
            break;
        }
    }
    return exists;
}
int search_student(student students[], int student_len){
    printf("\nEnter the student's id: ");
    int s_sid;
    scanf("%d", &s_sid);
    int iter;
    bool student_found = false;
    for (iter=0; iter<student_len; iter++){
        if (students[iter].sid == s_sid){
            printf("Found student with id %d, %s", s_sid, students[iter].name);
            student_found = true;
            return iter;
            break;
        }
    }
    if (!student_found) {
        printf("\nNo Student found!");
        return 999;
    }
}
int crn_credit(int crn_num){
    //Returns the credits of a crn number
    switch (crn_num){
        case 8977:
        case 8997:
            return 1;
        case 9856:
            return 2;
        case 4599:
        case 9696:
            return 3;
        case 4587:
            return 4;
        case 1232:
        case 8520:
            return 5;

        default: {
            printf("\nSorry invalid crn! %d", crn_num);
            return 0;
        }
    }
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
        case 1232: {
            printf("MAT 531");
            break;
        }
        case 9856: {
            printf("STA 100");
            break;
        }
        case 8520: {
            printf("TNV 400");
            break;
        }
        case 8977: {
            printf("CMP 100");
            break;
        }
        default: {
            printf("\nINVALID CRN");
        }
    }
}
void remove_class(int classes[], int index, int array_length)
{
    int i;
    for(i = index; i < array_length - 1; i++) classes[i] = classes[i + 1];
    classes[3] = 0;
}
void print_all_courses(){
    int crns[]= {4587, 4599, 8997, 9696, 1232, 9856, 8520, 8977};
    int crn_count = 7;
    int iter;
    printf("\nCourses available\nCRN\tCR_PREFIX\tCR_HOURS");
    for (iter = 0; iter<=crn_count; iter++){
        printf("\n%d\t", crns[iter]);
        print_crn_prefix( crns[iter]);
        printf("\t\t\t%d", crn_credit(crns[iter]));

    }
}
void print_invoice(student students[], int student_len, int student_idx) {
    if (student_idx != 999) {
        float cred_cost = 120.25;
        float health = 35;
        printf("\nVALENCE COMMUNITY COLLEGE \nORLANDO FL 10101 \n---------------------\n");
        printf("\nFee Invoice Prepared for Student %d-%s\n", students[student_idx].sid, students[student_idx].name);
        printf("\n1 Credit Hour = $120.25\n");
        printf("\nCRN\tCR_PREFIX\tCR_HOURS\n");
        int crn_iter;
        int total_cred = 0;
        for (crn_iter = 0; crn_iter <= 3; crn_iter++) {
            if (students[student_idx].classes[crn_iter] != 0) {
                printf("\n%d\t", students[student_idx].classes[crn_iter]);
                print_crn_prefix(students[student_idx].classes[crn_iter]);
                printf("\t\t%d\t\t$ %.2f", crn_credit(students[student_idx].classes[crn_iter]),
                       (float) crn_credit(students[student_idx].classes[crn_iter]) * cred_cost);
                total_cred += crn_credit(students[student_idx].classes[crn_iter]);
            }
        }
        printf("\n\n\t\t\tHealth & id fees $ %.2f\n\n", health);
        float total = health + (total_cred * cred_cost);
        printf("------------------------------------------------\n\t\t\tTotal Payments $  %.2f", total);
    }
}
void add_del_course(student students[], int student_len){
    printf("\nEnter the student's id: ");
    int current_sid;
    scanf("%d", &current_sid);
    int iter;
    bool student_found = false;
    int found_std_idx;
    for (iter=0; iter<student_len; iter++){
        if (students[iter].sid == current_sid) {
            student_found = true;
            found_std_idx = iter;
            break;
        }
    }
    if (student_found){
        printf("\nHere are the courses [%s] is taking:", students[found_std_idx].name);
        int class_iter;
        printf("\n\t\tCRN\tPREFIX\t\tCR. HOURS");
        for (class_iter = 0; class_iter<=3; class_iter++) {
            if (students[iter].classes[class_iter] != 0 ){
                printf("\n\t\t%d\t ", students[iter].classes[class_iter]);
                print_crn_prefix(students[iter].classes[class_iter]);
                printf("\t%d", crn_credit(students[iter].classes[class_iter]));
            }
        }
        printf("\nChoose from:\nA- Add a new course for [%s]\nD- Delete a course from [%s]'s schedule\nC- Cancel operation\n: ", students[found_std_idx].name, students[found_std_idx].name);
        char choice;
        scanf(" %c", &choice);
        switch (choice){
            case 'A':
            case 'a':{
                int class_iter;
                bool can_take_more = false;
                for (class_iter = 0; class_iter<=3; class_iter++) {
                    if (students[found_std_idx].classes[class_iter] == 0){
                        can_take_more = true;
                        print_all_courses();
                        int course_crn;
                        printf("\nEnter course Number to add: ");
                        scanf(" %d", &course_crn);
                        if (crn_credit(course_crn) > 0) {
                            students[found_std_idx].classes[class_iter] = course_crn;
                            printf("[%d ", course_crn);
                            print_crn_prefix(course_crn);
                            printf("] was added successfully!");
                        }
                        else printf("Invalid CRN!");
                        break;
                    }
                }
                if (!can_take_more) printf("%s can't take anymore classes already has 4", students[found_std_idx].name);
                break;
            }
            case 'D':
            case 'd':{
                printf("\nEnter course Number to delete: ");
                int course_crn;
                scanf(" %d", &course_crn);
                int class_iter;
                for (class_iter = 0; class_iter<=3; class_iter++) {
                    if (students[found_std_idx].classes[class_iter] == course_crn){
                        remove_class(students[found_std_idx].classes, class_iter, 4);
                        printf("[%d ", course_crn);
                        print_crn_prefix(course_crn);
                        printf("] was removed successfully!");
                        break;
                    }
                }
                char choice;
                printf("\nWant to display the new invoice? Y/N: ");
                scanf(" %c", &choice);
                switch (choice){
                    case 'Y':
                    case 'y': {
                        print_invoice(students, student_len, found_std_idx);
                        break;
                    }
                    default: break;
                }

                break;
            }
            case 'C':
            case 'c':{
                printf("\nCancelled!");
                break;
            }
            default:{
                printf("\nInvalid choice!");
            }

        }
    }
    else {
        printf("\nStudent with id %d not found!", current_sid);
    }
}

int add_test_student(student students[], int student_len){
    //TEST STUDENT
    students[0].sid = 8008;
    strcpy(students[0].name, "TEST");
    students[0].classes[0] = 4587;
    students[0].classes[1] = 4599;
    students[0].classes[2] = 0;
    students[0].classes[3] = 8520;
    student_len++;
    printf("DOES TEST STUDENT EXIST: %d", check_for_id(8008, students, student_len));
    return student_len;
}
int new_student(student students[], int student_len){
    printf("\nEnter the student's id: ");
    int new_sid;
    scanf("%d", &new_sid);
    if (check_for_id(new_sid, students, student_len)){
        printf("\nStudent with id %d already exists", new_sid);
    }
    else {
        students[student_len].sid = new_sid;
        printf("\nEnter student's name:");
        fflush(stdin);
        fgets(students[student_len].name, 100, stdin);
        printf("Enter how many courses [%s] is taking (up to 4 courses)?: ", students[student_len].name);
        int course_count;
        scanf("%d", &course_count);
        print_all_courses();
        if (course_count > 4 || course_count < 0){
            printf("\nInvalid course count 4 max! Please use option two to add valid courses for this new student now");
        }
        else {
            int iter;
            printf("\nEnter the %d course numbers: ", course_count);
            for (iter = 0; iter< course_count; iter++) {
                int temp_crn;
                scanf("%d", &temp_crn);
                if (crn_credit(temp_crn) > 0) {
                    students[student_len].classes[iter] = temp_crn;
                } else {
                    printf("\nPlease use option two to add courses now for this new student!");
                    fflush(stdin);
                    break;
                }
            }
        }

        student_len++;

    }
    return student_len;
}
int main(){
    printf("\nWelcome!\n");
    student students[100];
    int student_len = 0;
    //TESTING STUDENT
    //student_len = add_test_student(students, student_len);
    bool should_end = false;
    while (!should_end) {
        int selection;
        printf("\nChoose from the following options:\n\t1- Add a new student\n\t2- Add/Delete a course\n\t3- Search for a student\n\t4- Print fee invoice\n\t0- Exit program");
        printf("\n\nEnter your selection:");
        scanf("%d", &selection);
        switch(selection){
            case 0: {
                should_end = true;
                break;
            }
            case 1:{ // New Student
                student_len = new_student(students, student_len);
                break;
            }
            case 2:{ // Add-Delete Course for student
                add_del_course(students, student_len);
                break;
            }
            case 3:{ // Search for student by id
                search_student(students, student_len);
                break;
            }
            case 4:{ // Print Fee invoice
                int student_idx;
                student_idx = search_student(students, student_len);
                print_invoice(students, student_len, student_idx);
                break;
            }
            case 5: { // DEBUG OUTPUT INFO
                int iter;
                printf("Size of students %d", student_len);
                for (iter=0; iter<student_len; iter++){
                    printf("\n ----- \n %d %d %s crns: ", iter, students[iter].sid, students[iter].name);
                    int class_iter;
                    for (class_iter = 0; class_iter<=3; class_iter++){
                        printf("%d ", students[iter].classes[class_iter]);
                    }
                    printf("\n -----");
                }
                break;
            }
            default: {
                printf("\nInvalid Selection.");
                break;
            }
        }
        printf("\n--------------------");
    }
    printf("\nBye!");
    return 0;
}
