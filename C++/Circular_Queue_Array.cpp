#include <iostream>
using namespace std;

#define N 5 // Size of the circular queue
int queue[N];
int front = -1, rear = -1;

void enqueue(int x) {
    if(front == -1 && rear == -1) {
        front = rear = 0; 
        queue[rear] = x;
    }
    else if((rear + 1) % N == front) {
        cout << "Queue is full!" << endl;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if(front == -1 && rear == -1) {
        cout << "Queue is empty!" << endl;
    } else if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % N;
    }
}

void peek() {
    if(front == -1 && rear == -1) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}


void display(){
    int i = front;
    if(front == -1 && rear == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    else{
        cout << "Queue elements are: ";
        while(i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % N;
        }
        cout << queue[rear] << endl;
    }
}

int main() {
    int choice, value;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 5);
}