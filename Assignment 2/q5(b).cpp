#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the order of matrix : ";
  cin>>n;
  int max=(3*n-2);
  int a[max];
  cout<<"Enter the elements: ";
  for(int i=0;i<max;i++)
  {
    cin>>a[i];
  }
  int p=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==j || i-j==1 || i==j-1)
      {
        cout<<a[p]<<" ";
        p++;
      }
      else
      {
        cout<<"0 ";
      }
    }
    cout<<endl;
  }
}