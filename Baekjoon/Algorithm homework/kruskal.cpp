#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000

int p[101];
int W[101][101];

class Edge
{
	public :
		int node[2];
		int dist;
		
		Edge(int a, int b, int dist)
		{
			this -> node[0] = a;
			this -> node[1] = b;
			this -> dist = dist;
		}
		
		bool operator < (const Edge &edge) const {
			return (this -> dist) < (edge.dist);
		}
};

vector <Edge> v;

int Findset(int x)
{
	if(p[x] == x) return x;
	return p[x] = Findset(p[x]);
}

void Union(int x, int y)
{
	x = Findset(x);
	y = Findset(y);
	
	if(x!=y) p[y] = x;

}



int kruskal(int n, int s)
{
	sort(v.begin(), v.end());
	
	for(int i=1; i<=n; i++)
		p[i] = i;
		
	int sum =0;
	int iw = 0;
	for(int i=0; i<v.size(); i++)
	{
		if(Findset(v[i].node[0]) != Findset(v[i].node[1]))
		{
			if(i==s)
				iw = v[i].dist;
			//cout<<v[i].dist<<" ";
			sum += v[i].dist;
			Union(v[i].node[0], v[i].node[1]);
		}
	}
	
	cout << sum << endl << iw;
	
}

int main() 
{ 
	int n, m, i;
	int x, y, w;
	cin>>n>>m;
	cin>>i;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++){
			W[i][j] = INF;
		}
	}
	

	for(int i=0; i<m; i++)
	{
		cin>>x>>y>>w;
		v.push_back(Edge(x,y,w));
	}
	
	
    kruskal(n, i); 
    
    return 0;
} 
