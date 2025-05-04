// Program to Implement Hash Table using Separate chaining 
#include<iostream>
using namespace std ;

const int TABLE_SPACE = 10 ;
const int EMPTY = -1 ;
const int DELETED = -1 ;


class Hashtable 
{
    private :
    
    struct Node
    {
        int data ;
        struct Node *next ;

    }*head , *current  ;
    
    Node*Hasharr[TABLE_SPACE] ;

    public :


    Hashtable()
    {
        head = NULL ;
        current = NULL ;
        for (int i = 0 ; i < TABLE_SPACE ; i++)
        { 
            Hasharr[i] = NULL ;
        }
    }
    
    int Hashfunction(int key)
    {
        return (key % TABLE_SPACE);
    }
    void Insert(int key);
    void Delete(int key);
    void Search(int key);
};

int main()
{
    Hashtable ht ;
    int choice , key ;
    do
    {
        printf("\n    Menu    \n");
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Search \n");
        printf("4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            printf("Enter Key : ");
            scanf("%d",&key);
            ht.Insert(key);
            break;
            case 2 :
            printf("Enter Key : ");
            scanf("%d",&key);
            ht.Delete(key);
            break;
            case 3 :
            printf("Enter Key : ");
            scanf("%d",&key);
            ht.Search(key);
            break;
            case 4 :
            printf("Exiting... \n");
            break ;
        }
    } while (choice!=4);
    
}

// Functions 

//1.Function to Insert at Beginning 
void Hashtable::Insert(int key)
{
    int index = Hashfunction(key) ;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)) ; 
    new_node->data = key ;
    new_node->next =  Hasharr[index];
    Hasharr[index] = new_node ;

    cout << "Inserted " << key << " at index " << index << endl;
    
}

//2. Function to Delete By Key
void Hashtable::Delete(int key)
{
    int index = Hashfunction(key);
    Node* temp = Hasharr[index];
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == key) {
            if (prev == nullptr) {
                Hasharr[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Key " << key << " deleted from index " << index << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Key " << key << " not found.\n";
}


//3. Search by key 
void Hashtable::Search(int key)
{
    int index = Hashfunction(key);
    Node* temp = Hasharr[index];
    while (temp != nullptr) 
    {
        if (temp->data == key) 
        {
            cout << "Key " << key << " found at index " << index << endl;
            return;
        }
        temp = temp->next;
    }
    printf("key not found") ;
}

