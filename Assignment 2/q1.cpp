#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[5];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the number to search: ";
    cin >> target;
    int start = 0;
    int end = n - 1;
    int result = -1;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] < target) {
            start = mid + 1;     
        }
        else if (target < arr[mid]) {
            end = mid - 1;       
        }
        else {
            result = mid;        
            break;
        }
    }
    if (result != -1)
        cout << "Your number is found at index " << result << endl;
    else
        cout << "Number not found in array" << endl;
    return 0;
}
