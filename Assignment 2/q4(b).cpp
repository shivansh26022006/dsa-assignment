#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[10];
    cout << "Enter a string: ";
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}
