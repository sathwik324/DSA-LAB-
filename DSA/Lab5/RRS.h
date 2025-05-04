// Menu header

#ifndef ROBIN_H
#define ROBIN_H

#include <iostream>

using namespace std;

class Process{
    private:
        int t = 0;
        int quantum=3;
        int process_counter = 0;   

        struct Node{
            int process_id ;
            int bt;
            int rem_bt;
            int wt;
            struct Node *next;
        }*head, *tail;

    public:
        Process(){
        head = NULL;
        }
        void insert(int);
        int execute();
        int display();

};

void Process::insert(int bt){
    Node* newProcess = new Node; 
    newProcess->bt = bt;
    newProcess->rem_bt = bt;  
    newProcess->wt = 0;
    newProcess->process_id = ++process_counter;
    newProcess->next = NULL;

    if (head == NULL){
        head = tail = newProcess;
        newProcess->next = head;
    }else{
        tail->next = newProcess;
        newProcess->next = head;
        tail = newProcess;
    }

}

int Process::execute(){
    if (head == NULL) {
         printf("No processes.");
         printf("Total Execution Time:  ");
        return -1; 
    }

    Node *temp = head;
    int id = temp->process_id;

    // RR Schedule Logic
    if (temp->rem_bt > quantum)
        {
            // Increase the value of t i.e. shows how much time a process has been processed
            t += quantum;

            // Decrease the burst_time of current process by quantum
            temp->rem_bt -= quantum;

            // Reinsert at end of queue
            head = head->next;  
            tail->next = temp;
            temp->next = head;  
            tail = temp;        
        }

        // If burst time is smaller than or equal to quantam
        else{
            t = t + temp->rem_bt;
            temp->wt = t - temp->bt;
            temp->rem_bt = 0;
        
            if (head->next == head) 
            {
                delete temp;
                head = tail = NULL;
            } 
            else 
            {
                Node* last = head;
                while (last->next != head){
                    last = last->next;
                }
                head = head->next;
                last->next = head;

                delete temp;
            }
        }
    return id;
}

int Process::display(){
    if(!head){
        printf("No processes.") ;
        return -1;
    }
    Node *temp = head;
    do{
        printf("Process ID:",temp->process_id);
        printf("Burst Time: ",temp->bt);
        printf("Remaining Time: ",temp->rem_bt) ;
        temp = temp->next;
    }while(temp != head);
    return 0;
}
#endif