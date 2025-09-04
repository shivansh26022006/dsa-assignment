#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the value of n:";
  cin>>n;
  int max=(n*(n+1))/2;
  int a[max];
  cout<<"Enter the array elements:";
  for(int i=0;i<max;i++){
    cin>>a[i];
  }
  int k=0;
  cout<<"Lower triangle"<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if((i==j)||(i>j))
      {
        cout<<a[k]<<" ";
        k++;
      }
      else{
        cout<<"0"<<" ";
      }
    }
    cout<<endl;
  }
}