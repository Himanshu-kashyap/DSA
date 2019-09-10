#include<bits/stdc++.h>
 using namespace std;
 
 
struct node{
	int to,weight;
};

vector<node> edges[2000];


void addEdge(int u,int v,int wt)
 {
 	edges[u].push_back({v,wt});
 	edges[v].push_back({u,wt});
 }
 
 void zeroOneBFS(int src)
 {
 	int dist[10000];
 	for (int i=0;i<10000;i++)
 	 dist[i] = INT_MAX;
 	
	deque<int> Q;
	dist[src] =0;
	Q.push_back(src);
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop_front();
		for(int i=0;i<edges[u].size();i++)
		 {
		 	if(dist[edges[u][i].to] > dist[ u ] + edges[u][i].weight)
		 	 {
		 	 	dist[edges[u][i].to] = dist[ u ] + edges[u][i].weight;
		 	 	
		 	 	if(edges[u][i].weight == 0)
		 	 	 Q.push_front(edges[u][i].to);
		 	 	else
				  Q.push_back(edges[u][i].to);
		 	 	
		 	 	
			  }
		 }
		
	}
	
	int itr= 0;
	while(dist[itr]!= INT_MAX)
		{
			cout<<dist[itr]<<endl;
			itr++;
		}
 }

int main()
{
	
 	addEdge(0, 1, 0); 
    addEdge(0, 7, 1); 
    addEdge(1, 7, 1); 
    addEdge(1, 2, 1); 
    addEdge(2, 3, 0); 
    addEdge(2, 5, 0); 
    addEdge(2, 8, 1); 
    addEdge(3, 4, 1); 
    addEdge(3, 5, 1); 
    addEdge(4, 5, 1); 
    addEdge(5, 6, 1); 
    addEdge(6, 7, 1); 
    addEdge(7, 8, 1); 
		
		int src = 0;
		zeroOneBFS(0);
		return 0;
}

