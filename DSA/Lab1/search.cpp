#include<cstdio>
#include<cstdlib>
#include"sortfunction.h"

int linearsearch(int arr[],int n,int t)
{
  for( int i = 0 ; i < n ; i++)
  {
     if(arr[i]==t) 
     {
        printf("\n Target found at %d position",i) ;
     }
  }
}

int binarysearch(int arr[],int n,int t)
{   
        int l=0 ;
        int r = n-1 ;
        while(l<=r) 
        {
            int mid = (l+r)/2 ;

        if(arr[mid]==t) 
        {
        printf("target found at %d",mid) ;
        return mid ; 
        }
        if(arr[mid] < t ) 
        {
        l = mid + 1 ;
        }
        else
        {
        r = mid - 1;
        }

        }
        printf("target not found ");
        return -1 ;
}   


void printArray(int arr[], int size) 
 {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]) ;

    }   
 }
int main() 
{
 int arr[100] ;
 int n , t ,choice ;

 do 
 {
   printf("\n    menu    \n") ;
   printf("1.linear search\n" ) ;
   printf("2.binary search\n") ;
   printf("3.exit\n") ;
   printf("enter your choice : ");
   scanf("%d",&choice) ;

   switch(choice)
   {
    case 1 :
    printf("enter the no of elements in the array : ") ;
    scanf("%d",&n) ;
    printf("enter the elements : ");
    for(int i = 0 ; i<n ; i++) 
    {
       scanf("%d",&arr[i]); 
    }
    printf("enter your target : ");
    scanf("%d",&t);
    linearsearch(arr,n,t) ;

    break ;
    

    case 2 : 
    printf("enter the no of elements in the array : ") ;
    scanf("%d",&n) ;
    printf("enter the elements : ");
    for(int i = 0 ; i<n ; i++) 
    {
       scanf("%d",&arr[i]); 
    }
    selection_sort(arr,n);
    
    printf("enter your target : ");
    scanf("%d",&t);
    binarysearch(arr,n,t);
   
    break ; 

    case 3 : 
    
    printf("exiting the programme ");
    break; 
    
   }
 } 
 while(choice!=3) ;
 return 0 ;

}