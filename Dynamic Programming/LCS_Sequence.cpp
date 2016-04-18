#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

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


cout<<"\nThe LCS Matrix is ready, We will print the sequnce now \n";

int r = s_len-1;
int c = t_len-1;

std::stack<char> myStack;

while(r>=0 || c>=0){

	

if(r==0 && c>0){
	if(LCS[r][c-1]==0){
		myStack.push(S[r]);
		c--;
	}

	if(LCS[r][c-1] ==  LCS[r][c]){
		c--;
	}

}

if(c==0 && r>0){

   if(LCS[r-1][c]==0){
	myStack.push(S[r]);
	r--;
   }

   if(LCS[r-1][c] == LCS[r][c]){
   	r--;
   }

}

if(c>0 && r>0){
	if(LCS[r][c-1]<LCS[r][c]  && LCS[r-1][c] < LCS[r][c]){
		myStack.push(S[r]);
		r--;
		c--;
	}

 if(LCS[r][c-1]==LCS[r][c]){
 	c--;
 }
 if(LCS[r-1][c] == LCS[r][c]){
 	r--;
 }

}

if(c==0 && r==0){
	if(LCS[r][c]==1){
		myStack.push(S[r]);
		
	}

	r--;
		c--;
}

}

while(!myStack.empty()){
	cout<<myStack.top();
	myStack.pop();
}

return 0;

}
