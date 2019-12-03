#include<bits/stdc++.h>
using namespace std;

class BFS{
int V;
vector<int> *adj;
int count;
public:

BFS(int V)
{
    this->V = V;
    adj = new vector<int> [V];
    count =0;
}

void addEdge(int u,int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfstraversal(int source)
{
    bool visited[V];
    for(int i = 1; i<=V ;i++)visited[i] = false;
    
	queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while(!q.empty())
    {
        source = q.front();
        cout<<source<<endl;
        count+=1;
        q.pop();
        
        for(vector<int> ::iterator itr = adj[source].begin();itr != adj[source].end();itr++)
        {
            if(!visited[*itr])
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
        cout <<count<<endl;
        
    }
}
    
};
 
 int main()
 {
 	BFS graph(5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(2, 4);
    
    graph.bfstraversal(1);
         
     
     
     
     return 0;
     
 }
