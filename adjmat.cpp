/* Implementing Adjacency Matrix */

#include <iostream>
#include <cstdio>
using namespace std;

struct AdjMatGraph {
int V ;
int E;
int ** AdjMat;
};

struct AdjMatGraph * MakeGraph (){
 
 struct AdjMatGraph * G = (struct AdjMatGraph *) malloc (sizeof(struct AdjMatGraph));
 if(!G){
 	cout<<"Memory Error 1\n";
 }

//Taking Input #Vertices, #Edges
cout<<"Please Enter Number of Vertices and Edges\n";
int a,b;
cout<<"Vertices :"; cin>>G->V;
cout<<"Edges : " ; cin>>G->E; 


 
//Creating required space for the Matrix
G->AdjMat = (int**) malloc(G->V * sizeof(int*));
for(int k =0;k<G->V;k++){
	G->AdjMat[k] = (int *) malloc (G->V* sizeof(int));
}

if(!G->AdjMat) {
	cout<<"Memory Error 2\n";
}

 // Innitialization Adjacency Matrix

for(int u=0;u<G->V;u++){
	for(int v=0;v<G->V;v++){
       G->AdjMat[u][v] = 0;

	}
}

//Reading Edges of the Graph
cout<<"\n Please Enter the edges as a pair\n";
cout<<"You have to enter :"<<G->E<<" edges\n";
int u,v;


for(int i=0;i<G->E;i++){
 cin>>u;
 cin>>v;

//Creating an edge in the Matrix
G->AdjMat[u][v]=1;
}

return G; 

}


int main(){

cout<<"It is time to Wake up\n";
cout<<"Let's create a Graph\n";

struct AdjMatGraph * G = MakeGraph();

cout<<"\n I Guess the Graph got created, Let's print it\n";

for(int u=0; u<G->V;u++){
	for(int v=0;v<G->V;v++){
		cout<<G->AdjMat[u][v]<<" ";
	}
	cout<<endl;
}


return 0;

}