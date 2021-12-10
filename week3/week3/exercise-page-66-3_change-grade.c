#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LENGTH 8
#define NAME_LENGTH 25

//WORKING

typedef struct Student_t {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    int grade;

    struct Student_t *next;
} Student;

Student *find_student(Student *head, char *id)
{
    Student *cur = head;
    while (cur != NULL && strcmp(cur->id, id) != 0){
        cur=cur->next;
    }
    return cur;
}
// ????? UNKNOWN
Student *change_grade(Student *head, char *id, int newgrade)
{
    Student *std = find_student(head, id);
    std = create(std->name, id. newgrade);

    head = remove(head, id);
    return add_student(root, std); 
}