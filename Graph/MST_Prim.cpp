#include<iostream>
#include<functional>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

typedef pair<long long,int> PII;
const int MAX = 1e5+4;
bool visited[MAX];
vector<PII> adj[MAX];


long long prim(int x)
{
	priority_queue<PII ,vector<PII> ,greater<PII> > Q;
		int y;
		long long minCost = 0;
		PII p;
		Q.push(make_pair(0,x));
		while(!Q.empty())
		{
			p = Q.top();
			Q.pop();
			x = p.second;
			if(visited[x] == True)
				continue;
			
			minCost += p.first;
			visited[x] = true;
			
			for(int i=0;i<adj[x].)
		}
		
}
