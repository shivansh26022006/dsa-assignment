#include<iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    int arr[5][5];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Sum of each row: " << endl;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " : " << rowSum << endl;
    }
    cout << "Sum of each column: " << endl;
    for (int j = 0; j < cols; j++) {   
        int colSum = 0;
        for (int i = 0; i < rows; i++) {  
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " : " << colSum << endl;
    }
    return 0;
}