#include<bits/stdc++.h>
 using namespace std;

int main()
{
 vector<int> vi[2000+10];  // vector of edges
 int dist[1000+10];
 
 int m,n;
 cin>>m>>n;
 
 
 for(int i =0;i<m+2;i++)   // m == edges
  	dist[i] = INT_MAX;
  dist[0] = 0;
  
  for(int i=0;i<m;i++)   // intake edges index 0 will be src 1:dest and 2:weight
  {
  	int wt,src,dest;
   	cin>>src>>dest>>wt;
   	vi[i].push_back(src);
   	vi[i].push_back(dest);
   	vi[i].push_back(wt);
  }
  
  for(int i=0;i<n-1;i++)  // n == vertices
  {
  	int j=0;
  	while(vi[j].size() != 0)
  	 {
  	 	if(dist[ vi[j][0] ] + vi[j][2] < dist[vi[j][1]])    // if dist[dest] > dist[src] + weight
  	 	{
  	 		 dist[vi[j][1]] = dist[ vi[j][0] ] + vi[j][2];
		   }
		   j++;
	   }
	}
	
	
	for(int i=0;i<n;i++)  
	{
		int src = vi[i][0];
		int dest = vi[i][1];
		int wt = vi[i][2];
		
		cout<<dist[src]<<"\t"<<dist[dest]<<"\t"<<wt<<"\n";
		
		if(dist[dest] > dist[src] + wt)
		{
			printf("Cycle Detected\n");
		}
	}
		
	
	printf("updated weights from src ie 0\n");
	for(int i=0;i<n;i++)     // for all vertices
	{
		cout<<i<<"\t"<<dist[i]<<endl;
	}	   
  }
  



