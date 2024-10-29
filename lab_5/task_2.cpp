#include <iostream>
using namespace std;

#define SIZE 5 

class Queue {
private:
    int front, rear;
    int queue[SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Enqueue: Add an element to the rear of the queue
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot add element: " << element << endl;
            return;
        }
        if (front == -1) front = 0;  // If inserting the first element
        rear++;
        queue[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue: Remove and return the element from the front of the queue
    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;  // Return a sentinel value to indicate error
        }
        int element = queue[front];
        cout << "Dequeued: " << element << endl;

        // Shift front forward, and reset the queue if it becomes empty
        if (front == rear) {
            front = -1;
            rear = -1;  // Queue is now empty
        } else {
            front++;
        }
        return element;
    }

    // Display the first element at the front of the queue
    void FirstElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "First element is: " << queue[front] << endl;
        }
    }

    // Clear: Release memory by resetting the queue
    void Clear() {
        front = -1;
        rear = -1;
        cout << "Queue cleared." << endl;
    }
};

int main() {
    Queue q;
    
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);  

    q.FirstElement();

    q.Dequeue();  
    q.Dequeue();  

    q.FirstElement();

    q.Clear();  

    return 0;
}
