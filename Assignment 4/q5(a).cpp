#include <iostream>
using namespace std;
#define SIZE 20
class StackTwoQueues {
    int q1[SIZE], q2[SIZE];
    int f1, r1, f2, r2;   // front and rear pointers
public:
    StackTwoQueues() {
        f1 = r1 = f2 = r2 = -1;
    }
    bool isEmpty() {
        return (f1 == -1);
    }
    void enqueue1(int x) {
        if (r1 == SIZE - 1) { cout << "Overflow\n"; return; }
        if (f1 == -1) f1 = 0;
        q1[++r1] = x;
    }
    void enqueue2(int x) {
        if (r2 == SIZE - 1) { cout << "Overflow\n"; return; }
        if (f2 == -1) f2 = 0;
        q2[++r2] = x;
    }
    int dequeue1() {
        if (f1 == -1) return -1;
        int val = q1[f1++];
        if (f1 > r1) f1 = r1 = -1;
        return val;
    }
    int dequeue2() {
        if (f2 == -1) return -1;
        int val = q2[f2++];
        if (f2 > r2) f2 = r2 = -1;
        return val;
    }
    int size1() { return (f1 == -1) ? 0 : (r1 - f1 + 1); }
    void push(int x) {
        enqueue1(x);
    }
    void pop() {
        if (isEmpty()) { cout << "Stack empty\n"; return; }

        while (size1() > 1) {
            enqueue2(dequeue1());
        }
        cout << "Popped: " << dequeue1() << endl;
        int *tempArr, tf, tr;
        tempArr = q1; tf = f1; tr = r1;
        q1 = q2; f1 = f2; r1 = r2;
        q2 = tempArr; f2 = tf; r2 = tr;
    }
    void display() {
        if (isEmpty()) { cout << "Stack empty\n"; return; }
        cout << "Stack: ";
        for (int i = f1; i <= r1; i++) cout << q1[i] << " ";
        cout << endl;
    }
};
int main() {
    StackTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}