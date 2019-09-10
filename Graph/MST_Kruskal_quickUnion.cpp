//complexity of this algo is O(ElogV)

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

//declare id for each node
const int MAX = 1e4+5;
int id[MAX],nodes,edges;
pair<long long, pair<int,int> > p[MAX];
 
 
 // this is the part of quick union
 
 
 // init ids for everynode
void init()
{
	for(int i = 0;i<MAX;i++)
	 id[i] = i;
}


// implementing quick union where we join root to other root
int root(int n)
{
	while(id[n]!=n){
		id[n] = id[id[n]];
		n = id[n];
	}
return n;
}

void union1(int p,int q)
{
	int x = root(p);
	int y = root(q);
	id[x] = id[y];
}

// ------------------------ quick union ends here

long long kruskal(pair<long long,pair<int,int> > p[]) 
{
	int x,y;
	long long cost,minimumCost = 0;
	
	
	for(int i =0;i<edges;i++)
	  {
	  	x = p[i].second.first;
	  	y = p[i].second.second;
	  	
	  	cost = p[i].first;
	  	
	  	//check whether it makes a cycle or not 
	  	if(root(x) != root(y))
	  	 {
	  	 	minimumCost += cost;
	  	 	union1(x,y);
		   }
	  }
	  return minimumCost;
}
 
int main()
{
	int x,y;
	long long weight,cost,minimumCost;
	init();
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	 {
	 	cin>>x>>y>>weight;
	 	p[i] = make_pair(weight,make_pair(x,y));
	 }
	 
	 // sort the edges in ascending order
	 sort(p,p+edges);
	 minimumCost = kruskal(p);
	 cout<<minimumCost<<endl;
	 return 0;

}

