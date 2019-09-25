// using bellman ford 
// if dist[v] > dist[u] + wt(u,v) update dist[v]

#include<bits/stdc++.h>
 using namespace std;

struct Edge{
	int src,dest,weight;
};

struct Graph{
	int V,E;
	struct Edge *edge;
};


struct Graph *createGraph(int V,int E){
	
	struct Graph *graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[V];
		
}


bool isNegCycle(struct Graph *graph,int src)
 {
 	int V = graph->V;
 	int E = graph->E;
 	int dist[V];
 	
 	for(int i=0;i<V;i++)
 		dist[i] = INT_MAX;
 	
	dist[src] = 0;
	
	for (int i=0;i<V;i++)   // traverse V-1 vertices
	{
		for (int j=0;j<E;j++)	
		{
			int u = graph->edge[i].src;
			int v = graph->edge[i].dest;
			int weight = graph->edge[i].weight;
			
			if(dist[u]!= INT_MAX and dist[v] > dist[u] + weight)
				dist[v] = dist[u] + weight;
		}
	}
	
	for(int i=0;i<E;i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		
		if(dist[u] != INT_MAX and dist[v]> dist[u]+weight)
			return true;
	}
 	return false;
 	
 }
 
 


int main()
{
	
	
int V = 5; // Number of vertices in graph 
    int E = 8; // Number of edges in graph 
    struct Graph* graph = createGraph(V, E);
  
    // add edge 0-1 (or A-B in above figure) 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    if (isNegCycle(graph, 0)) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
    return 0; 

}


