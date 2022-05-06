#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdint.h>
#include "StandardType.h"

/* Type node of linked list */
struct Node{
    int Data;
    struct Node* NextNode;
};

typedef struct Node LinkedList_Node_Type;

/*
*   Description : Initialize linked list
*/
void LinkedList_Init(LinkedList_Node_Type** LinkedListBaseAddr,int NumArr, int* DataArr);

/*
*   Description : Print Linked List data
*/
LinkedList_Node_Type* LinkedList_CreateNode(int NewNodeData);

/*
*   Description : Insert a node into Linked List
*/
void LinkedList_InsertNode(LinkedList_Node_Type** LinkedListBaseAddr, int PosNode, LinkedList_Node_Type* Node);

/*
*   Description : Delete a node in Linked List
*/
void LinkedList_DeleteNode(LinkedList_Node_Type** LinkedListBaseAddr, int PosNode);

/*
*   Description : Get data of node in Linked List
*/
int LinkedList_GetDataNode(LinkedList_Node_Type* LinkedListBaseAddr, int PosNode);

/*
*   Description : Print linked list data
*/
void LinkedList_PrintList(LinkedList_Node_Type* LinkedListBaseAddr);

/*
*   Description : Print linked list data
*/
void LinkedList_FreeList(LinkedList_Node_Type* LinkedListBaseAddr);

/*
*   Description : Replace data of all node in Linked List
*/
void LinkedList_ReplaceData(LinkedList_Node_Type* LinkedListBaseAddr, int OldData, int NewData);

/*
*   Description : Delete node has data bigger than Sample in Linked List
*/
void LinkedList_DeleteBigger(LinkedList_Node_Type** LinkedListBaseAddr, int Sample);

#endif /* LINKEDLIST_H */