#include "LinkedList.h"
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

/*
*   Description : Initialize linked list
*/
void LinkedList_Init(LinkedList_Node_Type** LinkedListBaseAddr,int NumArr, int* DataArr)
{
    CHECK_PARAMETER(NumArr != 0U);
    CHECK_PARAMETER(DataArr != NULL_PTR);

    int Index = 0U;

    for(Index = 0; Index < NumArr; Index++)
    {
        if(Index == 0U)
        {
            (*LinkedListBaseAddr) = LinkedList_CreateNode(DataArr[Index]);
        }
        else
        {
            LinkedList_InsertNode(LinkedListBaseAddr, Index, LinkedList_CreateNode(DataArr[Index]));
        }
    }
}

/*
*   Description : Create a node
*/
LinkedList_Node_Type* LinkedList_CreateNode(int NewNodeData)
{
    LinkedList_Node_Type* NodeAddr = (LinkedList_Node_Type*)calloc(1U,sizeof(LinkedList_Node_Type));
    NodeAddr->Data = NewNodeData;
    NodeAddr->NextNode = NULL_PTR;
    return NodeAddr;
}

/*
*   Description : Insert a node into Linked List
*/
void LinkedList_InsertNode(LinkedList_Node_Type** LinkedListBaseAddr, int PosNode, LinkedList_Node_Type* Node)
{
    CHECK_PARAMETER(Node != NULL_PTR);

    LinkedList_Node_Type* TempNodeAddr = (*LinkedListBaseAddr);
    int Index = 1;

    if(PosNode == 0)
    {
        Node->NextNode = TempNodeAddr;
        (*LinkedListBaseAddr) = Node;
    }
    else
    {
        while((Index != PosNode) && (TempNodeAddr->NextNode != NULL_PTR))
        {
            Index++;
            TempNodeAddr = TempNodeAddr->NextNode;
        }
        if(Index == PosNode)
        {
            Node->NextNode = TempNodeAddr->NextNode;
            TempNodeAddr->NextNode = Node;
        }
        else
        {
            CHECK_PARAMETER(PosNode == Index);
        }
    }
}

/*
*   Description : Delete a node in Linked List
*/
void LinkedList_DeleteNode(LinkedList_Node_Type** LinkedListBaseAddr, int PosNode)
{
    CHECK_PARAMETER((*LinkedListBaseAddr) != NULL_PTR);
    CHECK_PARAMETER(PosNode != 0U);

    LinkedList_Node_Type* TempNodeAddr = (*LinkedListBaseAddr);
    LinkedList_Node_Type* DeleteNodeAddr = NULL_PTR;
    int Index = 2U;

    if(PosNode == 1U)
    {
        TempNodeAddr = (*LinkedListBaseAddr)->NextNode;
        free((*LinkedListBaseAddr));

#if(TEST_ENABLE == STD_ON)
        /* Check free node sucess */
        printf("Test - Delete node %d : 0x%X,0x%X,0x%X\t", PosNode, (*LinkedListBaseAddr), (*LinkedListBaseAddr)->Data, (*LinkedListBaseAddr)->NextNode);
        printf("\n");
#endif

        (*LinkedListBaseAddr) = TempNodeAddr;
    }
    else
    {
        while((Index != PosNode) && (TempNodeAddr->NextNode != NULL_PTR))
        {
            Index++;
            TempNodeAddr = TempNodeAddr->NextNode;
        }
        if(Index == PosNode)
        {
            DeleteNodeAddr = TempNodeAddr->NextNode;
            TempNodeAddr->NextNode = DeleteNodeAddr->NextNode;
            free(DeleteNodeAddr);

#if(TEST_ENABLE == STD_ON)
            /* Check free node sucess */
            printf("Test - Delete node %d : 0x%X,0x%X,0x%X\t", PosNode, DeleteNodeAddr,DeleteNodeAddr->Data,DeleteNodeAddr->NextNode);
            printf("\n");
#endif
        }
        else
        {
            CHECK_PARAMETER(PosNode == Index);
        }
    }
}

