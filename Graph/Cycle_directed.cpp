#include<bits/stdc++.h>
 using namespace std;

class DirectedCycle{
	int V;
	vector <int> *adj;
	
	public:
	DirectedCycle(int V)
	{
	   this->V = V;
	   adj = new vector<int>[V];
	}
	
	void addEdge(int u,int v)
	 {
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	 	
	 }
	 
	 bool isCyclicUtil(int v,bool visited[],int parent)
	 {
	 	visited[v]  = true;
	 	vector<int> :: iterator i;
	 	for (i = adj[v].begin();i!= adj[v].end();i++)
	 	{
	 		if(!visited[*i])
	 			{
				 if(isCyclicUtil(*i,visited,v))
	 				return true;
	 			}
	 		
			else if(*i != parent) 		
				return true;
		 }
		
		return false; 
	 }
	 
	 bool isCyclic(){
	 	bool *visited = new bool[V];
	 	for (int i=0;i<V;i++)
			visited[i] = false;
			
		for(int u =0;u<V;u++)	
			if(!visited[u])
				if(isCyclicUtil(u,visited,-1))
					return true;
		
		return false;			
			
			
	 }
	 
	 
};

int main()
{
DirectedCycle g1(5);
g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    DirectedCycle g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    return 0; 

}

