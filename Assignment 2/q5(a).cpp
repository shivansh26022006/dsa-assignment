#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of diagonal matrix (n): ";
    cin >> n;
    int diag[10];
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) {
        cin >> diag[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j){
            	cout << diag[i] << " ";
			}
            else{
            	cout <<"0 ";
			} 
        }
        cout << endl;
    }
    return 0;
}
