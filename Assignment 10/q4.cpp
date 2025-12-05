#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = 6;

    unordered_map<int, int> freq;

    for (int x : arr)
        freq[x]++;

    for (int x : arr)
        if (freq[x] == 1) {
            cout << x;
            return 0;
        }

    cout << "No unique element";
}
