#include <iostream> 
using namespace std;


int main(){
int T;
cin>>T;
while(T--){

unsigned int N ;
cin>>N;

int numOfBits = sizeof(N) * 8;  

for(int i=0;i<numOfBits;i++){
 N = N^(1<<i);
}


cout<<N;

}






	return 0;
}