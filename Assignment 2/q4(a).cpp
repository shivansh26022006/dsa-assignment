#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str1[100], str2[50];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    strcat(str1, str2); 
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
