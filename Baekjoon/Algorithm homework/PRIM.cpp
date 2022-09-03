#include <iostream>
using namespace std;

#define INF 1000 

int W[101][101];

int V[101]; 
int dist[101]; 


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

 
void prim(int n) 
{ 
    int i, u, v; 
	int sum=0;
    for(int i=1; i<=n; i++) 
        dist[i]=INF; 
     
    dist[1]=0; 
    for(i=1;i<=n;i++) 
    { 
        u = extractMin(n); 
        V[u]=true; 
         
        if( dist[u] == INF ) return; 
        sum+=dist[u];     
 		cout << u <<" ";
 		
        for( v=1; v<=n; v++) 
        { 
            if( W[u][v]!= INF) 
            { 
                if( !V[v] && W[u][v]< dist[v] ) { 
                    cout<<"cc"<<endl;
                    dist[v] = W[u][v]; 
                }
            } 
        } 
    } 
    
    cout<<sum;
} 


int main() 
{ 
	int n, m;
	int x, y, w;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++){
			W[i][j] = INF;
		}
	}
	

	for(int i=0; i<m; i++)
	{
		cin>>x>>y>>w;
		W[x][y] = w ;
		W[y][x] = w;
	}
	
	
    prim(n); 
    
    return 0;
} 
