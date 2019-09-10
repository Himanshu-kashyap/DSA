#include<bits/stdc++.h>
 using namespace std;


const int MAX = 1e5+5;
int id[MAX];
int nodes,edges;

void initialization()
{
	for(int i =0;i<MAX;i++)
	id[i] = i;
}

//find root

int root(int src)
{
	if (src != id[src])
	 {
	 	id[src] = id[id[src]];
	 	src = id[src];
	 }
	 return src;
}

void union1(int p,int q)
{
	int x = id[p];
	int y = id[q];
	id[x] = id[y];
}

void kruskal(pair< long long,pair<int,int> > in[])
{
	
}

int main()
{
   

}

