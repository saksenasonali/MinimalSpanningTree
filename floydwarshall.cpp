// floydd warshal algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, e;
	cin >> n >> e;
  	int dist[n][n], i, j, k;
	vector<pair <int,int> > graph[n];
	int u, v, w, tmp;
	for(int i =0; i<e; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
  	for (i = 0; i < n; i++)
        	for (j = 0; j < n; j++)
        	    dist[i][j] = graph[i][j].second;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
