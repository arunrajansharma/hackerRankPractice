#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
string S,T;
cout<<"\n Please enter the first string: ";
cin>>S;
cout<<"\n Please enter the second string: ";
cin>>T;

int s_len = S.length();
int t_len = T.length();

int LCS[s_len][t_len];

for(int i=0;i<s_len;i++){
	for(int j=0;j<t_len;j++){
		LCS[i][j] = 0;          // initialization 
	}
}


for(int i=0;i<s_len;i++){
	for(int j=0;j<t_len;j++){
		
		if(S[i]!=T[j]){
			
			if(i==0 && j==0){
				// do nothing, as already intialized to 0
			}

			else if(i==0 && j!=0 ){
				LCS[i][j] =  LCS[i][j-1];
			}

			else if(i!=0 && j==0){
				LCS[i][j] = LCS[i-1][j];
			}

			else{
				LCS[i][j] = std::max(LCS[i][j-1],LCS[i-1][j]);
			}


		}

		else{

			if(i==0 && j==0){
				LCS[i][j] = 1;
			}

			else if(i==0 && j!=0 ){
				LCS[i][j] =  1+LCS[i][j-1];
			}

			else if(i!=0 && j==0){
				LCS[i][j] = 1+ LCS[i-1][j];
			}

			else{
				LCS[i][j] = 1+ LCS[i-1][j-1];
			}
		}



	}
}


cout<<"\n The Length of the LCS is : "<<LCS[s_len-1][t_len-1]<<"\n" ;



return 0;

}
