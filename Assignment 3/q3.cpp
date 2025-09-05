#include <iostream>
using namespace std;
class Stack {
	

public:
	
		
    char arr[5];
    int top;
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 5 - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1; // or some error code
        }
        return arr[top--];
    }
    int calc(int a, int b, char c){
	switch(c){
			case '+':
				return a+b;
				break;
			case '-' :
				return a-b;
				break;
			case '*' :
				return a*b;
				break;
			case '/' :
				return a/b;
				break;
		}
	}
};
int main(){
	int arr[5];
	int a,b,c;
	Stack s;
	cout<<"Enter Expression : "<<endl;
	for(int i=0;i<4;i++){
		cin>>arr[i];
	}
	for(int i=0;i<4;i++){
		if(isdigit(arr[i])){
		s.push(arr[i]);
	}
		if(arr[i]=='*'||arr[i]=='+'||arr[i]=='-'||arr[i]=='/'){
			a=s.pop();
			b=s.pop();
			c=s.calc(a,b,arr[i]);
			s.push(c);
		}
	}
	cout<<s.pop();
	
}

