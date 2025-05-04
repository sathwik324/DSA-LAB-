#include<cstdio>
#include<iostream>
#include "linkedlist2.h"

int main ()
{
   List l1 , l2 , l3 ;
   int choice , val ;

   do 
   {
    printf("\n  menu  \n") ;
    printf("1.Insert list 1 \n") ;
    printf("2.Insert list 2 \n") ;
    printf("3.Merge list 1,list2 in list 3 \n") ;
    printf("4.Display \n") ;
    printf("5.Exit \n") ;
    printf("\nEnter your choice : ") ;
    scanf("%d",&choice) ;
    switch(choice)
    {
      case 1 :
      //Insert into list 1 
      printf("Enter the values to be inserted into list 1 : ") ;
      scanf("%d",&val) ;
      l1.Insert_ascending(val);
      break ;
      case 2 :
      //Inseet elements into list 2 
      printf("Enter the values to be inserted into list 2 : ") ;
      scanf("%d",&val) ;
      l2.Insert_ascending(val) ;
      break ;
      case 3 :
      //Creating list3 by merging list1 and list2 
      l3.Merge(l1,l2);
      printf("\nlist3 is ready \n");
      break ;
      case 4 :
      //Display all the three lists after merging  
      printf("list 1 : ") ; 
      l1.Display();
      printf("list 2 : ") ;
      l2.Display();
      printf("list 3 : ") ;
      l3.Display();
      break ;
      case 5 :
      //Exiting the program 
      printf("Exiting the program \n") ;
      break ;
      default :
      printf("Invalid") ;
    }
   }
   while(choice < 5);
}


