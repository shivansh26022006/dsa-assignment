#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100], uniqueArr[100], k = 0;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate==0) {
            uniqueArr[k] = arr[i];
            k++;
        }
    }
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << uniqueArr[i] << " ";
    }
    return 0;
}
