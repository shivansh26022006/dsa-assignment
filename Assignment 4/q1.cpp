#include <iostream>
using namespace std;
#define Size 5
class Queue{
	private:
		int arr[Size];
		int front, rear;
	public:
		Queue(){
			front=rear=-1;
		}
		bool isEmpty(){
			return (front==-1||front>rear);
		}
		bool isFull(){
			return (rear==Size-1);
		}
		void enqueue(int value){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
			if(isEmpty()){
				front=0;
			}
			rear=rear+1;
			arr[rear]=value;
		}
		void dequeue(){
			if(isEmpty()){
				cout<<"Queue is empty!"<<endl;
				return;
			}
			int removed=arr[front];
			if(front==rear){
				front=rear=-1;
			}
			else{
				front=front+1;
			}
			cout<<"Removed element : "<<removed<<endl;
		}
		void peek(){
			if(isEmpty()){
				cout<<"Queue is empty."<<endl;
			}
			else{
				cout<<"Front element is : "<<arr[front]<<endl;
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"Queue is empty!"<<endl;
			}
			else{
				cout<<"Queue : ";
				for(int i=front;i<=rear;i++){
					cout<<arr[i]<<" ";
				}
			}
		}
};
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is Empty." : "Queue is NOT Empty.") << endl;
            break;
        case 6:
            cout << (q.isFull() ? "Queue is Full." : "Queue is NOT Full.") << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}