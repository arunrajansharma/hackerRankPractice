#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int MyFun(int a, int b, int bot){
    int offset ;
    int base ;
    if(a>b){base = a-b; }    else {base = b-a;} 
    if(bot ==-1) {
        return base;
    }
    if(bot>a) { offset = bot-a; } else { offset = a-bot;}
    
    return(base+offset);
       
    
}

int twoRob(int R1, int R2, int N){
    if(N==0){
        return 0;
    }
    
    else{
        
        N--;
        cout<<"Now N is  "<<N<<endl;
        int a,b;
        cin>>a>>b;
        
        if(R1==-1){   // First move being given to bot 1
            
            int result;
             if(a>b){result = a-b; }    else {result = b-a;} 
            
            
            return(result + twoRob(b,R2,N)); 
            
        }
        
        int result_1, result_2;
        
        result_1 = MyFun(a,b,R1);
        cout<<"Now result_1 is  "<<result_1<<endl;
       
        
        
        
        result_2 = MyFun(a,b,R2);



        cout<<"Now result_2 is  "<<result_2<<endl;


        result_1 += twoRob(b,R2,N) ;
        
        result_2 += twoRob(R1,b,N) ;
        
        if(result_1>=result_2) return result_2; else { return result_1; }  
        
        
    }
    
    
}


int main() {
   
    int T,M,N;

    cin>>T;

    while(T--){

        cin>>M>>N;
        
        int R1 ;
        R1 = -1;
        int R2 ;
         R2 = -1;

         while()
        
        int result =  twoRob(R1,R2,N);
        
        cout<<result<<endl;
            
                 
            
        }
        
    
    
    return 0;
}
