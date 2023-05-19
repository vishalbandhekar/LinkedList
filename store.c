
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store_inventory.h"

/*
    1. call the init function to fetch all the details
    This user interface should ask for the following options.
        1. Print all list.
        2. Add an entry.
        3. Get stock by model number.
        4. exit.
    
    and do the same by calling the corresponding function from store_inventory.h
*/
	
int main()
{
	struct Node* head = fetchData();
    	struct Node* current = NULL;
	struct Node* new = NULL;
    	char line[256], modelnumber[20];	
	
	int option=0;
	
	printf(" 1. Print all list.\n");
	printf(" 2. Add an entry.\n");
	printf(" 3. Get stock by model number.\n");
	printf(" 4. exit.\n");
	printf("Please enter the option\n");
	scanf("%d", &option);

	switch(option)
	{
		case 1:	if(head)
				 printLinkedList(head); 
			else
				printf("List is empty");
			break;

		case 2:	insertNode(head);
			break;

		case 3:	printf("Please enter the Model Number:\n");
			scanf("%s",modelnumber);
			if(head!=NULL)
				getStockByModelNumber(head, modelnumber);
			else
				printf("List is empty");
			break;

		case 4:	exit(0);
			break;
	}



    return 0;
}
