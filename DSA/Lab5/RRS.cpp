// Main Menu of RR schedule
#include <iostream>

#include "RRS.h"

using namespace std;

int main(){
    Process process;
    int choice, time;
    do{
        printf("\n1.Insert\n2.Execute\n3.Display\n4.Exit\n");
        printf("Enter your choice : ") ;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the process time:"); 
                scanf("%d",&time);
                process.insert(time);
                break;
            case 2:
                process.execute();
                break;
            case 3:
                process.display();
                break;
            case 4:
                printf("Program Exited...") ;
                break;
            default:
                 printf("Invalid Input ") ;
        }
    }while(choice < 4);
}