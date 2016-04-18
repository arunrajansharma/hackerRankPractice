#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

  int N,K,Q;
  cin>>N>>K>>Q;
  int arr[N];
  int index =0;
  
  for(int i=0;i<N;i++){
  	cin>>arr[i];
  }

  int magic_value = K%N;

while(Q--){
	cin>>index;

	 

	 if(magic_value == 0 )  // No change in positions
	 {
	 	cout<<arr[index]<<endl;
	 	continue;
	 }
  
    
     if(index ==0 ){
     	cout<<arr[N- magic_value]<<endl;
     	continue;
     }
 
     if(index == magic_value){
     	cout<<arr[0]<<endl;
     	continue;
     }


    int temp = index - magic_value;

    if(temp>0){
    	cout<<arr[temp]<<endl;
    	continue;
    }

     if( temp <0){
     	cout<<arr[N+temp]<<endl;
     }


}


    return 0;
}
