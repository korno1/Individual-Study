#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v[25][25];
vector<int> res;

bool locPos(int x, int y, int n){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=n) return false;
    if(v[x][y]!=1) return false;
    return true; 
}

void bfs(int i, int j, int n, int count){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    v[i][j] = count;
    int sum = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(locPos(x-1, y, n)){
            v[x-1][y] = count;
            q.push(make_pair(x-1, y));
            sum++;
        }
        if(locPos(x+1, y, n)){
            v[x+1][y] = count;
            q.push(make_pair(x+1, y));
            sum++;
        } 
        if(locPos(x, y-1, n)){
            v[x][y-1] = count;
            q.push(make_pair(x, y-1));
            sum++;
        } 
        if(locPos(x, y+1, n)){
            v[x][y+1] = count;
            q.push(make_pair(x, y+1));
            sum++;

        } 
    }
    res.push_back(sum);
}

int searchOne(int n){
    int count = 2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]==1){
                //cout<<i<<" "<<j<<" "<<count<<endl;
                bfs(i, j, n, count);
                count++;
            }
        }
    }
    return count-2;
}

int main(){
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            scanf("%1d", &v[i][j]);
    }
    
    cout<<searchOne(n)<<endl;
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}