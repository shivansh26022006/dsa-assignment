#include <iostream>
using namespace std;
int main(){
  const int SIZE = 100;
  int arr[SIZE];
  int n=0;
  int choice;
  do{
    cout<<"---Menu---"<<endl;
    cout<<"CREATE"<<endl;
    cout<<"DISPLAY"<<endl;
    cout<<"INSERT"<<endl;
    cout<<"DELETE"<<endl;
    cout<<"LINEAR SEARCH"<<endl;
    cout<<"EXIT"<<endl;
    cout<<"Enter choice:"<<endl;
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter the number of elements : ";
        cin>>n;
        cout<<"Enter"<< n <<"elements"<<endl;
        for(int i=0;i<n;i++)
        {
          cin>>arr[i];
        }
        break;
      }
      case 2:{
        if(n==0){
        cout<<"Array is empty"<<endl;
        break;
      }
      cout<<"Array elements : ";
      for(int i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<< endl;
      break;
    }
      case 3:{
        if(n>=SIZE)
        {
          cout<<"Array is full"<<endl;
          break;
        }
        int pos,val;
        cout<<"Enter position to insert(0 to "<<n<<"):";
        cin>>pos;
        if(pos<0||pos>n){
          cout<<"Invalid position"<<endl;
          break;
        }
        cout<<"Enter value to insert:";
        cin>>val;
        for(int i=n;i > pos;i--){
          arr[i]=arr[i-1];
        }
        arr[pos] = val;
        n++;
        cout<<"Elements inserted"<<endl;
        break;
      }
      case 4:{
        if(n==0){
          cout<<"Array is empty"<<endl;
          break;
        }
        int pos;
        cout<<"Enter the position to delete(0 to "<<n-1<<"):";
        cin>>pos;
        if(pos<0||pos>=n){
          cout<<"invalid position"<<endl;
          break;
        }
        for(int i=pos;i<n-1;i++){
          arr[i]=arr[i+1];
        }
        n--;
        cout<<"Element deleted"<<endl;
        break;
      }
      case 5:
      {
          if(n==0){
            cout<<"Array is empty"<<endl;
            break;
          }
          int val,found=0;
          cout<<"Enter the value to search"<<endl;
          cin>>val;
          for(int i=0;i<n;i++){
            if(arr[i]==val){
              cout<<"Element found at index"<<i<<endl;
              found=1;
              break;
            }
          }
          if(!found){
            cout<<"Element not found"<<endl;
          }
          break;
      }
      case 6:
      {
        cout<<"Exiting program"<<endl;
        break;

        default:
        cout<<"Invalid choice.Try again"<<endl;
      } 
    }
  }
while(choice!=6);
return 0;
}