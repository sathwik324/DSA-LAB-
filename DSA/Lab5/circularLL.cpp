// Program to use circular linked list 

#include<cstdio>
#include<cstdlib>
using namespace std ;

class CList 
{
  private :
    struct Node 
    {   int data ;
        struct Node *next ;
    }*head ;
  public :
    CList ()
    {
      head = NULL ;
    }
    void Insertbeginnig(int val) ;
    void Insertend(int val) ;
    void Insertposition(int val ,int pos) ;
    void Deletebeginning() ;
    void Deleteend() ;
    void Deleteposition(int pos) ;
    void Search(int val) ;
    void Display() ;
};

int main () 
{
  CList list1 ;
  int val , pos , choice ;
  do
  {
    printf("\n    Menu    \n") ;
    printf(" 1.Insert beginning  \n") ;
    printf(" 2.Insert end \n") ;
    printf(" 3.Insert position  \n") ;
    printf(" 4.Delete beginning \n") ;
    printf(" 5.Delete end \n") ;
    printf(" 6.Delete position \n" ) ;
    printf(" 7.Search List \n") ;
    printf(" 8.Display \n") ;
    printf(" 9.Exit \n") ;
    printf(" Enter choice : ") ;
    scanf("%d",&choice) ;
    switch(choice)
    {
       case 1 :
       printf("Enter the value : ") ;
       scanf("%d", &val ) ; 
       list1.Insertbeginnig(val) ;
       list1.Display() ;
       break ;
       case 2 : 
       printf("Enter the value : ") ;
       scanf("%d",&val) ;
       list1.Insertend(val) ;
       list1.Display() ;
       break ;
       case 3 :
       printf("Enter the value : ") ;
       scanf("%d",&val) ;
       printf("Enter the position : ");
       scanf("%d",&pos);
       list1.Insertposition(val,pos);
       list1.Display();
       break;
       case 4 :
       list1.Deletebeginning() ;
       list1.Display() ;
       break ; 
       case 5 : 
       list1.Deleteend() ;
       list1.Display() ;
       break ;
       case 6 :
       printf("Enter the position you wanna delete : ");
       scanf("%d",&pos) ;
       list1.Deleteposition(pos) ;
       list1.Display();
       break ;
       case 7 :
       printf("Enter the number you want to search : ") ;
       scanf("%d",&val);
       list1.Search(val);
       case 8 : 
       list1.Display() ;
       break ;
       case 9 : 
       printf("Exiting the program") ;
       break ;
    }
  }
  while(choice!=9);
  return 0 ;
}

//Function definitons

// 1. Inserting element at the beginning function
void CList :: Insertbeginnig(int val)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)) ;
    new_node->data = val ; 
    if(head == NULL)
    {  
        head = new_node ;
        new_node->next = head ;
    }
    else
    {   struct Node *temp = head ;
        while( temp->next != head )
        { 
            temp = temp->next ;
        }
            new_node->next = head ;
            temp->next = new_node ;
            head = new_node ;
    }  
} 

//2. Inserting element at the end function
void CList :: Insertend(int val)
{   
    if(head==NULL)
    {
        printf("list is empty") ;
    }   
    else
    {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)) ;
    struct Node *temp = head ;
    while(temp->next != head)
    {
        temp = temp->next ;
    }
    temp->next = new_node ;
    new_node->data = val ; 
    new_node->next = head ;
    }
}

// 3. Insertion at the position function 

void CList::Insertposition(int val , int pos)
{
  if(head==NULL)
  {
    printf("list is empty,cannot insert") ; 
  }

  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node *temp = head ;
  for(int i = 1 ; i < pos-1 ; i++)
  {
    temp = temp->next ;
  }
  new_node->next = temp->next ;
  temp->next = new_node ;
  new_node->data = val ;
  struct Node *temp1 = head ;
  while( temp1->next != head )
  { 
      temp1 = temp1->next ;
  }
  temp1->next = head ;
  
}

// 4. Deleting element at the beginning function

void CList:: Deletebeginning() 
{
  if(head == NULL)
  {
    printf("list is empty") ;
  }
  else
  {
  int ele ;
  ele = head-> data ;
  struct Node *temp = head ;
  while(temp->next != head)
  {
    temp = temp->next ;
  }
  temp->next = head->next ;
  head = head-> next ;
  
  printf("deleted element : %d \n",ele) ;
  
  }
}

//5. Deleting element at the end function 

void CList :: Deleteend() 
{
   if(head == NULL)
  {
    printf("list is empty") ;
  }
  else
  { 
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)) ;
    struct Node *temp = head ;
    if(temp->next == NULL)
    {
    printf("only one element , considered as first \n") ;
    }
    if(temp->next != NULL)
    {
    while(temp->next->next != head)
    {
        temp = temp->next ;
    }
    temp->next = head ;
    }
  }
}

//6. Deleting element at position 

void CList::Deleteposition(int pos) 
{
  if(head==NULL)
  {
    printf("list is empty cannot delete");
  }
  struct Node *temp = head ;
  for(int i = 1 ; i < pos-1 ; i++)
  {
    temp = temp->next ;
  }
  temp->next = temp->next->next ;

}

// 7. Searching function 
void CList::Search(int val)
{   
    if (head == NULL)
    {
        printf("list is empty can't search \n");
    }
    struct Node *temp = head ;
    do
    {
        if (val == temp->data)
        {
            printf(" %d found \n", val ) ; 
        }
        temp = temp->next;
    } while (temp != head);
    
    
    
}
//8. Display funtion 
void CList :: Display() 
{   
    if(head==NULL) 
    {
      printf("list is empty") ;
    }
    else
    {   
        struct Node *temp = head  ;
        do 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } 
        while (temp != head);
    }
    if(head!=NULL)
    printf("%d \n",head->data) ;
}
