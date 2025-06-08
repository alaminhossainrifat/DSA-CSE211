#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node* next;
};

struct Node* top;

void push(int data) {
    struct Node* temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    // Check if memory(heap) is full.
    if (!temp){
        cout << "\n Heap Overflow";
        exit(1);
    }
    temp->value = data;
    temp->next = top;
    top = temp;
}

int pop(){
    struct Node* temp;
    int data;
    if(top == NULL) {
        cout << "\n Stack Underflow";
        exit(1);
    }
    else{
        data = top->value;
        temp = top;
        top = top->next;
        free(temp);
        return data;
    }
}

int peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return -1;
    } else {
        return top->value;
    }
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements: ";
        struct Node* temp = top;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    cout << "Popped value: " << value << endl;
                break;
            case 3:
                value = peek();
                if (value != -1)
                    cout << "Top value: " << value << endl;
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}