/*
*   Description : Get data of node in Linked List
*/
int LinkedList_GetDataNode(LinkedList_Node_Type* LinkedListBaseAddr, int PosNode)
{
    CHECK_PARAMETER(PosNode > 0U);
    CHECK_PARAMETER(LinkedListBaseAddr != NULL_PTR);

    LinkedList_Node_Type* TempNodeAddr = LinkedListBaseAddr;
    int RetVal = 0U;
    int Index = 1U;

    while((Index != PosNode) && (TempNodeAddr->NextNode != NULL_PTR))
    {
        TempNodeAddr = TempNodeAddr->NextNode;
        Index++;
    }
    if(Index == PosNode)
    {
        RetVal = TempNodeAddr->Data;
    }
    else
    {
        CHECK_PARAMETER(PosNode == Index);
    }
    return RetVal;
}

/*
*   Description : Print Linked List data
*/
void LinkedList_PrintList(LinkedList_Node_Type* LinkedListBaseAddr)
{
    CHECK_PARAMETER(LinkedListBaseAddr != NULL_PTR);

    LinkedList_Node_Type* TempNodeAddr = LinkedListBaseAddr;

#if(TEST_ENABLE == STD_ON)
        printf("Test - Print linked list : ");
#else
        printf("Print linked list: ");
#endif

    while(TempNodeAddr != NULL_PTR)
    {
#if(TEST_ENABLE == STD_ON)
        printf("0x%X,0x%X,0x%X\t",TempNodeAddr,TempNodeAddr->Data,TempNodeAddr->NextNode);
#else
        printf("0x%X\t",TempNodeAddr->Data);
#endif
        TempNodeAddr = TempNodeAddr->NextNode;
    }
    printf("\n");
}

/*
*   Description : Free linked list
*/
void LinkedList_FreeList(LinkedList_Node_Type* LinkedListBaseAddr)
{
    CHECK_PARAMETER(LinkedListBaseAddr != NULL_PTR);
    LinkedList_Node_Type* TempNodeAddr = NULL_PTR;

#if(TEST_ENABLE == STD_ON)
    printf("Test - Free linked list : ");
#endif

    while(LinkedListBaseAddr != NULL_PTR)
    {
        TempNodeAddr = LinkedListBaseAddr->NextNode;
        free(LinkedListBaseAddr);
#if(TEST_ENABLE == STD_ON)
        printf("0x%X,0x%X,0x%X\t",LinkedListBaseAddr,LinkedListBaseAddr->Data,LinkedListBaseAddr->NextNode);
#endif
        LinkedListBaseAddr = TempNodeAddr;
    }
}

/*
*   Description : Replace data of all node in Linked List
*/
void LinkedList_ReplaceData(LinkedList_Node_Type* LinkedListBaseAddr, int OldData, int NewData)
{
    LinkedList_Node_Type* TempNodeAddr = LinkedListBaseAddr;
    int Index = 0U;

    CHECK_PARAMETER(LinkedListBaseAddr != NULL_PTR);

    while(TempNodeAddr != NULL_PTR)
    {
        if(TempNodeAddr->Data == OldData)
        {
            TempNodeAddr->Data = NewData;
            Index++;
        }
        TempNodeAddr = TempNodeAddr->NextNode;
    }
}

/*
*   Description : Delete node has data bigger than Sample in Linked List
*/
void LinkedList_DeleteBigger(LinkedList_Node_Type** LinkedListBaseAddr, int Sample)
{
    CHECK_PARAMETER((*LinkedListBaseAddr) != NULL_PTR);

    LinkedList_Node_Type* TempNodeAddr = (*LinkedListBaseAddr);
    LinkedList_Node_Type* DeleteNodeAddr = NULL_PTR;

    /* Check some first node bigger than Sample to update BaseNode Address*/
    while(TempNodeAddr->Data > Sample)
    {
        DeleteNodeAddr = TempNodeAddr;
        TempNodeAddr = TempNodeAddr->NextNode;
        free(DeleteNodeAddr);
        (*LinkedListBaseAddr) = TempNodeAddr;
    }
    while(TempNodeAddr != NULL_PTR)
    {
        DeleteNodeAddr = TempNodeAddr->NextNode;
        while((DeleteNodeAddr != NULL_PTR) && (DeleteNodeAddr->Data > Sample))
        {
            TempNodeAddr->NextNode = DeleteNodeAddr->NextNode;
            free(DeleteNodeAddr);
            DeleteNodeAddr = TempNodeAddr->NextNode;
        }
        TempNodeAddr = TempNodeAddr->NextNode;
    }
}