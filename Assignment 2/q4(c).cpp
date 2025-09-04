#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[10];
    cout << "Enter a string: ";
    cin >> str;
    int k = 0;
    for (int i = 0; i<strlen(str); i++) {
        char c = tolower(str[i]);
        if (!(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')) {
            str[k++] = str[i];   // keep consonant
        }
    }
    str[k] = '\0';
    cout << "String without vowels: " << str << endl;
    return 0;
}
