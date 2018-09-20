/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* LinkedList.h  * * * * * * * * * * * * * * * * * * * */
/* Created by: Jordan Bonecutter * * * * * * * * * * * */
/* 19 September 2018 * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef unsigned int uint;
typedef void (*Releaser)(void *data);

typedef struct{
	uint length;
}LinkedList;

LinkedList *newLinkedList(Releaser itemReleaser);
void appendItem(LinkedList *list, void *data);
void prependItem(LinkedList *list, void *data);
void insertItem(LinkedList *list, void *data, uint index);
void deleteFirstItem(LinkedList *list);
void deleteLastItem(LinkedList *list);
void deleteItemAtIndex(LinkedList *list, uint index);
void deleteList(LinkedList *list);
