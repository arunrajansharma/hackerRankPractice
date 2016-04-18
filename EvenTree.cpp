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
	int magic_value;
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
	

  struct AdjListNode * newnode = CreateNode(src);
  newnode->next = graph->array[dest].head;
  graph->array[dest].head = newnode;

}





struct Graph * CreateGraph(int V){
	struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph ->V = V+1;  // extra 1 for index 0

	graph->array = (struct AdjList *)malloc( (V+1) * sizeof(AdjList) ) ;    
	
  graph->array[0].head = NULL;         // we are not using index 0
	graph->array[0].head_value = -1;
  graph->array[0].magic_value = -1;


	for(int i=1; i<=V;i++){
		graph->array[i].head = NULL;
		graph->array[i].head_value = i;
		graph->array[i].magic_value = 1;     // initialization
	}


    

   return graph;

}

void PrintGraph(struct Graph* graph){

  
  for(int i=1; i<graph->V;i++){
    struct AdjList current = graph->array[i];

    cout<<"head_value : "<<current.head_value<<" magic_value : "<<current.magic_value<<endl; 

    /*

    struct AdjListNode * pCrawl = current.head;
    while(pCrawl){
      cout<<"Head : "<<current.head_value<<"  Node: "<<pCrawl->val <<endl;
      pCrawl = pCrawl ->next;
    }
    */

  }

}



void SetMagicValue(struct Graph* graph, int index){

  struct AdjList current = graph->array[index];


    struct AdjListNode * pCrawl =  current.head ;

    while(pCrawl){

     if(graph->array[pCrawl->val].head == NULL) {
      current.magic_value += 1; 
 
       } // leaf case

     else{ SetMagicValue(graph,pCrawl->val);
           current.magic_value += graph->array[pCrawl->val].magic_value;

       }
  
    pCrawl = pCrawl->next;

   }

   graph->array[index] = current;

 } 

int HasFurtherEven(struct Graph * graph, int index){
     struct AdjList current = graph->array[index];
     if(current.magic_value == 1){
      return 0;
     }
     else if(current.magic_value %2==0) {
      return 1;

     }
     else {
      int result = 0;
      queue <struct AdjList> q;
      q.push(current);
      while(!q.empty()){
       current = q.front();
       q.pop();
       struct AdjListNode * pCrawl =  current.head ;
         while(pCrawl){
          result += HasFurtherEven(graph,pCrawl->val);

          pCrawl = pCrawl->next;

         }

       }

      return result;
   }


}

int EvenTree(struct Graph * graph, int index){
	 
 int result =0; 
 struct AdjList current = graph->array[index];

 queue < struct AdjList > q ;
 q.push(current) ;

 while(!q.empty()){

  current = q.front();
  q.pop();



 struct AdjListNode * pCrawl =  current.head ;

 while(pCrawl){

  if(graph->array[pCrawl->val].magic_value ==2){
    result += 1;
  }

   if(graph->array[pCrawl->val].magic_value % 2 !=0 && HasFurtherEven(graph,pCrawl->val) ==0){
    result += 0 ;
  }
  
  if(graph->array[pCrawl->val].magic_value % 2 !=0 && HasFurtherEven(graph,pCrawl->val)  >0){

    result += EvenTree(graph,pCrawl->val);
  }
  

   if( graph->array[pCrawl->val].magic_value !=2 && graph->array[pCrawl->val].magic_value % 2==0 && HasFurtherEven(graph,pCrawl->val) == 0){
    result = result+ 1;

  }

 if( graph->array[pCrawl->val].magic_value !=2 && graph->array[pCrawl->val].magic_value % 2==0 && HasFurtherEven(graph,pCrawl->val) > 0){
    result = result+ 1+ EvenTree(graph,pCrawl->val);

  }  
  

  pCrawl = pCrawl->next;

  }

   
 }

return result;
} //End of Function





int main(){
   int V, E;
   cin>>V;
  struct Graph * graph = CreateGraph(V);
 

  cin>>E;

  while(E--){


   int src, dest;
   
    cin>>src>>dest;
    AddEdge(graph,src,dest);
   
   }

    SetMagicValue(graph,1);
    PrintGraph(graph);


  cout<<EvenTree(graph,1)<<endl;

 

	return 0;
}





