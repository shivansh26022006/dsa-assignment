#include<iostream>
using namespace std;
int main()
{
  int A[10][10],transpose[10][10];
  int rows,cols;
  cout<<"Enter number of rows and columns: ";
  cin >> rows >> cols; 
  cout<<"Enter elements of matrix: "<<endl;
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cin >> A[i][j];
    }
  }
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      transpose[j][i]=A[i][j];
    }
  }
  cout<<"Transpose of matrix: "<<endl;
  for(int i=0;i<cols;i++){
    for(int j=0;j<rows;j++){
      cout<<transpose[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}