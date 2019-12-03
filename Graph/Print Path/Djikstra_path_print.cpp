/*
* since we extract min dist among all adj vertices they are implemented using adj we use min priority queue
* 1. all except source's dist = inf ; dist[src] = 0
* 2. add source to priority queue
* 3. while pq is not empty pop adj elements and update wts

*/

#include<bits/stdc++.h>
 using namespace std;


#define SIZE 100000
typedef pair<int,int> iPAIR;

class Dijkstra{

int V;  // number of vertices
vector<pair <int,int> > *adj;  // insert as distance and vertex 

public:
	Dijkstra(int V)
	{
		this->V = V;
		adj  = new vector<iPAIR>[V];
	}
	
	void addEdge(int u,int v,int wt)
	 {
		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(u,wt));
	 }

/*
********************************************************************************************
*/	

void printPath(int parent[],int j)
{
	if(parent[j] == -1)
		return;
	
	printPath(parent,parent[j]);
	cout<<j<<" ";
}

void printSolution(vector<int> distance,int parent[],int V)
{
	int src = 0;
	for(int i=0;i<V;i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, distance[i], src);
		printPath(parent,i);
		
	}
}

/*
********************************************************************************************
*/	


void dijkstra(int source)
	{
		int parent[V];
		parent[source] = -1;
	
	priority_queue<iPAIR,vector<iPAIR>, greater<iPAIR> > pq;   //min priority queue
	
	vector<int> dist(V,INT_MAX);   // init dist with INF
	
	dist[source] = 0;  // source dist = 0
	
	pq.push(make_pair(0,source));
	

	
	while(!pq.empty())
	{
		int u = pq.top().second;  // top of priority q = int int === dist and node
		pq.pop();
		
		vector<pair <int,int> > ::iterator itr;
		
		
		for(itr=adj[u].begin();itr != adj[u].end();itr++)  // from pair beginning to end
		{
			int v  = (*itr).first;    // first in pair i.e node
			int w  = (*itr).second;   // second in pair i.e weight
			
			if(dist[u]+w < dist[v])
				{
					parent[v] = u;
 					dist[v] = dist[u]+ w;
					pq.push(make_pair(dist[v],v));     
				}
				
					
		}
	}

printf("Vertex   Distance from Source\n"); 

        
    printSolution(dist,parent,V);
}




};
int main()
{

Dijkstra g(9);
g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.dijkstra(0); 
    
    
    
    return 0;


}

