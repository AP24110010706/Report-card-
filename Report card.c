#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    char grade;
    struct Student *next;
};

struct Student *head = NULL;

char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 40) return 'D';
    else return 'F';
}

void insertStudent() {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->grade = calculateGrade(newNode->marks);
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Student *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("\nStudent Added Successfully!\n");
}

void displayStudents() {
    struct Student *temp = head;

    if (temp == NULL) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n------ REPORT CARDS ------\n");
    while (temp != NULL) {
        printf("Roll No: %d\n", temp->roll);
        printf("Name   : %s\n", temp->name);
        printf("Marks  : %.2f\n", temp->marks);
        printf("Grade  : %c\n", temp->grade);
        printf("---------------------------\n");
        temp = temp->next;
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("\nStudent Found!\n");
            printf("Name  : %s\n", temp->name);
            printf("Marks : %.2f\n", temp->marks);
            printf("Grade : %c\n", temp->grade);
            return;
        }
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

void updateStudent() {
    int roll;
    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);
            temp->grade = calculateGrade(temp->marks);

            printf("\nRecord Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    struct Student *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (temp->roll == roll) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("\nRecord Deleted Successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== REPORT CARD MANAGEMENT =====");
        printf("\n1. Add Student");
        printf("\n2. Display Report Cards");
        printf("\n3. Search Student");
        printf("\n4. Update Marks");
        printf("\n5. Delete Student");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: insertStudent(); break;
        case 2: displayStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateStudent(); break;
        case 5: deleteStudent(); break;
        case 6: exit(0);
        default: printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}