#include <iostream>
using namespace std;

#define INF 1000

int W[101][101];
int V[101];
int dist[101];
int pr[101];

int extractMin(int n) 
{ 
    int v; 

    for (int i = 1; i <= n; i++) 
    { 
        if (!V[i]) 
        {  
            v = i;  
            break; 
        } 
    } 
 
    for (int i = 1; i <= n; i++) 
    { 
        if( !V[i] && (dist[i] < dist[v]))  
            v = i; 
    } 

    return v; 
} 

void dijkstra(int n, int r, int t)
{
	int u;
	
	for(int i=1; i<=n; i++){
		dist[i] = INF;
	}
	dist[r] = 0;
	V[1] = 0;
	
	for(int i=1; i<=n-2; i++)
	{
		u = extractMin(n);
		V[u] = true;
		
		for(int v=1; v<=n; v++)
		{
			if(!V[v])
			{
				if(dist[u] + W[u][v] < dist[v]) 
				{
					dist[v] = dist[u] + W[u][v]; 
					pr[v] = u;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		cout<<pr[i]<<" ";
	}
	
	if (dist[t] == INF) cout << "Impossible";
	
	else cout<<dist[t];
}

int main()
{
	int n, m, r, t;
	int x, y, w;
	cin>>n>>m;
	
	
		
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i==j) W[i][j] = 0;
			else W[i][j] = INF;
		}
		
	for(int i=0; i<m; i++)
	{
		cin>>x>>y>>w;
		W[x][y] = w;
	}
	
	cin>>r>>t;
	
	dijkstra(n, r, t);
	
	return 0;
}
