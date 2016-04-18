#include <iostream> 
#include <queue>
#include <cstdio>
using namespace std;

struct AdjListNode {
	int val;
	struct AdjListNode * next;
};

struct AdjList
{ 
	int head_value;
	int distance;
	struct AdjListNode *head ;
};


struct Graph
{
	int V;
	struct AdjList * array;
    
};

struct AdjListNode * CreateNode(int num){
	struct AdjListNode * newnode = (AdjListNode *)malloc(sizeof(AdjListNode));
	if(!newnode){
		cout<<"Memory Error 1";
		exit(1);
	}
    newnode->val = num;
    newnode->next = NULL;

    return newnode;

}

void AddEdge(struct Graph* graph, int src, int dest){
	struct AdjListNode * newnode =  CreateNode(dest);
	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;
}

struct Graph * CreateGraph(int V){
	struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph ->V = V;

	graph->array = (struct AdjList *)malloc( V * sizeof(AdjList  )) ;    // ouiiiiiiii
	graph->array[0].head = NULL;
	graph->array[0].head_value = -1;
	for(int i=1; i<V;i++){
		graph->array[i].head = NULL;
		graph->array[i].head_value = i;
		graph->array[i].distance = 999;     // initialization
	}


    for(int i=1;i<V-1;i++){
    	AddEdge(graph,i,i+1);
    }

   return graph;

}




int FindMin(struct Graph * graph){
	 
   
	struct AdjList current ;
	graph->array[1].distance = 0; 
	
	int result =-1;

	queue <struct AdjList >  q;
	q.push(graph->array[1]);
     
    int snake = 0 ;

    int ladder = 0;

    while(!q.empty() ) {
    	current = q.front();
    	q.pop();
      cout<<"current : "<<current.head_value;
      cout<<"\n distance : "<<current.distance<<"\n";
    	struct AdjListNode * pCrawl =  current.head ;
        
             if(current.head_value ==100){
          result = (graph->array[current.head_value].distance )/7 +1 ;
 
             break;

        }  
            
        if(current.head_value <=94 && current.head_value >= 89){
        	result = (graph->array[current.head_value].distance )/7 +3 ;

             break;

        }

        if(current.head_value <=99 && current.head_value >= 94){
          result = (graph->array[current.head_value].distance )/7 +2 ;

             break;

        }
      


    	while(pCrawl){

          if(graph->array[pCrawl->val].distance >current.distance){

          	 if(graph->array[pCrawl->val].head_value - current.head_value >1){
          	 	graph->array[pCrawl->val].distance = current.distance ; 
          	 	ladder++; // ladder
 
          	  }
             else{
          	 graph->array[pCrawl->val].distance = current.distance + 1;
          	 }
          }

           if(graph->array[pCrawl->val].distance != 999 && graph->array[pCrawl->val].head_value <current.head_value){
             if(graph->array[pCrawl->val].distance > current.distance){
             	graph->array[pCrawl->val].distance = current.distance ;
             	snake++;
             }
           
           }
           
           q.push(graph->array[pCrawl->val]);

    		pCrawl = pCrawl->next;
    	}

    }


 


 return result;  
}


int main(){

  int V = 101 ;
  struct Graph * graph = CreateGraph(V);


  int T;
  cin>>T;

  while(T--){

  int ladder,snake;

   cin>>ladder;
   int src, dest;
   for(int i=0;i<ladder;i++){
    cin>>src>>dest;
    AddEdge(graph,src,dest);
   }

   cin>>snake;
   for(int i=0;i<snake;i++){
    cin>>src>>dest;
    AddEdge(graph,src,dest);
   }

  cout<<FindMin(graph)<<endl;

 }

	return 0;
}