#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
  int T, N ;

  cin>>T ; 
  

  while(T--){
   
   cin>> N;
   int arr[N];

   
  
int flag =0 ;

   for(int i=0;i<N;i++){
   	cin>>arr[i];

   }

     int left_arr[N];

    left_arr[0] = 0 ;

    for(int l = 1; l<N;l++){
    	left_arr[l] = left_arr[l-1] + arr[l-1];
    }

    int right_arr[N];

    right_arr[N-1] =0;

    for(int r = N-2; r>=0 ;r-- ){
    	right_arr[r] = right_arr[r+1] + arr[r+1];
    }


   for(int i =0;i<N;i++){
   	 if(left_arr[i]==right_arr[i]) flag =1;



   }
    
    
  if(flag==1){
  	cout<<"YES"<<endl;
  }
  else {
  	cout<<"NO"<<endl;
  }
 






  }


    return 0;
}
