#include <iostream>
#include <cmath>
using namespace std;

int main(){
	 
	 cout<<"Please Enter the total number of numbers "<<endl;
     int N;
     cin>>N;
     int A[N];
     int S[N];
     

     cout<<"Please start entering the numbers\n";

     for(int i=0;i<N;i++){
        cin>>A[i];
        S[i] = 1;

     }

     // Logic Starts from Here

     for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[j]<=A[i]){
                if(S[j]+1 > S[i]){
                    S[i] = S[j]+1 ;
                }

            }
        }
     }



cout<<"The length of the longest non-decreasing sequence :" <<S[N-1];
cout<<"\nThe Solution Array is \n";


  for(int i=0;i<N;i++){
        
        cout<<S[i]<<" ";

     }

     

}