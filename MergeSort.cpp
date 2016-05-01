#include<iostream>
#include<stdio.h>
using namespace std;
void mergelist(int L[],int nl,int R[],int nr,int A[])
{

    int i=0;
    int j;
    int k=0;
    while(i<nl && j<nr)
    {
    if(L[i]<=R[j])
    {
        A[k]=L[i];
        i=i+1;
        k=k+1;
    }
    else{
        A[k]=R[j];
        j=j+1;
        k=k+1;
    }
    }
    while(i<nl){
        A[k]=L[i];
        i=i+1;
        k=k+1;
    }
    while(j<nr){
        A[k]=R[j];
        j=j+1;
        k=k+1;
    }
}

void newMerge(int A[], int na, int B[], int nb, int C[], int nc){

    if(na<=0){ // if first list is empty, copy all the elements from second list into third list
        for(int i=0;i<nb;i++){
            C[i] = B[i];
        }

        return;
    }

    if(nb<=0){ // if second list is empty, copy all the elements from first list into third list
        for(int i=0;i<na;i++){
            C[i] = A[i];
        }

        return;

    }

    // now both lists have some data and we need to store that 'properly' in the third list

   int i,j,k;
   i=j=k=0;

   while(i<na && j<nb){
      
       if(A[i]<=B[j]){
        C[k] = A[i];
        i++;
        k++;
       }

       else{
        C[k] = B[j];
        j++;
        k++;
       }


   }
 
   while(i<na){ //means second list got over before the first, now we need to dump the remaining element in C
       C[k] = A[i];
       i++;
       k++;

   }
  
  while(j<nb){ //means first list got over before the second, now we need to dump the remaining element in C
    C[k] = B[j];
    j++;
    k++;
  }




}



void mergesort(int A[],int n)
{


    if(n<2)
     return;
    int mid=n/2;
    int L[mid];
    int R[n-mid];
    int i;
    for(i=0;i<=mid-1;i++)
    {
        L[i]=A[i];

    }
    for(i=mid;i<n;i++)
    {
        R[i-mid]=A[i];

    }
    mergesort(L,mid);
    mergesort(R,n-mid);
    newMerge(L,mid,R,n-mid,A,n);
}
int main()
{
    int A[]={4,7,3,9,1,2,5,6};
    int na= sizeof(A)/sizeof(A[0]);



    mergesort(A,na);
    cout<<na<<endl;
   // mergesort(A,na);
    for(int i=0;i<na;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
