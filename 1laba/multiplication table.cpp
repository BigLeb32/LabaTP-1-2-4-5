#include <iostream>
#include <vector>
using namespace std;

int main()
{ int j,i,n;
  vector<int> tabl1{1,2,3,4,5,6,7,8,9};
  vector<int> tabl2{1,2,3,4,5,6,7,8,9};
    cout<<"Vvedite razmernost: ";
    cin>>n;
    for (int j = 0; j < n; j++ ){
    for (int i = 0; i < n; i++ ){
  cout<<tabl1[j]<<" x "<<tabl2[i]<<" = "<<tabl1[j]*tabl2[i]<<"\n";
  }}
}
