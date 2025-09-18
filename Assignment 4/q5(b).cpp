#include <iostream>
using namespace std;
#define SIZE 20
class StackOneQueue {
    int q[SIZE];
    int f, r;   
public:
    StackOneQueue() { f = r = -1; }
    bool isEmpty() { return (f == -1); }
    void enqueue(int x) {
        if (r == SIZE - 1) { cout << "Overflow\n"; return; }
        if (f == -1) f = 0;
        q[++r] = x;
    }
    int dequeue() {
        if (f == -1) return -1;
        int val = q[f++];
        if (f > r) f = r = -1;
        return val;
    }
    int size() { return (f == -1) ? 0 : (r - f + 1); }
    void push(int x) {
        int s = size();
        enqueue(x);
        for (int i = 0; i < s; i++) {
            enqueue(dequeue());
        }
    }
    void pop() {
        if (isEmpty()) { cout << "Stack empty\n"; return; }
        cout << "Popped: " << dequeue() << endl;
    }
    void display() {
        if (isEmpty()) { cout << "Stack empty\n"; return; }
        cout << "Stack: ";
        for (int i = f; i <= r; i++) cout << q[i] << " ";
        cout << endl;
    }
};
int main() {
    StackOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}