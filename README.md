# LinkedList
A lightweight LinkedList object for C

The Student files show a possible application of the LinkedList object by decalring a typedef with a new list (StudentList).
This is similar to inheriting from a superclass in OO langs like OBJ-C, Java, C++, etc

Upon further inspection, you may notice that the list used in LinkedList.c is completely different from the one declared in LinkedList.h. I did this to achieve data hiding. Programmers need not access any of the internal structures of the list. If you want to do so, simply copy the List typedef found in LinkedList.c into whatever file you are using and you may access the members that way.
