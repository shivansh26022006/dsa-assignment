#include <iostream>
using namespace std;
#define SIZE 10
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return (rear == SIZE - 1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    int getElement(int i) {
        return arr[front + i];
    }
};
int main() {
    Queue q, result;
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }
    int half = n / 2;
    for (int i = 0; i < half; i++) {
        result.enqueue(q.getElement(i));         
        result.enqueue(q.getElement(i + half));  
    }
    cout << "Interleaved Queue: ";
    result.display();
    return 0;
}
