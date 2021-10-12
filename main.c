/******************************************
 * Title: dummy
 * Course: dummy
 * @Author: dummy
 * Lab Section: dummy
 * Professor: dummy
 * Due date: dummy
 * Submission Date: dummy
******************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/************************************************************
Function Name: input_student
Purpose: Check Student input.
Function in parameters: void
Function out parameters: int
Version: 1
Author: 
*************************************************************/
int int_input()
{
    char input_id[16];
    int num = 0;
    int isDigit = 0;
    int j=0;
    
    while(1)
    {
        scanf("%s", input_id);
        printf("%s\n", input_id);
        while(j<strlen(input_id) && input_id[j] != '\0' && isDigit == 0){
            if(input_id[j] > 57 || input_id[j] < 48)
            {
                isDigit = 0;
                printf("Not a valid no...\n");
                break;
            }
            else{
                isDigit = 1;
                num = input_id[j] - '0';
            }
            j++;
        }
        if(isDigit)return num;
    }
}

/************************************************************
Function Name: input_student
Purpose: Check Student input.
Function in parameters: void
Function out parameters: int
Version: 1
Author: 
*************************************************************/
int input_student()
{
    char input_id[16];
    int num = 0;
    int isDigit = 0;
    int j=0;
    
    while(1)
    {
        scanf("%s", input_id);
        while(j<strlen(input_id) && input_id[j] != '\0'){
            if(input_id[j] > 57 || input_id[j] < 48)
            {
                isDigit = 0;
                break;
            }
            else{
                isDigit = 1;
                num = num * 10 + (input_id[j] - '0');
            }
            j++;
        }
        if(isDigit && num > 9999)return num;
        else printf("Please Enter valid Student ID...\n");
    }
}

/************************************************************
Function Name: input_course
Purpose: Check Student input.
Function in parameters: char[8]
Function out parameters: void
Version: 1
Author: 
*************************************************************/
void input_course(char *CourseCode)
{
    int index, isCorrect = 0;
    while (1)
    {
        scanf("%s", CourseCode);
        for (index = 0; CourseCode[index]!='\0'; index++) {
            if(
                (CourseCode[index] >= 'a' && CourseCode[index] <= 'z') &&
                (CourseCode[index] >= '0' && CourseCode[index] <= '9')
            ) {
                isCorrect = 0;
                break;
            }
            else isCorrect = 1;
        }
        if(isCorrect && index > 6) return;
        else printf("Please Enter valid Course Code...\n");
    }
    
}

/************************************************************
Function Name: fill_students
Purpose: Fill Each Student's data in students list on init.
Function in parameters: int[size], int
Function out parameters: void
Version: 1
Author: 
*************************************************************/
void fill_students(int *students, int size)
{
    int row_counter, malloc_size;

    for(row_counter=0;row_counter<size;row_counter++)
    {
        printf("Please enter student ID for student %d: ", row_counter+1);
        // scanf("%d", &students[row_counter]);  
        students[row_counter] = input_student();
        printf("got %d", students[row_counter]);  
    }
}

/************************************************************
Function Name: fill_courses
Purpose: Fill Each Course's code in courses list on init.
Function in parameters: char[size][8], int
Function out parameters: void
Version: 1
Author: 
*************************************************************/
void fill_courses(char **courses, int size)
{
    int course_index, malloc_size;
    
    malloc_size = sizeof(char) * 8;
    for(course_index=0;course_index<size;course_index++)
    {
        courses[course_index] = malloc(malloc_size);
        printf("Please enter course code for course %d: ", course_index+1);
        input_course(courses[course_index]);
        // scanf("%s", courses[course_index]);
    }
}

/************************************************************
Function Name: fill_registration
Purpose: Create an empty registration list directly on startup.
Function in parameters: int[n][3], int, int
Function out parameters: void
Version: 1
Author: 
*************************************************************/
void fill_registration(int **registration, int student_count, int course_count)
{
    int row_counter, student_index, course_index, malloc_size;
    row_counter = 0;
    malloc_size = sizeof(int) * 3;
    for(student_index=0;student_index<student_count;student_index++)
        for(course_index=0;course_index<course_count;course_index++)
        {
            registration[row_counter] = malloc(malloc_size);
            registration[row_counter][0] = student_index;
            registration[row_counter][1] = course_index;
            registration[row_counter][2] = -1;
            row_counter++;
        }
}

