#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){



    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        long L;
        long R;
        cin >> L >> R;
   

        long A = 1;

        for(long i =2;i<=L;i++){
        	A^=i;
        }

        long B = 1 ;
        for(long j =2;j<=R;j++){
        	A^=j;
        }
      

       cout<<(A^B)<<endl;

   }
    return 0;
}
