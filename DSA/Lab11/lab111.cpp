// Program to Implement Hash ADT with Linear Probing
#include<iostream> 
using namespace std ;

const int TABLE_SPACE = 10 ;
const int EMPTY = -1 ;
const int DELETED = -2 ;

class Hashtable 
{
    private :

    int hasharr[TABLE_SPACE] ;

    public :

    Hashtable()
    {
        for (int i = 0 ; i < TABLE_SPACE ; i++)
        { 
            hasharr[i] = EMPTY ;
        }
    }

    int hashfunction(int key)
    {
        return (key % TABLE_SPACE) ;
    }
    void Insert(int key);
    void Delete(int key);
    void Search(int key);
    void Display() ; 

} ;

int main () 
{
    Hashtable ht ;
    int choice , key ;
    do 
    {
        printf("\n     Menu    \n");
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Search \n");
        printf("4.Display \n");
        printf("5.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice) ;
        switch(choice)
        {
            case 1 :
            printf("Enter key : ");
            scanf("%d",&key) ;
            ht.Insert(key); 
            break ;
            case 2 :
            printf("Enter key : ");
            scanf("%d",&key) ;
            ht.Delete(key) ;
            break ;
            case 3 :
            printf("Enter key : ");
            scanf("%d",&key) ;
            ht.Search(key) ;
            break ;
            case 4 :
            ht.Display();
            break ;
            case 5 : 
            printf("Exiting Program \n ");
            break ;

        }
    }    
    while(choice != 5) ;

    return 0 ;
}
// Function Definitions 

//1. Function to Insert 
void Hashtable :: Insert(int key)
{  
    int index = hashfunction(key) ;
    int originalindex = index ;
    int i = 0 ;
    while(hasharr[index] != EMPTY && hasharr[index] != DELETED) 
    {
        if(i == TABLE_SPACE)
        {
            printf("Hashtable is Full");
        }
        index  = ((originalindex + (++i)) % TABLE_SPACE );
    }
    hasharr[index] = key ;
    printf("key is inserted at %d ",index) ;
    
}

//2.Function to Delete 
void Hashtable :: Delete(int key)
{

    int index = hashfunction(key);
    int originalindex = index ;
    int i=0 ;
    while(hasharr[index] != EMPTY)
    {
        if (hasharr[index] == key) 
        {
            hasharr[index] = DELETED;
            cout << "Deleted " << key << " from index " << index << endl;
            return;
        }
        index = ((originalindex + (++i)) % TABLE_SPACE);
    }
        printf("%d is not found",index) ; 
}

//3. Function to Search 
void Hashtable :: Search(int key)
{ 
    int index = hashfunction(key) ;
    int originalindex = index ;
    int i = 0 ;
    while(hasharr[index] != EMPTY)
    {
        if(hasharr[index] == key)
        {
            printf("%d key is found at index ",key,index);
        }
        index = ((originalindex + (++i)) % TABLE_SPACE) ;   
    }
    printf("%d is not found",key);
}

//4. Function to display  
void Hashtable :: Display()
{
    for(int i = 0 ; i < TABLE_SPACE ; i++)
    { 
            if (hasharr[i] == EMPTY)
                cout << i << ": EMPTY\n";
            else if (hasharr[i] == DELETED)
                cout << i << ": DELETED\n";
            else
                cout << i << ": " << hasharr[i] << "\n";
    }

}