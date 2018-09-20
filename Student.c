/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Student.c * * * * * * * * * * * * * * * * * * * * * */
/* Created by: Jordan Bonecutter * * * * * * * * * * * */
/* 19 September 2018 * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Student.h"
#include <stdlib.h>

StudentList *newStudentList()
{
	return newLinkedList(&deleteStudent);
}

void appendStudent(StudentList *list, Student *student)
{
	appendItem(list, student);
}

void prependStudent(StudentList *list, Student *student)
{
	prependItem(list, student);
}

void insertStudentAtIndex(StudentList *list, Student *student, uint index)
{
	insertItem(list, student, index);
}

void deleteFirstStudent(StudentList *list)
{
	deleteFirstItem(list);
}

void deleteLastStudent(StudentList *list)
{
	deleteLastItem(list);
}

void deleteStudentAtIndex(StudentList *list, uint index)
{
	deleteItemAtIndex(list, index);
}

void deleteStudentList(StudentList *list)
{
	deleteList(list);
}

Student *newStudent()
{
	Student *res = malloc(sizeof(Student));
	res->name = NULL;
	res->school = NULL;
	res->major = NULL;
	res->grade = 0;

	return res;
}

void deleteStudent(void *data)
{
	Student *s = (Student *)data;
	if(s->name)
	{
		free(s->name);
		s->name = NULL;
	}
	if(s->school)
	{
		free(s->school);
		s->school = NULL;
	}
	if(s->major)
	{
		free(s->major);
		s->major = NULL;
	}
	free(s);
}
