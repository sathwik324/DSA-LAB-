#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

class Graph {
    private :
       int Adjmatrice[10][10] ;
       int NumVertices ;
    public : 
       Graph(int vertices)
       {
          NumVertices = vertices ;
       
       for(int i = 0 ; i < NumVertices; i++)
       {
            for(int j = 0 ; j < NumVertices ; j++)
            {
                Adjmatrice[i][j] = 0 ;
            }
       }
       }
       void InsertEdge(int start , int end);
       void DeleteEdge(int start , int end);
       void SearchEdge(int start , int end);
       void Display();
} ;


int main()
{
    int vertices , choice ,start ,end ; 
    cout << "Enter number of vertices : " ;
    cin >> vertices ;
    Graph graph(vertices) ;
    if (vertices > 10 || vertices <= 0) 
    {
        cout << "Invalid number of vertices.\n";
        return 0;
    }
    do
    {
        cout << "\n   Menu   \n" ;
        cout << "1.Insertion \n" ;
        cout << "2.Deletion \n" ;
        cout << "3.Search \n" ;
        cout << "4.Display \n" ;
        cout << "5.Exit \n" ;
        cout << "Enter your choice : " ;
        cin  >> choice ;
        switch(choice)
        {
            case 1:
            cout << "Enter start and end vertices to insert edge: \n";
            cin >> start ;
            cin >> end;
            graph.InsertEdge(start, end);
            break;
        case 2:
            cout << "Enter start and end vertices to delete edge: \n";
            cin >> start ;
            cin >> end;
            graph.DeleteEdge(start, end);
            break;
        case 3:
            cout << "Enter start and end vertices to search edge: \n";
            cin >> start ;
            cin >> end;
            graph.SearchEdge(start, end);
            break;
        case 4:
            graph.Display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please select between 1 to 5.\n";
        }
    } while (choice != 5);

}

// Functions 

// 1. Function To Insert 
void Graph :: InsertEdge(int start , int end)
{
    if(start >= NumVertices || end >= NumVertices || start < 0 || end < 0 )
    {
        cout << "Invalid Entry" ;
        return ;
    }
    Adjmatrice[start][end] = 1 ;
    Adjmatrice[end][start] = 1 ;
}
// 2. Function To Delete 
void Graph :: DeleteEdge(int start , int end)
{
    if(start >= NumVertices || end >= NumVertices || start < 0 || end < 0 )
    {
        cout << "Invalid Entry" ;
        return ;
    }
    if(Adjmatrice[start][end] = 0 )
    {
        return ; 
    }
    Adjmatrice[start][end] = 0 ;
    Adjmatrice[end][start] = 0 ;
    
}
// 3. Function To Search 
void Graph :: SearchEdge(int start , int end)
{
    if(start >= NumVertices || end >= NumVertices || start < 0 || end < 0 )
    {
        cout << "Invalid Entry" ;
    }
    if (Adjmatrice[start][end] == 1)
    {
        cout << "Edge exists between " << start << " and " << end << ".\n";
    }        
    else
        cout << "Edge does not exist between " << start << " and " << end << ".\n";
    

    
}
// 4. Function to Display 
void Graph :: Display()
{
    for(int i = 0 ; i < NumVertices ; i++)
    {
        for(int j = 0 ; j < NumVertices ; j++)
        {
            cout << Adjmatrice[i][j] << " " ;
        }
        cout << endl ;
    }
}