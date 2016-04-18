#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;


      
       int arr[n]; int flag =0;
       int second_flag =0;
      for(int i=0;i<=n && flag==0;i++){
      	 for(int j=n;j>=0;j--){

           if(i+j==n){

            if(j%3 ==0 && i%5 ==0){  // ideal condition
            	flag =1;
                  if(j>0){
                  	second_flag =1;
                  	for(int k=0;k<j;k++){
                  		arr[k] = 5;
                  	 }
                  	for(int k=j;k<n;k++){
                  		arr[k] = 3;

                    	}
                    
                      }

                     if(second_flag==0){ 
                     	for(int k=0;k<i;k++) {
                     		arr[k]=3;


                     }
                   }

                   
                } 

           }





      	 }
      }

      if(flag==1){
      	for(int k=0;k<n;k++){
      		cout<<arr[k];
      	}
      	cout<<endl;
      }

      else{
      	cout<<-1<<endl;
      }


    }
    return 0;
}
         