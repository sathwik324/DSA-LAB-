#include<cstdio>
int bubble_sort (int arr[] , int n)
{
  for(int i = 0 ; i<n-1 ; i++) 
  {
     for( int j = 0 ; j<n-i-1 ; j++)
     {
        if( arr[j] > arr[j+1] ) 
        {
          int temp = arr[j] ;
          arr[j]=arr[j+1];
          arr[j+1]= temp ;
        }
        
     }
  }
}
int selection_sort ( int arr[],int n )
{
for(int i = 0 ; i < n-1 ; i++) 
{
  int min = i ; 
for(int j = i + 1 ; j < n ; j++) 
{
  if(arr[j] < arr[min]) 
  {
    min = j ;
  }
  
}
if(min != i) 
  {
          int temp = arr[i] ;
          arr[i] = arr[min];
          arr[min] = temp ;
  }
}
}

int insertion_sort (int arr[] , int n )
{
 for(int i = 0 ; i<n ; i++)
{
   int k = arr[i] ;
   int j = i- 1 ;
   
   while(j>=0 && arr[j]>k) 
   {
    arr[j+1] = arr[j] ;
    j-- ;
   }
   arr[j+1] = k ;

}


}