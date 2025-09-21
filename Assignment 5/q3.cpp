#include <iostream>
using namespace std;
struct LL {
    int data;
    struct LL *next;
};
typedef struct LL node;
node *head = NULL, *tail = NULL;
void insertAtEnd(int val) {
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
void print() {
    node *p = head;
    cout << "Linked List: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void findMiddle() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    int length = 0;
    node *p = head;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    int midIndex = length / 2;
    p = head;
    for (int i = 0; i < midIndex; i++) {
        p = p->next;
    }
    cout << "Middle element (Two-Pass): " << p->data << endl;
}
int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertAtEnd(val);
    }
    print();
    findMiddle();
    return 0;
}
