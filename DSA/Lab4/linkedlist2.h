//header file for merging 
#ifndef LIST_H
#define LIST_H 
#include<iostream>

class List
{
    private : 
         struct Node 
         {
            int data ;
            struct Node *next ;
         }*head;
          
         int gethead()
         {
            return head->data ;
         }
    public : 
        List()
        {
            head = NULL ;
        }     
        void Insert_ascending(int);
        void Merge(const List&, const List& );
        void Display();
};

// Function to insert elelments in ascending order 
void List::Insert_ascending(int val)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val ;
    newnode->next = NULL ;
    // If list is empty or if the node itself is the first node 
    if (head == NULL || head->data >= val) 
    {
        newnode->next = head;
        head = newnode;
        return;
    } 

    //To check for the right positon for insertion(traversing)
    struct Node *temp = head ;
    while(temp->next != NULL && temp->next->data < val)
    {
        temp = temp->next ;
    }
    //After traversal inserting at the right position
    newnode->next = temp->next ;
    temp->next = newnode ;
}

 // Function to merge two lists 
void List::Merge(const List& list1 , const List& list2)
{
  struct Node *temp1 = list1.head ;
  struct Node *temp2 = list2.head ; 
  while(temp1 != NULL )
  {
    Insert_ascending(temp1->data) ;
    temp1 = temp1->next ;
  } 

  while(temp2 != NULL )
  {
    Insert_ascending(temp2->data) ;
    temp2 = temp2->next ;
  } 
}
//Function to display the list 
void List::Display()
{
 if (head == NULL)
 {
   printf(" list is empty ") ;
 }
 else
 {
 struct Node *temp = head ;
 while(temp != NULL)
 {  
    printf(" %d ->", temp->data );
    temp = temp->next ;
 }
 if(head!=NULL)
 printf(" NULL \n") ;
 }
}

#endif 










































