#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
    int x;
    int y;
    struct pointType* next;
} PointType;

typedef struct linkedList {
    struct pointType* head;
    int size;
} LinkedList;

extern LinkedList* createLinkedList();
extern int destroyLinkedList(LinkedList* li);
extern int isEmptyLinkedList(LinkedList* li);
extern int sizeLinkedList(LinkedList* li);
extern LinkedList* insertFirstLinkedList(LinkedList* li, PointType item);
extern LinkedList* insertLastLinkedList(LinkedList* li, PointType item);
extern LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item);
extern LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item);
extern PointType deleteFirstLinkedList(LinkedList* li);
extern PointType deleteLastLinkedList(LinkedList* li);
extern PointType deleteAtLinkedList(LinkedList* li, int at);
extern PointType getItemLinkedList(LinkedList* li, int pos);
extern LinkedList* replaceItemLinkedList(LinkedList* li, int pos, PointType item);
extern PointType* nextItemLinkedList(LinkedList* li, PointType* pre);
extern int printLinkedList(LinkedList* li);

#endif
