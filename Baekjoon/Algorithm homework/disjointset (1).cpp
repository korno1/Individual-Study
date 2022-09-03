//disjointset
#include <iostream>
using namespace std;

int p[500001];
int r[1000001];
int ssize[500001];
bool fi = false;

void Makeset(int u)
{
	p[u] = u;
	r[u] = 1;
}


int find_set(int u)
{
	if(p[u] != u) p[u] = find_set(p[u]);
	return p[u];
}

void Union(int u, int v)
{
	u = find_set(u);
	v = find_set(v);
	
	if(u==v) {
		fi = true;
		return ;
	}

	if(r[u] > r[v]){
		p[v] = u;
		ssize[u] += ssize[v];
	} 
		
	
	
	else{
		p[u] = v;
		ssize[v] += ssize[u];
		if(r[u]==r[v])
			r[v]++;
 	}
}

//2. connected components
int connectedComponent(int n){
	int arr[n+1] = {0,};
	int count=0;
	for(int i=1; i<=n; i++){
		int q = find_set(i);
		arr[q] = 1;
	}

	for(int i=1; i<=n; i++)
		count += arr[i];

	return count;
}

int main()
{
	
	int n, m;
	int u, v;
	cin>>n>>m;
	int max=0;
	

	for(int i=1; i<=n; i++) 
		Makeset(i);
	
	for(int i=1; i<=n; i++){
		ssize[i] = 1;
	}

	for(int i=0; i<m; i++)
	{
		cin>>u>>v;
		Union(u,v);
	}

	
	//3. greatest connected component
	for(int i=1; i<=n; i++){
		if(ssize[i]>max) max = ssize[i];
	}

	if(fi==true) cout<<"Found"<<endl;
	else cout<<"Not found"<<endl;

	cout<<connectedComponent(n)<<endl<<max<<endl;
	
	return 0;
}
