#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */


/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
   
    std::sort(_a.begin(),_a.end());

    int count =0;

 
    for(int i=0;i<_a_size;i++){
             int flag =0;
    for(int j = _a_size-1;j>=0 && flag==0;j--){

        if(_a[j]-_a[i] ==_k){
            count++;
            flag =1;

        }
    }

    }
              
    


    
    cout << count;
    
    
    return 0;
}
