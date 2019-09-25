// Negative Cycle detection using floyd warshall algorithm


#include<bits/stdc++.h>
 using namespace std;


# define V 4
# define INF 999999



bool negCycle(int graph[][V])
{
	int dist[V][V],i,j,k;
	
	for(int i=0;i<V;i++)
	for(int j=0;j<V;j++)
		dist[i][j] = graph[i][j];
		
		
	for(int k =0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	for(int i =0;i<V;i++)	
	 {
	 	if(dist[i][i] < 0)
	 	return true;
	 	
	 	return false;
	 }
}



int main()
{
int graph[V][V] = { {0   , 1   , INF , INF}, 
                        {INF , 0   , -1  , INF}, 
                        {INF , INF , 0   ,  -1}, 
                        {-1  , INF , INF ,   0}}; 
      
    if (negCycle(graph)) 
       cout << "Yes"; 
    else
       cout << "No";  
    return 0; 

}

