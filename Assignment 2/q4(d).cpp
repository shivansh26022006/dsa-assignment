#include <iostream>
#include <cstring>   
using namespace std;
int main() {
    char str[10];
    cout << "Enter a string: ";
    cin >> str;
    int len = strlen(str);   
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {   
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "String in alphabetical order: " << str << endl;
    return 0;
}
