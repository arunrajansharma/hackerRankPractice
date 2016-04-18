#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int M, test;

    std::vector<int> v;

    cin>>M;
    int flag =0;

    while(M--){
    	
    	cin>>test;
    	if(v.empty()){
    		v.push_back(test);
    	}

    	else{
    		if(test>v.back()){
    			v.push_back(test);

    		}
    		else if(test==v.back()){
    			flag =1;
    			break;
    		}

    		else{ 
    			if(test-v.back() ==-1){
    				v.push_back(test);
    			}

    			else{
    				if(std::find(v.begin(),v.end(),(v.back()-1)) != v.end()){
    					v.push_back(test);
    				}
    				else{
    					flag =1;
    					break;
    				}
    			}

    		}
    	}


    }

    if(flag ==0){
    	cout<<"YES";
    }
    else{
    	cout<<"NO";
    }


     return 0;
}
