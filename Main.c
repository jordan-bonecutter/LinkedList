/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Main.c  * * * * * * * * * * * * * * * * * * * * * * */
/* Created by: Jordan Bonecutter * * * * * * * * * * * */
/* 19 September 2018 * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Student.h"

int main()
{
	StudentList *myList = newStudentList();
	appendStudent(myList, newStudent());
	appendStudent(myList, newStudent());
	appendStudent(myList, newStudent());
	appendStudent(myList, newStudent());
	appendStudent(myList, newStudent());
	appendStudent(myList, newStudent());
	appendStudent(myList, newStudent());
	prependStudent(myList, newStudent());
	prependStudent(myList, newStudent());
	prependStudent(myList, newStudent());
	prependStudent(myList, newStudent());
	prependStudent(myList, newStudent());
	prependStudent(myList, newStudent());
	insertStudentAtIndex(myList, newStudent(), 3);
	insertStudentAtIndex(myList, newStudent(), 4);
	insertStudentAtIndex(myList, newStudent(), 5);
	insertStudentAtIndex(myList, newStudent(), 6);
	insertStudentAtIndex(myList, newStudent(), 7);
	deleteFirstStudent(myList);
	deleteFirstStudent(myList);
	deleteFirstStudent(myList);
	deleteLastStudent(myList);
	deleteLastStudent(myList);
	deleteLastStudent(myList);
	deleteStudentAtIndex(myList, 2);
	deleteStudentAtIndex(myList, 4);
	deleteStudentList(myList);
}
