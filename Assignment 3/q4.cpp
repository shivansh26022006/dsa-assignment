#include <iostream>
using namespace std;
class Stack{
	private:
		int arr[15];
		int top;
	public:
		Stack(){
			top=-1;
		}
		bool isFull(){
			return (top==15-1);
		}
		bool isEmpty(){
			return (top==-1);
		}
		void push(int a){
			arr[++top]=a;
		}
		int pop(){
			return arr[top--];
		}
		int calc(int a, int b, char c){
			switch(c){
				case '+':
					return a+b;
					break;
				case '-':
					return a-b;
					break;
				case '*':
					return a*b;
					break;
				case '/':
					return a/b;
					break;
			}
	}
};
int main(){
	string str;
	Stack s;
	cout<<"Enter postfix Expression : ";
	cin>>str;
	int a,b,c;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if(isdigit(ch))
			s.push(ch-'0');
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
			b=s.pop();
			a=s.pop();
			c=s.calc(a,b,ch);
			s.push(c);
		}
	
	}
	cout<<"Result : "<<s.pop();
}