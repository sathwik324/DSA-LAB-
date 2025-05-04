//Program to implement Doubly linked list 
#include<cstdio>
#include<cstdlib>
using namespace std ;

class Dlist 
{

private :

     struct Node 
     {
         int data ;
         struct Node *next ;
         struct Node *prev ; 
     }*head;
public :
 
     Dlist()
     {
        head = NULL ;
     }
    
    void Insertbeginning(int val) ;
    void Insertend(int val) ;
    void Insertposition(int val ,int pos) ;
    void Deletebeginning() ;
    void Deleteend() ;
    void Deleteposition(int pos) ;
    void Search(int val) ;
    void Display() ;
};

int main()
{
    Dlist list1 ;
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
      printf(" 9.Reverse display \n") ;
      printf(" 10.Reverse link \n") ;
      printf(" 11.Exit \n") ;
      printf(" enter choice : ") ;
      scanf("%d",&choice) ;
      switch(choice)
      {
        case 1 :
        printf("Enter the value : ") ;
        scanf("%d", &val ) ; 
        list1.Insertbeginning(val) ;
        list1.Display() ;
        break ;
        case 2 : 
        printf("Enter the value : ") ;
        scanf("%d",&val) ;
        list1.Insertend(val) ;
        list1.Display() ;
        break ;
         case 3 :
        printf("Enter the position : ");
        scanf("%d",&pos) ;
        printf("Enter the value : ");
        scanf("%d",&val);
        list1.Insertposition(val,pos);
        list1.Display();
        break ;
        case 4 :
        list1.Deletebeginning() ;
        list1.Display() ;
        break ; 
        case 5 : 
        list1.Deleteend() ;
        list1.Display() ;
        break ;
        case 6 :
        printf("Enter the position you want to delete : ") ;
        scanf("%d",&pos) ;
        list1.Deleteposition(pos) ;
        list1.Display() ;
        break ;
        case 7 :
        printf("Enter the value you want to search :  ") ;
        scanf("%d",&val) ;
        list1.Search(val) ;
        list1.Display() ;
        break ;
        case 8 : 
        list1.Display() ;
        break ;
        case 9 :
        printf("Exiting the program");
        break ;
      }
    }
    while(choice!=9);
    return 0 ;
}

// Function declarations 

// 1. Insertion in the beginning function 

void Dlist :: Insertbeginning (int val)
{
    struct Node *newnode = (struct Node*) malloc (sizeof(struct Node)) ;
    newnode->data = val ; 
    newnode->next = head;
    newnode->prev = NULL;
    if(head == NULL )
    {
    head = newnode ;  
    }
    else 
    {  
       head->prev = newnode ;
       head = newnode ;
    } 
}     

// Insertion in the end function 

void Dlist ::Insertend(int val)
{
    if(head==NULL) 
    {
       printf("cannot insert list is empty ") ;
    } 

    struct Node *newnode = (struct Node*) malloc (sizeof(struct Node)) ;
    newnode->data = val ; 
    newnode->prev = NULL;
    struct Node *temp = head ;
    
    
    while(temp->next !=NULL)
    {
        temp = temp->next ;
    }
        temp->next = newnode ;
        newnode->next = NULL ; 
        newnode->prev = temp ;
        
}

// Insertion at the position function 

void Dlist :: Insertposition(int val , int pos) 
{   
    if (head==NULL)
    {
        printf("list is empty \n") ;
    }
    else
    {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node)) ;
    struct Node *temp = head ;
    newnode->data = val ; 
    newnode->next = NULL ;
    newnode->prev = NULL ;
    int count=0 ;
    while(temp->next != NULL) 
    {
        temp = temp->next ;
        count++ ;
    }
    temp = head ;
    if( pos>count+1 || pos < 0 )
    {
       printf("invalid position \n") ;
       printf("count  = %d \n", count) ;
    }
    else
    {
    for(int i = 1 ; i < pos-1  ; i++ )
    {   
        temp = temp->next ;
    }
    newnode->next = temp->next ;
    temp->next->prev = newnode ;
    newnode->prev = temp ;
    temp->next = newnode ;
    }
    }
}

// Deletion at the beginning function 

void Dlist ::Deletebeginning()
{
    if (head==NULL) 
    {
        printf("list is empty \n") ;
    }
    else if(head->next == NULL)
    {
        head = NULL ;
    }
    else
    {
      struct Node *temp = head ;
      temp = temp->next ;
      head = temp ;
      head->prev = NULL ;
    }
}

// Deletion at the end function 

void Dlist :: Deleteend()
{  
   if ( head == NULL || head->next == NULL )
   {
       printf("cannot delete") ;
   }
   else
   {
   struct Node *temp = head ;
   while(temp->next->next != NULL)
   {
       temp = temp->next ;
   }
   temp->next = NULL ;
   }
}

// Deletion at the position function 

void Dlist :: Deleteposition(int pos)
{
  if (head==NULL)
  {
    printf("list is empty \n") ;

  }
  else if ( head->next->next == NULL)
  {
    printf("use delete at beggining or end \n") ;
  }
  else
  {
    struct Node *temp = head ;
    for(int i = 1 ; i < pos-1 ; i++)
    {
        temp = temp->next ;
    }
    temp->next = temp->next->next ;
    temp->next->prev = temp ; 
  }
}

// Function to search 

void Dlist :: Search(int val)
{
    struct Node * temp;
    temp=head;
    int i =  0 ;
    while (temp !=NULL)
    {
        if (temp->data==val)
        {
            printf("\nThe element %d is found\n\n",val);
            int i = 1 ;
        }
        temp=temp->next;
    }  
    if( i == 0)
    {
        printf("Element is nowhere to be found in the list \n ") ;
    }
}

// Function to display 

void Dlist :: Display()
{   
    if(head == NULL)
    {
        printf("list is empty \n") ;
    }
    struct Node *temp = head ;
    if(head!=NULL)
    printf(" NULL ") ;
    while(temp!= NULL)
    {
        printf("<-%d->",temp->data) ;
        temp = temp->next ;
    }
    if(head!=NULL)
    printf(" NULL \n") ;
}
