#include <bits/stdc++.h>

using namespace std;
struct LLNode
{
    char data[1000];
    struct LLNode* next;
};
/* Function to insertAtBeginning a node */
void insertAtBeginning(struct LLNode** head, char * dataToBeInserted)
{
    struct LLNode* curr = new LLNode;
    strcpy(curr->data, dataToBeInserted);
    curr->next = NULL;
    if(*head == NULL)
    *head=curr; //if this is first node make this as head of list
    
    else
    {
        curr->next=*head; //else make the curr (new) node's next point to head and make this new node a the head
        *head=curr;
    }
  
//O(1) constant time
}

//display linked list
void display(struct LLNode**node)
{

    struct LLNode *temp= *node;
    if(temp == NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        cout<<temp->data<<"->";
        else
        cout<<temp->data;
        
        temp=temp->next; //move to next node
}
//O(number of nodes)
cout<<endl;
}
//function to delete node at given pos
void deleteNode(struct LLNode **head_ref, int position)
{
    // If linked list is empty
    if (*head_ref == NULL)
    return;

    // Store head node
    struct LLNode* temp = *head_ref;

   // If head needs to be removed
   if (position == 0)
   {
       *head_ref = temp->next; // Change head
       free(temp);           // free old head
       return;
   }

   // Find previous node of the node to be deleted
   for (int i=0; temp!=NULL && i<position-1; i++)
       temp = temp->next;

   // If position is more than number of nodes
   if (temp == NULL || temp->next == NULL)
       return;

   // Node temp->next is the node to be deleted
   // Store pointer to the next of node to be deleted
   struct LLNode *next = temp->next->next;

   // Unlink the node from linked list
   free(temp->next); // Free memory

   temp->next = next; // Unlink the deleted node from list
}
//Main function
int main()
{
    //Input list
    struct LLNode* head = NULL;
    char ch [1000];
    
    while(true)
    {
        cout<<endl;
        cout<<"Please choose operation: "<<endl;
    cout<<"1. print the list"<<endl;
    cout<<"2. remove element from list"<<endl;
    cout<<"3. insert an element"<<endl;
    cout<<"4. end program"<<endl;
    
    int value;
    cin>>value;
    if(value == 1)
    {
        cout<<"Linked list: ";
        display(&head);
        } 
        else if(value ==2 )
        {
            cout<<"Enter the index of element: ";
            int index;
            cin>>index;
            deleteNode(&head, index - 1);
        } 
        else if(value == 3)
        {
            cout<<"Enter string to store in linked list: ";
            cin>>ch;
            insertAtBeginning(&head, ch);
        } 
        else 
        {
            break;
        }
    }
    
    return 0;
}