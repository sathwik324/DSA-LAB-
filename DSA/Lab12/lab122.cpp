#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <list> 
using namespace std ;

class Graph {
    private :
       list <int>*  Adjlist ;
       int NumVertices ;
    public : 
       Graph(int vertices)
       {
        if (vertices <= 0) {
            cout << "Number of vertices must be positive.\n";
            exit(1);
        }
        NumVertices = vertices;
        Adjlist = new list<int>[vertices];
       } 
       
       
       ~Graph()
       {
       delete[] Adjlist ;
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
    Adjlist[start].push_back(end);
    Adjlist[end].push_back(start);     
}
// 2. Function To Delete 
void Graph :: DeleteEdge(int start , int end)
{
    if(start >= NumVertices || end >= NumVertices || start < 0 || end < 0 )
    {
        cout << "Invalid Entry" ;
        return ;
    }
    Adjlist[start].remove(end);
    Adjlist[end].remove(start);
}
// 3. Function To Search 
void Graph :: SearchEdge(int start , int end)
{
    if(start >= NumVertices || end >= NumVertices || start < 0 || end < 0 )
    {
        cout << "Invalid Entry" ;
    }
    for (int neighbour : Adjlist[start])
    {
        if(neighbour == end)
        {
            cout << "Edge exists between"<<start<<"and"<<end ;
            return ; 
        }
    }
    cout << "edge does not exist" ;   
}
// 4. Function to Display 
void Graph :: Display()
{
    for(int i = 0 ; i < NumVertices ; ++i)
    {
        cout << i <<"-->" ;
        for(int neighbour : Adjlist[i])
        {
            cout << neighbour << " " ;
        }
        cout << endl ;
    }   
}