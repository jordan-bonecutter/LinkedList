/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* LinkedList.c  * * * * * * * * * * * * * * * * * * * */
/* Created by: Jordan Bonecutter * * * * * * * * * * * */
/* 19 September 2018 * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "LinkedList.h"
#include <assert.h>
#include <stdlib.h>

typedef struct element Element;
typedef struct list List;

Element *newElement(void *data, List *list);
void deleteElement(Element *element);

// We're going to do some data hiding in the OOP way
struct element{
    Element *next;
    Element *prev;
    void *data;
	List *list;
};

// Again, under the hood we're using a different struct than the one
// we're declaring in the header for better data hiding
struct list{
	uint length;
	Element *first;
	Element *last;
	Releaser itemReleaser;
};

LinkedList *newLinkedList(Releaser itemReleaser)
{
	List *res = malloc(sizeof(List));
	res->length = 0;
	res->first = NULL;
	res->last = NULL;
	res->itemReleaser = itemReleaser;

	return (LinkedList *)res;
}

void appendItem(LinkedList *in, void *data)
{
	assert(in);
	assert(data);
	List *list = (List *)in;
	Element *append = newElement(data, list);
	append->next = list->last;
	append->prev = NULL;
	if(list->last)
	{
		list->last->prev = append; 
	}
	list->last = append;
	if(!list->first)
	{
		list->first = append;
	}
	list->length++;
}

void prependItem(LinkedList *in, void *data)
{
	assert(in);
	assert(data);
	List *list = (List *)in;
	Element *prepend = newElement(data, list);
	prepend->prev = list->first;
	prepend->next = NULL;
	if(list->first)
	{
		list->first->next = prepend;
	}
	list->first = prepend;
	if(!list->last)
	{
		list->last = prepend;
	}
	list->length++;
}

void insertItem(LinkedList *in, void *data, uint index)
{
	assert(in);
	assert(data);
	List *list = (List *)in;
	Element *insert = newElement(data, list), *elementAtIndex = list->first;

	if(index == 0)
	{
		insert->next = list->last;
		insert->prev = NULL;
		if(list->last)
		{
			list->last->prev = insert; 
		}
		list->last = insert;
		if(!list->first)
		{
			list->first = insert;
		}
		list->length++;
	}
	else if(index == list->length-1)
	{
		insert->next = NULL;
		insert->prev = list->first;
		if(list->first)
		{
			list->first->next = insert;
		}
		list->first = insert;
		if(!list->last)
		{
			list->last = insert;
		}			
		list->length++;
	}
	else if(index < list->length)
	{
		for(uint n = 0; n < index; n++)
		{
			elementAtIndex = elementAtIndex->prev;
		}
		elementAtIndex->next->prev = insert;
		insert->next = elementAtIndex->next;
		insert->prev = elementAtIndex;
		elementAtIndex->next = insert;
		list->length++;
	}
}

void deleteFirstItem(LinkedList *in)
{
	List *list = (List *)in;
	Element *temp = list->first;
	assert(list);

	if(list->first)
	{
		list->first = list->first->prev;
		if(list->first)
		{
			list->first->next = NULL;
		}
		deleteElement(temp);
		list->length--;
	}
}

void deleteLastItem(LinkedList *in)
{
	List *list = (List *)in;
	Element *temp = list->last;
	assert(list);

	if(list->last)
	{
		list->last = list->last->next;
		if(list->last)
		{
			list->last->prev = NULL;
		}
		deleteElement(temp);
		list->length--;
	}
}

void deleteItemAtIndex(LinkedList *in, uint index)
{
	List *list = (List *)in;
	assert(list);
	Element *elementAtIndex = list->first;
	if(index == 0)
	{
		deleteFirstItem(in);
	}
	else if(index == list->length - 1)
	{
		deleteLastItem(in);
	}
	else if(index < list->length)
	{
		for(uint n = 0; n < index; n++)
		{
			elementAtIndex = elementAtIndex->prev;
		}
		elementAtIndex->prev->next = elementAtIndex->next;
		elementAtIndex->next->prev = elementAtIndex->prev;
		deleteElement(elementAtIndex);
		list->length--;
	}
}

void deleteList(LinkedList *in)
{
	List *list = (List *)in;
	assert(list);
	while(list->length)
	{
		deleteFirstItem(in);
	}
	free(in);
}

Element *newElement(void *data, List *list)
{
	Element *res = malloc(sizeof(Element));
	res->next = NULL;
	res->prev = NULL;
	res->data = data;
	res->list = list;
	return res;
}

void deleteElement(Element *e)
{
	assert(e);
	e->list->itemReleaser(e->data);
	free(e);
}
