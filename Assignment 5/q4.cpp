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
    if (p == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Linked List: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void reverseList() {
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    while (curr != NULL) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;        
        curr = next;         
    }
    head = prev; 
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
    cout << "\nOriginal ";
    print();
    reverseList();
    cout << "Reversed ";
    print();
    return 0;
}