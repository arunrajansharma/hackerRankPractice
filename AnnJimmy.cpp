#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

  int N;
  cin>>N;

  int max_val = -1;
  for(int i=1;i<=N;i++){
  	for(int j=1;j<=N;j++){
        int k = N-(i+j);
        if(k<=0){
        	break;
        }

        int loc_val = i*j*k; 
        if(loc_val>max_val){
        	max_val = loc_val;
        }

  		
  	}
  }


   cout<<max_val;
	return 0;

}
