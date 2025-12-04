#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}


void heapSortIncreasing(int arr[], int n) {
    
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

 
    for (int i = n - 1; i > 0; i--) {
        
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

     
        maxHeapify(arr, i, 0);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void heapSortDecreasing(int arr[], int n) {
  
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

 
    for (int i = n - 1; i > 0; i--) {
    
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        minHeapify(arr, i, 0);
    }
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[100], arr2[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];   
    }
    heapSortIncreasing(arr1, n);
    cout << "Heap Sort (Increasing): ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    heapSortDecreasing(arr2, n);
    cout << "Heap Sort (Decreasing): ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
