import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T>0){
        	int N = sc.nextInt();

        	int[] price = new int[N];
        	for(int i=0;i<N;i++){
        		price[i] = sc.nextInt();
        	}

          // Magic begins here
           int[][] arr = new int [N][N];
           for(int i=0;i<N;i++){
           	for(int j=0;j<N;j++){
           		arr[i][j] = -1;
           	}
           }

        	int result = funDP(0,0,price,arr) ;

        	System.out.println(result);

        	

        	T--;

        }
    
    } // end of main

static int fun (int i, int s, int[] price){
	if(i>=price.length){
		return 0;
	}

	int nothing = fun(i+1,s,price);

	int buy = fun(i+1,s+1,price) - (price[i]);

	int sell = 0; 
	for(int t = 1; t<=s; t++){

		int lMax = fun(i+1,s-t,price) + (price[i]*t) ;
		if(lMax >= sell){
			sell = lMax;
		}
	}

	int result = Math.max(nothing,Math.max(buy,sell));

	return result;
} // end of 'normal' fun()


static int funDP (int i, int s, int[] price, int [][] arr){
	if(i>=price.length){
		return 0;
	}

	if(arr[i][s]!=-1) return arr[i][s];

	int nothing = fun(i+1,s,price);

	int buy = fun(i+1,s+1,price) - (price[i]);

	int sell = 0; 
	for(int t = 1; t<=s; t++){

		int lMax = fun(i+1,s-t,price) + (price[i]*t) ;
		if(lMax >= sell){
			sell = lMax;
		}
	}

	int result = Math.max(nothing,Math.max(buy,sell));
    
    arr[i][s] = result;

 
	return result;
} // end of 'DP' fun()




}