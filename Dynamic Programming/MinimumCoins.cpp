#include <iostream>
#include <cmath>
using namespace std;

int main(){
	 
	 cout<<"Please Enter the total number of coins "<<endl;
     int N;
     cin>>N;
     int coins[N];
     
     cout<<"Please enter the list of coins \n";
     
     for(int i=0;i<N;i++){
     	cin>>coins[i];
     }
    
    cout<<"\nplease enter the value of Sum : S \n";
    int S;
    cin>>S;

    int min[S+1];

    min[0] = 0;  //base case
    
    for(int i=1;i<=S;i++){
    	min[i] = INT_MAX;
    }

    for(int i=1;i<=S;i++){
        for(int j=0;j<N;j++){
        	if(coins[j]<=i && min[(i-coins[j])]+1<min[i]){
        		min[i] = min[(i-coins[j])]+1 ;
        		cout<<coins[j]<<" "<<endl;
        	}
        }

    }

    cout<<"\n The number of minimum coins required are : "<<min[S]<<"\n";




}