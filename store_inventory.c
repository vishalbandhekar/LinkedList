
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store_inventory.h"


//function to print the linked list
void printLinkedList(struct Node* head) 
{	
	struct Node* current = head;

	while(current != NULL)
	{
		printf("Stock Name: %s\n", current->stockname);
        	printf("Model Number: %s\n", current->modelnumber);
        	printf("Count: %d\n", current->count);
        	printf("Venodr: %s\n\n", current->vendor);
        	current = current->next;
	}
}

//Function to add the new node at the front/head of the linkedlist
void appendToList(struct Node** head, struct Node* newNode) 
{
	if(*head == NULL) 
	{
        	*head = newNode;
    	} 
	else 
	{
        	struct Node* current = *head;
        	while (current->next != NULL) 
		{
            		current = current->next;
        	}
        	current->next = newNode;
    	}
}

//Function to add the new node data to the file
void addEntryToFile(const char* filename, struct Node* entry) 
{
	FILE* file = fopen(filename, "a");
	if(file == NULL)
	{
		printf("Failed to open the file.\n");
		return;
	}

	fprintf(file,"%s,%s,%d,%s\n", entry->stockname, entry->modelnumber, entry->count, entry->vendor);
	fclose(file);
}

//Function to insert the new node
void insertNode(struct Node* head)
{
	char stockname[20],modelnumber[20],vendor[20];
	int count;

	printf("please enter the node value\n");
	printf("Stock Name:");
	scanf("%s",stockname);

	printf("Model Number:");
	scanf("%s",modelnumber);

	printf("count:");
	scanf("%d",&count);

	printf("Vendor:");
	scanf("%s",vendor);
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) 
	{
		printf("Failed to allocate memory for new node.\n");
		return;
        }

	strcpy(newNode->stockname,stockname);
	strcpy(newNode->modelnumber,modelnumber);
	newNode->count = count;
	strcpy(newNode->vendor,vendor);
	newNode->next=NULL;

	//adding new node to the linked list	
	appendToList(&head,newNode);
	
	//adding new data to the file
	const char* filename = "stocks_available.txt";
	addEntryToFile(filename, newNode);
	
}

//function to search model number
void getStockByModelNumber(struct Node* head, char modelnumber[]) {
    struct Node* node = head;
    int found = 0;

    while (node != NULL) {
        if (strcmp(node->modelnumber, modelnumber) == 0) {
            printf("Stock Name: %s\n", node->stockname);
            printf("Model Number: %s\n", node->modelnumber);
            printf("Count: %d\n", node->count);
            printf("Vendor: %s\n\n", node->vendor);
            found = 1;
        }
        node = node->next;
    }

    if (!found) {
        printf("Model not found.\n");
    }
}

//function to fetch data from this stocks_available.txt file and store in single linked list structure. i.e Init function
struct Node* fetchData() 
{

	FILE* file = fopen("stocks_available.txt", "r");
	if(file == NULL) 
	{
		printf("Failed to open the file.\n");
		return 0;
	}

	struct Node* head = NULL;
	struct Node* current = NULL;
	char line[256];

	while(fgets(line, sizeof(line), file)) 
	{
		// Remove the newline character from the line
		line[strcspn(line, "\n")] = '\0';

        	// Tokenize the line
        	char* stockname = strtok(line, ",");
        	if(stockname == NULL) 
		{
			char value[10];
			printf("Stock Name is empty please enter Stock Name:");
			scanf("%s",value);
			stockname = value;
        	}
        
        	char* modelnumber = strtok(NULL, ",");
        	if(modelnumber == NULL) 
		{
			char value[10];
			printf("Stock Name is empty please enter Model Number:");
			scanf("%s",value);
			modelnumber = value;
        	}

        	char* countStr = strtok(NULL, ",");
        	if(countStr == NULL) 
		{
			char value[10];
			printf("Stock Name is empty please enter Count:");
			scanf("%s",value);
			countStr = value;
        	}
        	int count = atoi(countStr);

        	char* vendor = strtok(NULL, ",");
        	if(vendor == NULL) 
		{
			char value[10];
			printf("Stock Name is empty please enter Vendor:");
			scanf("%s",value);
			vendor = value;

			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        		if(newNode == NULL) 
			{
            			printf("Failed to allocate memory for new node.\n");
            			return 0;
        		}

        		// Copy the data fields into the new node
        		strncpy(newNode->stockname, stockname, sizeof(newNode->stockname) - 1);
        		strncpy(newNode->modelnumber, modelnumber, sizeof(newNode->modelnumber) - 1);
        		newNode->count = count;
        		strncpy(newNode->vendor, vendor, sizeof(newNode->vendor) - 1);

        		newNode->next = NULL;
			
			// Check if the linked list is empty
        		if(head == NULL) 
			{
				head = newNode;
            			current = newNode;
        		} 
			else 
			{
            			current->next = newNode;
            			current = current->next;
        		}
	
            	}
		


        	// Create a new node
        	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        	if(newNode == NULL) 
		{
            		printf("Failed to allocate memory for new node.\n");
            		return 0;
        	}

        	// Copy the data fields into the new node
        	strncpy(newNode->stockname, stockname, sizeof(newNode->stockname) - 1);
        	strncpy(newNode->modelnumber, modelnumber, sizeof(newNode->modelnumber) - 1);
        	newNode->count = count;
        	strncpy(newNode->vendor, vendor, sizeof(newNode->vendor) - 1);

        	newNode->next = NULL;

        	// Check if the linked list is empty
        	if(head == NULL) 
		{
			head = newNode;
            		current = newNode;
        	} 
		else 
		{
            		current->next = newNode;
            		current = current->next;
        	}
    	}
	fclose(file);

	return head;
}

