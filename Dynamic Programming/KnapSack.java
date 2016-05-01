import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class KnapSack{

public static void main(String[] args){

	Scanner sc = new Scanner(System.in);

	System.out.println("Please Enter the value of N ");

	int N = sc.nextInt();

	int value[] = new int[N];
	int weight[] = new int[N];

	System.out.println("Enter the "+N+" values now ");
	for(int i=0;i<N;i++){
		value[i] = sc.nextInt();

	}

    System.out.println("Enter the "+N+" weights now ");
    for(int i=0;i<N;i++){
		weight[i] = sc.nextInt();

	}

   System.out.println(" Enter the constaint weight now ");
   int S = sc.nextInt();

   int[][] arr = new int[N][S+1];
   for(int i=0;i<N;i++){
   	for(int j=0;j<=S;j++){
   		arr[i][j] = -1;
   	}
   } 

   int result = getValueDP(N-1,S,value,weight,arr);

   System.out.println(result+"   Yeeey");
  





}

static int getValueDP(int n, int s, int[] value, int[] weight, int[][] arr){
int result;



if(n==-1) return 0;
if(arr[n][s] !=-1) return arr[n][s];


if(weight[n] > s){ // we can not use this weight
result = getValueDP(n-1,s,value,weight,arr);

}
else{
result = Math.max((value[n] + getValueDP(n-1,s- weight[n], value, weight,arr)) , getValueDP(n-1,s,value,weight,arr) );

}


arr[n][s] = result;

for(int i=0;i<=2;i++){
	 	System.out.println();
   	for(int j=0;j<=5;j++){
   		System.out.print(" "+arr[i][j]);
   	}
   
   }

   System.out.println();

return result;


} // end of getValueDP method


static int getValue(int n, int s, int[] value, int[] weight){
int result;

if(n==-1) return 0;

if(weight[n] > s){ // we can not use this weight
result = getValue(n-1,s,value,weight);

}
else{
result = Math.max((value[n] + getValue(n-1,s- weight[n], value, weight)) , getValue(n-1,s,value,weight) );

}

return result;


} // end of getValue method




} // end of KnapSack class