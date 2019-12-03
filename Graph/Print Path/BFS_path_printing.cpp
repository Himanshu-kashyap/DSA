#include<bits/stdc++.h>
 using namespace std;

class PathFinding{
	
	int V;
	vector<int> *adj;
	int *parent;
	int *dist;
	
	
	public:
	PathFinding(int V)
	{
		this->V = V;
		adj = new vector<int>[V];
		parent = new int[V];
		dist = new int[V];
	}
	
	void add_edge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool bfs(int src,int dest)
	{
		queue<int> q;
		bool visited[V];
		
		for(int i=0;i<V;i++)
		 {
		 	visited[i] = false;
		 	parent[i] = -1;
		 	dist[i] = INT_MAX;
		 }
		 
		q.push(src);
		dist[src] = 0;
		
		while(!q.empty())
		 {
		 	src = q.front();
		 	q.pop();
		 	
		 	for(vector<int>::iterator i = adj[src].begin();i!=adj[src].end();i++)
		 	 {
		 	 	dist[*i] = dist[src] +1;
		 	 	visited[*i] = true;
		 	 	parent[*i] = src;
		 	 	q.push(*i);
		 	 	
		 	 	if(*i == dest)
		 	 	 return true;
			  }
		 	
		 }
		 
		 return false;
	}
	
	void printDist(int src,int dest)
	 {
	 	if(!bfs(src,dest))
	 	 {
	 		cout<<"No path in between"<<endl;
		 }
		 
		 vector<int> path;
		 int crawl = dest;
		 while(parent[crawl] != -1)
	 	 {
	 	 	path.push_back(parent[crawl]);
	 		crawl = parent[crawl];
	 	 }
		 
		 cout<<"shortest path algo is :"<< dist[dest];
		 cout<<"path is : ";
		 for(int i = path.size()-1; i>=0 ;i--)
			cout<<path[i]<<" ";
		 
	 }
	
	
	
	
	
};


int main()
{
	PathFinding g(8);
	g.add_edge(0, 1); 
    g.add_edge(0, 3); 
    g.add_edge(1, 2); 
    g.add_edge(3, 4); 
    g.add_edge(3, 7); 
    g.add_edge(4, 5); 
    g.add_edge(4, 6); 
    g.add_edge(4, 7); 
    g.add_edge(5, 6); 
    g.add_edge(6, 7);
    
    g.printDist(0,7);
    
    return 0;
	

}

