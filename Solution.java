import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
      int A, B, N;
      Scanner sc = new Scanner(System.in);
      A =sc.nextInt();
      B = sc.nextInt();
      N = sc.nextInt();

      BigInteger[] bigArray = new BigInteger[N];

      bigArray[0] =  new BigInteger(String.valueOf(A));
      bigArray[1] =  new BigInteger(String.valueOf(B));

      for(int i=2;i<N;i++){
      	bigArray[i] = (bigArray[i-1].pow(2)).add(bigArray[i-2]);
      }

      System.out.print(bigArray[N-1]);



        
    }



}