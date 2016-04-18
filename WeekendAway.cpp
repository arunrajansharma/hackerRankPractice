#include <iostream> 
#include <queue>
#include <cstdio>
#include <climits>
using namespace std;

struct AdjListNode {
	int val;
  int distanceFromSrc;
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

struct AdjListNode * CreateNode(int num,int weight){
	struct AdjListNode * newnode = (AdjListNode *)malloc(sizeof(AdjListNode));
	if(!newnode){
		cout<<"Memory Error 1";
		exit(1);
	}
    newnode->val = num;
    newnode->distanceFromSrc = weight;
    newnode->next = NULL;

    return newnode;

}

void AddEdge(struct Graph* graph, int src, int dest,int weight){
	struct AdjListNode * newnode =  CreateNode(dest,weight);
	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;
  graph->array[src].distance +=  weight;

struct AdjListNode * newnode_2 =  CreateNode(src,weight);
  newnode_2->next = graph->array[dest].head;
  graph->array[dest].head = newnode_2;
  graph->array[dest].distance += weight;


}

struct Graph * CreateGraph(int V){
	struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph ->V = V;

	graph->array = (struct AdjList *)malloc( V * sizeof(AdjList)) ;    // ouiiiiiiii
	graph->array[0].head = NULL;
	graph->array[0].head_value = -1;

	for(int i=1; i<=V;i++){
		graph->array[i].head = NULL;
		graph->array[i].head_value = i;
		graph->array[i].distance = 0;     // initialization
	}


   return graph;

}

int getDistance(struct Graph * graph, int index, int Cities ){
 if(Cities == 0){
  return 0;
 }

 else{

  if(Cities ==2){
    int city_1 = 0;


    int city_2 = 0;

    struct AdjList current ;
    current = graph->array[index];

    struct AdjListNode * pCrawl =  current.head ;
    int first_min = 999;
    int first_index = pCrawl->val;
    while(pCrawl){

      if(pCrawl->distanceFromSrc < first_min  ){
         first_index = pCrawl->val;
         first_min = pCrawl->distanceFromSrc;
      }
     pCrawl = pCrawl->next;
    }

  

   
    pCrawl = current.head ;
    int second_min = 998;
     int second_index = pCrawl->val;

      while(pCrawl){

      if(pCrawl->distanceFromSrc < second_min  && pCrawl->distanceFromSrc >first_min ){
         second_index = pCrawl->val;
         second_min = pCrawl->distanceFromSrc;
      }

      pCrawl = pCrawl->next;
    }

    city_1 = first_min + getDistance(graph,first_index,Cities-1);
    city_2 = second_min + getDistance(graph,second_index,Cities-1);
    
   
    
    
    if(city_1>city_2) return city_2;
    else{
      return city_1;
    }




  }

  if(Cities == 1) {
    struct AdjList current ;
    current = graph->array[index];

   
    struct AdjListNode * pCrawl =  current.head ;

    int min = 999; int list_index = pCrawl->val;
    while(pCrawl){

      if(pCrawl->distanceFromSrc < min && list_index != index){
         list_index = pCrawl->val;
         min = pCrawl->distanceFromSrc;
      }
      pCrawl = pCrawl->next;

    }

    // Now you have index of node with minimum distance from source
    
    return min;

 
 }

  
}

return 0;

} // end of method 

void freeGraph(struct Graph * graph,int V){

  for(int i =0;i<=V;i++){
   cout<<" Hello" ;
   
    struct AdjListNode * pCrawl = graph->array[i].head;

     

    while(pCrawl && pCrawl->next){

      struct AdjListNode * temp = pCrawl;
      pCrawl = pCrawl->next;
      free(temp);
    }
    free(pCrawl);

 
    graph->array[i].head = NULL;



   
  }

  graph->array = NULL;
  free(graph->array);
  graph = NULL;
  free(graph);

}

void HelpFunciton(int N, int M){

  struct Graph * graph = CreateGraph(N);  // creating graph of N vertices
  int src,dest,weight;
  while(M--){
    cin>>src>>dest>>weight;
    AddEdge(graph,src,dest,weight);
  }

   int max = INT_MAX; int index = 1;
 for(int i=1;i<=N;i++){
     if(graph->array[i].distance < max){
       index = i;
       max = graph->array[i].distance ;
     }
  }


  
  // Now I have index of where to start

  cout<<getDistance(graph,index,2)<<endl;
   

  freeGraph(graph,N); 
  
}


int main(){

  int T,N,M;
  cin>>T;
  while(T--){
  cin>>N>>M;
  HelpFunciton(N,M);

  

  }
   

	return 0;
}