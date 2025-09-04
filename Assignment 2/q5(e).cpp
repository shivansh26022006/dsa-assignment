#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of symmetric matrix (n): ";
    cin >> n;
    int sym[10];
    cout << "Enter elements ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> sym[i];
    cout << "Full symmetric matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
            	cout << sym[k++] << " ";
			}
            else {
                int index = j*(j+1)/2 + i;
                cout << sym[index] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
