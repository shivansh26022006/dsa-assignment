#include <iostream>
using namespace std;
#define SIZE 10
class Queue {
    char arr[SIZE];
    int front, rear;
public:
    Queue() { front = rear = -1; }
    bool isEmpty() { return (front == -1); }
    void enqueue(char x) {
        if (rear == SIZE - 1) return;  
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }
    char dequeue() {
        if (isEmpty()) return '\0';
        char val = arr[front++];
        if (front > rear) front = rear = -1;
        return val;
    }
    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};
void firstNonRepeating(string str) {
    int freq[256] = {0};  
    Queue q;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        q.enqueue(ch);
        freq[(int)ch]++;
        while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
            q.dequeue();
        }
        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}
int main() {
    string input;
    cout << "Enter characters : ";
    getline(cin, input);
    cout << "Output: ";
    firstNonRepeating(input);
    return 0;
}