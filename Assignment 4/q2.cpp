#include <iostream>
using namespace std;
#define Size 10
class CircularQueue{
	private:
		int arr[Size];
		int front,rear;
	public:
		CircularQueue(){
			front=rear=-1;
		}
		bool isEmpty(){
			return (front==-1);
		}
		bool isFull(){
			return ((rear+1)%Size==front);
		}
		void enqueue(int value){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
			if(isEmpty()){
				front=rear=0;
			}
			else{
				rear=(rear+1)%Size;
			}
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
				front=(front+1)%Size;
			}
			cout<<"Removed element : "<<removed<<endl;
		}
		void peek(){
			if(isEmpty()){
				cout<<"Queue is empty!"<<endl;
				return;
			}
			else{
				cout<<"Peek element : "<<arr[front]<<endl;
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"Queue is empty!"<<endl;
				return;
			}
			else{
				int i=front;
				while(true){
					cout<<arr[i]<<" ";
					if(rear==i)
						break;
					i=(i+1)%Size;
				}
				cout<<endl;
			}
		}
};
int main(){
	CircularQueue cq;
	int value, choice;
	do{
		cout << "\n----- Circular Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        	case 1:
        		cout<<"Enter value to enqueue : ";
        		cin>>value;
        		cq.enqueue(value);
        		break;
        	case 2:
        		cq.dequeue();
        		break;
        	case 3:
        		cq.peek();
        		break;
        	case 4:
        		cq.display();
        		break;
        	case 5:
        		cout<<(cq.isEmpty()?"Queue is empty!":"Queue is not empty!");
        		break;
        	case 6:
        		cout<<(cq.isFull()?"Queue is full!":"Queue is not full!");
        		break;
        	case 7:
        		cout<<"Exiting"<<endl;
        		break;
        	default:
        		cout<<"Wrong choice entered!"<<endl;
		}
	}while(choice!=7);
}