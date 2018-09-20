/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Student.h * * * * * * * * * * * * * * * * * * * * * */
/* Created by: Jordan Bonecutter * * * * * * * * * * * */
/* 19 September 2018 * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "LinkedList.h"

typedef struct{
	char *name;
	char *school;
	char *major;
	unsigned int grade;
}Student;

typedef LinkedList StudentList;

StudentList *newStudentList();
void appendStudent(StudentList *list, Student *student);
void prependStudent(StudentList *list, Student *student);
void insertStudentAtIndex(StudentList *list, Student *student, uint index);
void deleteFirstStudent(StudentList *list);
void deleteLastStudent(StudentList *list);
void deleteStudentAtIndex(StudentList *list, uint index);
void deleteStudentList(StudentList *list);
Student *studentAtIndex(StudentList *list, uint index);

Student *newStudent();
void deleteStudent(void *data);
