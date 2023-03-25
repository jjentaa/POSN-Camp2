#include <iostream>
using namespace std;

class Node
{
public:
    int element; // Value for this node
    Node *next;  // Pointer to next node in list
    // Constructors
    Node(int val, Node *next_node = NULL)
    {
        element = val;
        next = next_node;
    }
    Node(Node *nextval = NULL) { next = nextval; }
};

class LStack
{
private:
    Node *top; // Pointer to first element
    int size;  // Number of elements

public:
    LStack() // Constructor
    {
        top = NULL;
        size = 0;
    }

    ~LStack() { clear(); } // Destructor

    void clear()
    { // Reinitialize
        while (top != NULL)
        { // Delete nodes
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0; // Number of elements
    }

    void push(int it)
    { // Put "it" on stack
        top = new Node(it, top);
        size++;
    }
    int pop()
    { // Remove "it" from stack
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return 0;
        } else {
            int it = top->element;
            Node *ltemp = top->next;
            delete top;
            top = ltemp;
            size--;
            return it;
        }
    }

    int topValue() const
    { // Return top value
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return 0;
        } else return top->element;
    }

    int length() const { return size; } // Return length

    void viewAll()
    {
        Node *p = top;
        
        while(p) {
            cout << p->element << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LStack *st = new LStack();

    const int N = 10;

    for(int i = 0; i < N; i++)
        st->push(i);
    
    cout << "Completed pushing. Now view all: ";
    st->viewAll();
    
    cout << "Completed viewing. Now pop all:  ";
    for(int i = 0; i < N; i++)
        cout << st->pop() << " ";
    
    cout << endl;
}