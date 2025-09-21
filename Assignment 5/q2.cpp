#include <iostream>
using namespace std;
struct LL {
    int data;
    struct LL *next;
};
typedef struct LL node;
node *head = NULL;
node *tail = NULL;
void insertAtEnd(int val) {
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        head = tail = temp;
    } 
	else {
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
int countOccurrences(int key) {
    node *p = head;
    int count = 0;
    while (p != NULL) {
        if (p->data == key) count++;
        p = p->next;
    }
    return count;
}
void deleteAllOccurrences(int key) {
    while (head != NULL && head->data == key) {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    node *p = head;
    while (p != NULL && p->next != NULL) {
        if (p->next->data == key) {
            node *temp = p->next;
            p->next = p->next->next;
            if (temp == tail) tail = p; 
            delete temp;
        } else {
            p = p->next;
        }
    }
}
int main() {
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertAtEnd(val);
    }
    cout << "\nOriginal ";
    print();
    cout << "Enter key to count and delete: ";
    cin >> key;
    int occ = countOccurrences(key);
    cout << "Element " << key << " occurred " << occ << " times." << endl;
    deleteAllOccurrences(key);
    cout << "After deleting all occurrences of " << key << ":" << endl;
    print();
    return 0;
}
