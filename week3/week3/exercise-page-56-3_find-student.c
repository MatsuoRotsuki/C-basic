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

Student *findstudent(Student *head, char *targetid){
    Student *cur=head;
    while (cur!=NULL)
    {
        if(strcmp(cur->id, targetid) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
