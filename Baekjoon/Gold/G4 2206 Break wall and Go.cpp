#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<char> v[1000];
int dist[1000][1000]={0,};

bool locPos(int x, int y, int n, int m){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=m) return false;
    if(v[x][y]==1) return false;
    return true;
}

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char input;
            cin>>input;
            v[i].push_back(input);
        }
    }

    

    return 0;
}