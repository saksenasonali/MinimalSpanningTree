//Dijkstra's Algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=14;
	map<int,int> dist;
	vector<pair <int,int> > g[n];
	int u, v, w, tmp;
	for(int i =0; i<n; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,0));
	map<int,int> vis;
	while(q.size() > 0)
	{
		int tmp=q.top().second;
		int weight=q.top().first;
		q.pop();
		if(vis[tmp] == 1)
			continue;	
		vis[tmp]=1;
		dist[tmp]=weight;		
		
		for(int i =0; i<g[tmp].size();i++)
		{
			if(!vis[g[tmp][i].first])
			{
				q.push(make_pair(g[tmp][i].second,g[tmp][i].first));
			}
		}		
	}
	map <int,int> :: iterator it;
	for(it=dist.begin(); it!=dist.end(); it++)
	{
		cout << it->first << " " << it->second << endl ;
	}	

}