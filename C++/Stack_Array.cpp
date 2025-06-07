#include<iostream>
using namespace std;

#define n 100

class Stack {
    int stack[n];
    int top = -1;

    public:
    // push an element
    void push(){
        int x;
        cout << "Enter the element to push: ";
        cin >> x;
        if (top == n - 1) {
            cout << "Stack overflow\n";
        } else {
            top++;
            stack[top] = x;
            cout << "Element pushed: " << x << endl;
        }
    }

    // pop an element
    void pop(){
        int item;
        if(top == -1) {
            cout << "Stack underflow\n";
        } else {
            item = stack[top];
            top--;
            cout << "Element popped: " << item << endl;
        }
    }

    // peek at the top element
    void peek(){
        if(top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element: " << stack[top] << endl;
        }
    }

    // display all elements
    void display(){
        if(top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            for(int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Stack s;
    int choice;
    do {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 5);
    return 0;
}