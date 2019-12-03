#include<bits/stdc++.h>
 using namespace std;


void printPath(vector<int> path)
{
	int sz = path.size();
	for(int i=0;i<size;i++)
		cout<<path[i]<<" ";
		cout<<endl;
}

int isNotVisited(int x,vector<int> path)
{
	int sz = path.size();
	for(int i=0;i<size;i++)
		if(path[i] == x)
			return 0;
		return 1;	
}

void findPaths(vector<<vector<int> > g,int src,int dest,int v)
{
	queue<vector<int> > q;
	vector<int> path;
	
	path.push_back(src);
	q.push(path);
	
	while(!q.empty())
	 {
	 	path = q.front();
	 	q.pop();
	 	
	 	int last = path[path.size()-1];
	 	
	 	if(last == dest)
	 	 printpath(path);
	 	 
	 	for(int i =0;i<g.size();i++) 
	 	{
	 		if(isNotVisited)
		 }
	 }
}

int main()
{


}

