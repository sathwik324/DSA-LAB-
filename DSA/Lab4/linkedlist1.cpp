//program to use linked list 
#include<cstdio>
#include<cstdlib>
using namespace std ;

class List 
{
  private :
    struct Node 
    {
        int data ;
        struct Node *next ;

    }*head ;
  public :
    List ()
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
    void Reverse() ;
    void ReverseLink() ;
};

int main () 
{
  List list1 ;
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
       list1.Reverse() ;
       break ; 
       case 10 :
       list1.ReverseLink();
       list1.Display();
       break ;
       case 11 : 
       printf("Exiting the program") ;

       break ;
    }
  }
  while(choice!=11);
  return 0 ;
}

//Function definitons

// 1. Inserting element at the beginning function
void List :: Insertbeginnig(int val)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)) ;
    new_node->data = val ; 
    new_node->next = head ;
    head = new_node ;
    
} 

//2. Inserting element at the end function
void List :: Insertend(int val)
{   
    if(head==NULL)
    {
        printf("list is empty") ;
    }   
    else
    {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)) ;
    struct Node *temp = head ;
    while(temp->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next = new_node ;
    new_node->data = val ; 
    new_node->next = NULL ;
    }
}

// 3. Insertion at the position function 

void List::Insertposition(int val , int pos)
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


}

// 4. Deleting element at the  beginning function

void List:: Deletebeginning() 
{
  if(head == NULL)
  {
    printf("list is empty") ;
  }
  else
  {
  int ele ;
  ele = head-> data ;
  head = head-> next ;
  printf("deleted element : %d \n",ele) ;
  
  }
}

//5. Deleting element at the end function 

void List :: Deleteend() 
{
   if(head == NULL)
  {
    printf("list is empty") ;
  }
  else
  { 
    
    struct Node *temp = head ;
    if(temp->next == NULL)
    {
    printf("only one element , considered as first \n") ;
    }
    if(temp->next != NULL)
    {
    while(temp->next->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next = NULL ;
  }
  }
}

//6. Deleting element at position 

void List::Deleteposition(int pos) 
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
void List::Search(int val)
{
    struct Node *temp = head ;
    while (temp != NULL)
    {
        if (val == temp->data)
        {
            printf(" %d found \n", val ) ; 
        }
        temp = temp->next;
    }
    
}
//8. Display funtion 
void List :: Display() 
{   
    if(head==NULL) 
    {
      printf("list is empty") ;
    }
    struct Node *temp = head ;
   
    while(temp != NULL)
    {  
        printf(" %d ->", temp->data );
        temp = temp->next ;
    }
    if(head!=NULL)
    printf(" NULL \n") ;

}

// 9. Display reverse function 

void List::Reverse() 
{
  if (head == NULL)
  {
      printf("\nList is empty\n");
  }
  else {
      struct Node *temp = head ;
      int size=0 ;
      while (temp != NULL) 
      {
          temp = temp->next;
          size++;
      }

      int arr[size-1];
      temp = head;

      for (int i=(size-1);i>=0;i--)
      {
          arr[i]=temp->data;
          temp = temp->next;
      }
      printf("NULL");
      for (int i=0;i<size;i++)
      {
          printf(" -> %d", arr[i]);
      }
  }
}
//10 . Reverse linking function 
void List::ReverseLink() 
{
   if (head==NULL)
   {
    printf("list is empty") ;
   }
   else
   {
   struct Node *temp = head ;
   int size = 0 ; 
   while( temp != NULL)
   {
      temp = temp->next ;
      size++ ;
   }

   int arr[size-1] ;
   temp = head ;
   for(int i = (size-1) ; i>=0 ; i-- ) 
   {
       arr[i] = temp->data ; 
       temp = temp->next ;
   }
   temp = head ;
   for(int i = 0 ; i<size ; i++) 
   {
    temp -> data = arr[i] ;
    temp = temp->next ; 
   }
  }
}

 