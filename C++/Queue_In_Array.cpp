#include <iostream>
using namespace std;

const int N = 100;
int queue[N];
int front = -1, rear = -1;

// Enqueue -> Add an element to the end of the queue
void enqueue(int x) {
    if (rear == N - 1) {
        cout << "Queue is full!" << endl;
        return;
    }
    if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

// Dequeue -> Remove an element from the front of the queue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }
    else{
        cout << "Dequeued: " << queue[front] << endl;
        front++;
    }
}

// Peek -> View the front element of the queue without removing it
void peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << queue[front] << endl;
}

// Display -> Show all elements in the queue
void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    else{
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// Main function to demonstrate queue operations
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