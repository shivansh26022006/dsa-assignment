#include <iostream>
#include <string>
using namespace std;

#define MAX 100   // max size of stack

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    int isEmpty() {
        return (top == -1);
    }

    int isFull() {
        return (top == MAX - 1);
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        if (isEmpty()) {
            return '\0';  // return null if nothing to pop
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};
int isMatchingPair(char open, char close){
	if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}
int main(){
	Stack s;
	string str;
	cout<<"Enter String : ";
	getline(cin, str);
	int len=str.length();
	for(int i=0;i<len;i++){
		char c=str[i];
		if(c=='('||c=='{'||c=='['){
			s.push(c);
		}
		else if(c==')'||c=='}'||c==']'){
			if(s.isEmpty()){
				cout<<"Expression does not have balanced paranthesis"<<endl;
			}
			else{
				char top=s.pop();
				if(isMatchingPair(top, c)==0){
					cout<<"Expression does not have balanced paranthesis.";
					return 0;
				}
			}
		}
	}
	if(s.isEmpty()){
		cout<<"Expression has balanced paranthesis."<<endl;
	}
	else
		cout<<"Expression does not have balanced paranthesis.";
}