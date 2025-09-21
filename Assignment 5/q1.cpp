#include <iostream>
using namespace std;
struct LL {
    int data;
    struct LL *next;
};
typedef struct LL node;
node *head = NULL;
node *tail = NULL;
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
void insertAtBeginning(int val) {
    node *temp = new node;
    temp->data = val;
    temp->next = head;
    head = temp;
    if (tail == NULL) tail = head;
}
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
void insertBefore(int key, int val) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->data == key) {
        insertAtBeginning(val);
        return;
    }
    node *p = head;
    while (p->next != NULL && p->next->data != key) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Node with value " << key << " not found!" << endl;
        return;
    }
    node *temp = new node;
    temp->data = val;
    temp->next = p->next;
    p->next = temp;
}
void insertAfter(int key, int val) {
    node *p = head;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Node with value " << key << " not found!" << endl;
        return;
    }
    node *temp = new node;
    temp->data = val;
    temp->next = p->next;
    p->next = temp;
    if (p == tail) tail = temp;
}
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    if (head == NULL) tail = NULL;
}
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        return;
    }
    node *p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
    tail = p;
}
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->data == key) {
        node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
        return;
    }
    node *p = head;
    while (p->next != NULL && p->next->data != key) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Node with value " << key << " not found!" << endl;
        return;
    }
    node *temp = p->next;
    p->next = temp->next;
    if (temp == tail) tail = p;
    delete temp;
}
void search(int val) {
    node *p = head;
    int pos = 1;
    int found = 0;
    while (p != NULL) {
        if (p->data == val) {
            cout << "Element " << val << " found at position: " << pos << endl;
            found = 1;
        }
        p = p->next;
        pos++;
    }
    if (!found) {
        cout << "Element not found!" << endl;
    }
}
int main() {
    int choice, val, key;

    do {
        cout << "Singly Linked List Menu"<<endl;
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key value: ";
            cin >> key;
            cout << "Enter value to insert before " << key << ": ";
            cin >> val;
            insertBefore(key, val);
            break;
        case 4:
            cout << "Enter key value: ";
            cin >> key;
            cout << "Enter value to insert after " << key << ": ";
            cin >> val;
            insertAfter(key, val);
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteNode(key);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            search(key);
            break;
        case 9:
            print();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
