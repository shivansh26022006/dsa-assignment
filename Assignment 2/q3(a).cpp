#include <iostream>
using namespace std;
int main() {
    const int n = 10;           
    int arr[9];                 
    cout << "Enter 9 numbers from 1 to 10 in sorted order (one missing): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    int expectedSum = n * (n + 1) / 2;  
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }
    int missing = expectedSum - actualSum;
    cout << "Missing number is: " << missing << endl;
    return 0;
}
