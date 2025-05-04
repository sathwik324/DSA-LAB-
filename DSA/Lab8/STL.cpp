// Program to count the maximum number of blocks 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;


void solve()
{
   int n ;
   cout << "Towers"  ;
   cin >> n  ;
   vector < int > a(n) ;
   printf("Blocks") ; 
   for ( int i = 0 ; i < n ; i++ )
   {
    cin >> a[i] ;
   }
   int h = a[0] ;
   sort(a.begin()+ 1 , a.end()) ;
   for ( int i =1 ; i < n ; i++) 
   {
    if(a[i]>h)
    {
        int  e = a[i]- h ;
        h+= (e+1)/2 ;
    }
   }
   cout <<  h << '\n' ;
 }


int main ()
{
    int t ;
    cout << "Enter number of testcases" << "\n" ;
    cin >> t ;
    while(t--) 
    { 
        solve() ;
    }
    return 0 ;
}

