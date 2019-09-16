#include<bits/stdc++.h>
 using namespace std;

class BFS
{
	int V;
	vector<int> *nodes;
	vector<int> ::iterator itr;
	
	public:
	
	
	// constructor 
	BFS(int V)
	{
		this->V = V; 
		nodes = new vector<int> [V];
	}
	
	
	void addEdge(int u,int v)
	 {
	 	nodes[u].push_back(v);
	 }
	
	void bfs_traversal(int start)
	 {
	 	bool visited[V];
	 	
	 	for (int i =0;i<V;i++) visited[i] = false;
	 	
	 	queue<int> q;
	 	q.push(start);
	 	visited[start] = true;
	 	
	 	while(!q.empty())
	 	{
	 		start = q.front(); // front returns front element
	 		cout<<start<<"\t";
	 		q.pop();  // pop deletes the element
	 		
	 		for (itr = nodes[start].begin();itr!=nodes[start].end();itr++)
	 		{
	 			if( !visited[*itr])
	 			 {
	 			 	visited[*itr] = true;
	 			 	q.push(*itr);
				  }
			 }
		 }
	 	
	 }
	
};


int main()
{
	BFS graph(8);
	// Create edges between vertices
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    graph.addEdge(3, 6);
    graph.addEdge(4, 0);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.addEdge(6, 2);
    graph.addEdge(7, 3);
    
     cout << "Breadth First Traversal is : ";
    graph.bfs_traversal(0);
	
	
return 0;

}

