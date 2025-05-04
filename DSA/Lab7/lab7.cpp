//Program to process strings with '+' symbol
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Stackll.h"

using namespace std;

class StringProcessor
{
    private:
        string inputStr;
        string outputStr;
        
    public:
        StringProcessor()
        {
            inputStr = "";
            outputStr = "";
        }
        void GetInput();
        void ProcessString();
};

int main()
{
    StringProcessor processor;
    int choice;
    do
    {
        cout << "\n   Menu    \n";
        cout << "1. Enter Input String\n";
        cout << "2. Process String\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                processor.GetInput();
                break;
            case 2:
                processor.ProcessString();
                break;
            case 3:
                cout << "Exiting the program";
                break;
            default:
                cout << "Invalid choice! Please try again.";
                cin.clear();
                cin.ignore(10000, '\n');
                break ;
        }
    } while (choice != 3);
    
    return 0;
}

//Function Definitions

// 1. Function to Get Input String
void StringProcessor::GetInput()
{
    cout << "Enter your string: ";
    cin >> inputStr;
}

// 2. Function to Process String
void StringProcessor::ProcessString()
{
    if(inputStr.empty())
    {
        cout << "Error: No input string provided!\n";
        return;
    }
    if(inputStr[0] == '+')
    {
        cout << "Warning: String starts with '+' symbol. There is no character to remove.\n";
    }
    
    Stack charStack;
    

    for (char c : inputStr)
    {
        if (c == '+')
        {
            
            if (!charStack.isEmpty() && charStack.Peek() != '+')
            {
                charStack.Pop();
            }
        }
        else
        {
            
            charStack.Push(c);
        }
    }
    
    
    string tempStr = "";
    Stack tempStack;
    
    
    while (!charStack.isEmpty())
    {
        tempStack.Push(charStack.Pop());
    }
    
    
    while (!tempStack.isEmpty())
    {
        tempStr += (char)tempStack.Pop();
    }
    
    outputStr = tempStr;
    if(outputStr.empty())
    {
        cout << "Error: No processed string available!\n";
        return;
    }
    cout << "Output String: " << outputStr << endl;
}
    

