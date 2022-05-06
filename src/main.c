#include "LinkedList.h"
#include "StandardType.h"
#include <stdio.h>
#include <stdint.h>

LinkedList_Node_Type* BaseNode = NULL_PTR;

int main()
{
    int Arr[100];
    int NumArr = 0;
    int Index = 0;

    /* Get array */
    printf("Enter NumArr: ");
    scanf("%d",&NumArr);
    for(Index = 0; Index < NumArr; Index++)
    {
        printf("Enter Arr[%d]: ",Index);
        scanf("%d",&Arr[Index]);
    }

    /* Print Array*/
    printf("Arr: ");
    for(Index = 0; Index < NumArr; Index++)
    {
        printf("%d ",Arr[Index]);
    }
    printf("\n");

    /* Initialize linked list */
    LinkedList_Init(&BaseNode, NumArr, Arr);
    
    /* Check result */
    LinkedList_PrintList(BaseNode);
    /* Free all dynamic memory allocation */
    LinkedList_FreeList(BaseNode);
    
    return 0;
}