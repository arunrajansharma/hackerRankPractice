/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
#include<array>

using namespace std;
int main(void){

 

//Helpers for input and output

   int N, K;
   cin >> N >> K;
    int C[N];

 

   for(int i = 0; i < N; i++){
      cin >> C[i];
   }

   std::sort(C,C+N,std::greater<int>());  // TO sort in Descending order

 


   int result =0;
   int diff = N-K;
   int index =0 ;
   

  

   for(int i=0;i<=diff;i++){
      
      int K_ = K;
     while(K_-- && index <N){
     	result += (i+1)* C[index];
     	
     	index++;
     }

   
   }
   

 cout<<result;



   return 0;
   }