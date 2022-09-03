#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a, int b){
    return a>b;
}

int visited[100001]={0,};
vector<int> v[100001];
int seq=1;

void dfs(int m, int r){
    visited[r] = seq++;
    for(int i=0; i<v[r].size(); i++){
        if(visited[v[r][i]]==0){
            dfs(m, v[r][i]);
        }
    }
}

int main(){
    int n, m, r;
    //cin>>n>>m>>r;
    scanf("%d %d %d", &n, &m, &r);

    for(int i=0; i<m; i++){
        int x, y;
        //cin>>x>>y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end(), comp);
    }

    dfs(m, r);

    for(int i=1; i<=n; i++)
        printf("%d\n", visited[i]);
        //cout<<visited[i]<<endl;


    return 0;
}