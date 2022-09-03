#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char v[100][100];
int dist[100][100] ={0,};

bool locatePos(int x, int y, int n, int m){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=m) return false;
    if(v[x][y] == '0') return false;
    return true;
}

int bfs(queue<pair<int, int>> q, int n, int m){
    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    v[0][0] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x==n-1 && y==m-1) {
            return dist[x][y];
        }
        q.pop();
        if(locatePos(x-1, y, n, m)) {
            v[x-1][y] = '0';
            q.push(make_pair(x-1, y));
            dist[x-1][y] = dist[x][y] + 1;
        }
        if(locatePos(x+1, y, n, m)) {
            v[x+1][y] = '0';
            q.push(make_pair(x+1, y));
            dist[x+1][y] = dist[x][y] + 1;
        }
        if(locatePos(x, y-1, n, m)) {
            v[x][y-1] = '0';
            q.push(make_pair(x, y-1));
            dist[x][y-1] = dist[x][y] + 1;
        }
        if(locatePos(x, y+1, n, m)) {
            v[x][y+1] = '0';
            q.push(make_pair(x, y+1));
            dist[x][y+1] = dist[x][y] + 1;
        }
    }
}

int main(){
    int n, m;
    queue<pair<int, int>> q;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    
    int res = bfs(q, n, m);
    cout<<res<<endl;
    return 0;
}