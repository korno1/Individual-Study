#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[100001];
int visited[100001] = {0,};
int res = 1;

bool comp(int a, int b){
    return a>b;
}

void bfs(queue<int> q, int r){
    visited[r] = res++;
    q.push(r);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<v[u].size(); i++){
            int x = v[u][i];
            if(visited[x]==0){
                visited[x] = res++;
                q.push(x);
            }
        }
    }
}

int main(){
    int n, m, r;
    queue<int> q;
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

    bfs(q, r);

    for(int i=1; i<=n; i++){
        //cout<<visited[i]<<endl;
        printf("%d\n", visited[i]);
    }

    return 0;
}