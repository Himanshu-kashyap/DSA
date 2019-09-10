#include<bits/stdc++.h>
 using namespace std;
class DFS{
	
	vector<int> *nodes;
	int V;
	
	public:
	DFS(int V)
	{
		this->V = V;
		nodes = new vector<int>[V];
		
	}
	
	void addEdge(int u,int v)
	{
		nodes[u].push_back(v);
	}
	
	void dfs_traversal(int starting)
	{
		bool visited[V];
		for(int i=0;i<V;i++) visited[i]=false;
		
		//initialize a stack
		stack<int> st;
		
		visited[starting] = true;
		st.push(starting);
		
		vector<int> ::iterator itr;
		
		while(!st.empty())
		{
			starting = st.top();
			cout<<starting<<"\t";
			
			st.pop();
			
			for(itr = nodes[starting].begin();itr!=nodes[starting].end();itr++)
			{
				if(!visited[*itr])
				{
					visited[*itr] = true;
					st.push(*itr);
				}
				
			}
		}
	
}
};


int main()
{
  DFS graph(8);

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
    
     cout << "Depth First Traversal is : ";
    graph.dfs_traversal(0);

return 0;

}

