#include  <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node *front = 0;
struct Node *rear = 0;

void enqueue(int x) {
    struct Node *NewNode;
    NewNode = (struct Node*)malloc(sizeof(struct Node));
    if(!NewNode) {
        cout << "Overflow!" << endl;
        exit(1);
    }
    NewNode->data = x;
    NewNode->next = 0;
    if (front == 0 && rear == 0) {
        front = rear = NewNode;
    } else {
        rear->next = NewNode;
        rear = NewNode;
    }
}

void dequeue() {
    struct Node *temp;
    temp = front;
    if (front == 0 && rear == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    else{
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        free(temp);
    }
}

void peek() {
    if (front == 0 && rear == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << front->data << endl;
}

void display() {
    struct Node *temp;
    if (front == 0 && rear == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    else {
        temp = front;
        cout << "Queue elements: ";
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}