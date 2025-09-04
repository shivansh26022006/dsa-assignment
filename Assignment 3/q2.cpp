#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    int n = strlen(str);
    char stack[100];
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[++top] = str[i];
    }
    cout << "Reversed string: ";
    while (top != -1) {
        cout << stack[top--];
    }
    cout << endl;
    return 0;
}
