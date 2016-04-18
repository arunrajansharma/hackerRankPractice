#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;

    std::vector <std::string> Names;
    while(N--){
    	string a;
    	cin>>a;
    	Names.push_back(a);
    }

    int Q;
    cin>>Q;

   while(Q--){
   	string b;
   	int b_count =0;
   	cin>>b;
   	for(int i=0;i<Names.size();i++){
   		if(b==Names[i]) { b_count++;}
   	}

   	cout<<b_count<<endl;
   }


    return 0;
}
