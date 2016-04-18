#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool is_prime(int n)
{
     int i,sq,count=0;
     if(n==1 || n==2)
       return true;
     if(n%2==0)
       return false;
     sq=sqrt(n);
     for(i=2;i<=sq;i++)
     {
        if(n%i==0)
          return false;  
     }
      return true;
}

int printPowerSet(int *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    int result =0;

    std::vector<int> v;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
        int sum ;
        sum =0;

      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
       

          if(counter & (1<<j))
          {
            sum+= set[j];    

            

          }

       }

        if(std::find(v.begin(),v.end(),sum)!= v.end()) {
           
           }

       else{
         if(is_prime(sum)) result++;
         v.push_back(sum);

        }

        
       

    }

return result;
}


int main(){

int N;
cin>>N;

int arr[N] ;

for(int i=0;i<N;i++){
  cin>>arr[i];
}

cout<<printPowerSet(arr,N)<<endl;






  return 0;
}