/************************************************************
Function Name: menu
Purpose: Show menu and take user's choice.
Function in parameters: void
Function out parameters: int
Version: 1
Author: 
*************************************************************/
int menu()
{
    char choice;
    printf("Please choose one of the following actions:\n");
    printf("1- Register a student in a course\n");
    printf("2- Drop a student's course\n");
    printf("3- Print registration table\n");
    printf("4- Quit\n");
    printf("Please enter action number: ");
    
    scanf("\n%c", &choice);
    return choice;
}

/************************************************************
Function Name: print_registration
Purpose: Print Registration list data only values of each student as set
Function in parameters: int[mxn], int, int
Function out parameters: void
Version: 1
Author: 
*************************************************************/
void print_registration(int **registration, int student_count, int course_count)
{
    int student_index, course_index, row_index, max;
    row_index = 0;
    max=student_count * course_count;
    printf("[ ");
    for(student_index=0;student_index<student_count;student_index++)
    {
        printf("[");
        for(course_index=0;course_index<course_count;course_index++)
        {
            // How to get -1
            printf(" %d", registration[row_index][2]);
            
            if(course_index+1 < course_count)printf(",");
            row_index++;
        }
        printf(" ]");
        if(student_index+1 < student_count)printf(",");

    }
    printf(" ]\n");
}

/************************************************************
Function Name: register_modify
Purpose: Enroll/Drop Student from a course by setting its value.
Function in parameters: int[n], char[m][8], int[nxm][3], int, int
Function out parameters: void
Version: 1
Author: 
*************************************************************/
void register_modify(int *students, char **courses, int **registration, int student_count, int course_count, int value)
{
    int studentID;
    char courseCode[8];
    int student_index, course_index, flag;
    flag=1;
    while(flag){
        printf("Please enter student ID: ");
        // scanf("%d", &studentID);
        studentID = int_input();

        for(student_index=0;student_index<student_count;student_index++)
            if(studentID == students[student_index])
            {
                flag=0;
                break;
            }

        if(flag)printf("Incorrect student ID: %d\n", studentID);
        
    }
    
    flag=1;
    while(flag){
        printf("Please enter course code: ");
        scanf("%s", courseCode);

        for(course_index=0;course_index<course_count;course_index++)
            if(!strcmp(courseCode, courses[course_index]))
            {
                flag=0;
                break;
            }
        if(flag)printf("Incorrect Course Code: %s\n", courseCode);
    }

    flag = student_index * course_count + course_index;  // Check if we can fetch details directly
    if(students[registration[flag][0]] == studentID && registration[flag][1] == course_index)
    {
        registration[flag][2] = value;
        print_registration(registration, student_count, course_count);
    }
    else printf("Try again...");

}

/***************************************************************
Function Name: main
Purpose: Main function which runs and calls all other finctions
Function in parameters: void
Function out parameters: int
Version: 1
Author: 
***************************************************************/
int main()
{
    int *students;
    int **registration;
    int student_count, course_count;
    char **courses;

    // Allocating Memory and data for students
    printf("How many students will you like to register: ");
    // scanf("%d", &student_count);
    student_count = int_input();
    students = malloc(student_count * sizeof(int));
    fill_students(students, student_count);
    
    // Allocating Memory and data for Courses
    printf("How many courses are you offering: ");
    // scanf("%d", &course_count);    
    course_count = int_input();
    courses = malloc(8 * course_count * sizeof(char));
    fill_courses(courses, course_count);

    // Allocating Memory and data for Registration
    registration = malloc(3 * student_count * course_count * sizeof(int));
    fill_registration(registration, student_count, course_count);

    while(1){
        switch (menu())
        {
        case '4':
            // Empty all the data structure
            free(students);
            free(courses);
            free(registration);
            return 0;
        case '3':
            print_registration(registration, student_count, course_count);
            break;
        case '2':
            register_modify(students, courses, registration, student_count, course_count, 0);
            break;
        case '1':
            register_modify(students, courses, registration, student_count, course_count, 1);
            break;
        default:
            printf("Error Unknown action:\nTry again...\n");
            break;
        }
    }
    // Empty all the data structure
    free(students);
    free(courses);
    free(registration);
    return 0;
}