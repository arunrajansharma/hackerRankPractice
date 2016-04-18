#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, N;
    cin>>T;
    while(T--) {
      cin>>N;

      int arr[N] ;

      for(int i=0;i<N;i++){
      	cin>>arr[i];
      }

      int max_sum =0;

      int left = 0 ;   // Left index of desired sub array

      int right = -1 ;  // Right index of desired sub array

      int local_sum = 0;  // Initial 

      for(int i=0; i<N ; i++){
         
         local_sum += arr[i];

         if(local_sum <0 && i< N-1){ 
         	left = i+1 ;
         	local_sum =0;

         }

         if(local_sum >max_sum ){
         	max_sum = local_sum ;
         	right = i;
         }


      }

  int result =0;
    for(int k=left;k<=right;k++){
result+=arr[k];
    }

    cout<<result<<endl;




    }




    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
