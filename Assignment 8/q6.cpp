#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int size;


    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    void push(int value) {
        heap[size] = value;
        heapifyUp(size);
        size++;
        cout << "Inserted " << value << endl;
    }

   
    int pop() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }

        int removed = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        cout << "Deleted " << removed << endl;
        return removed;
    }

    int top() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int choice, value;

    while (true) {
        cout << " Priority Queue Using Heap \n";
        cout << "1. Insert element\n";
        cout << "2. Delete highest priority element\n";
        cout << "3. Get highest priority element\n";
        cout << "4. Display Priority Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pq.push(value);
                break;

            case 2:
                pq.pop();
                break;

            case 3:
                cout << "Highest priority: " << pq.top() << endl;
                break;

            case 4:
                pq.display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
