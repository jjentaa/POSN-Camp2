#include <iostream>
using namespace std;

class AStack
{
private:
    int maxSize;    // Maximum size of stack
    int top;        // Index for top element
    int *listArray; // Array holding stack elements

public:
    AStack(int size) // Constructor
    {
        maxSize = size;
        top = 0;
        listArray = new int[size];
    }

    ~AStack() { delete[] listArray; } // Destructor

    void clear() { top = 0; } // Reinitialize

    void push(int it)
    { // Put "it" on stack
        if (top == maxSize)
            cout << "Stack is full" << endl;
        else
            listArray[top++] = it;
    }

    int pop()
    { // Pop top element
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return -1;
        } else return listArray[--top];
    }

    int topValue()
    { // Return top element
        if (top == 0)
            cout << "Stack is empty" << endl;
            return -1;
        return listArray[top - 1];
    }

    int length() { return top; } // Return length

    void viewAll()
    {
        for (int i = 0; i < top; i++)
            cout << listArray[i] << " ";
        cout << endl;
    }
};

int main() {
    AStack *st = new AStack(5);

    for(int i = 0; i < 7; i++)
        st->push(i);
    
    st->viewAll();

    for(int i = 0; i < 7; i++)
        cout << st->pop() << endl;
}