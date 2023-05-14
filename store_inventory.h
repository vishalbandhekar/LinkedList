//structure of a Node
struct Node {
    char stockname[20];
    char modelnumber[20];
    int count;
    char vendor[20];
    struct Node* next;
};

//function to print the linked list
void printLinkedList(struct Node* head);

//Function to add the new node at the front/head of the linkedlist
void appendToList(struct Node** head, struct Node* newNode);

//Function to add the new node data to the file
void addEntryToFile(const char* filename, struct Node* entry);

//Function to insert the new node
void insertNode(struct Node* head);

//search node using model number
void getStockByModelNumber(struct Node* head, char modelnumber[]);

//function to fetch data from this stocks_available.txt file and store in single linked list structure. i.e Init function
struct Node* fetchData();

//print the data
void printData(); 


