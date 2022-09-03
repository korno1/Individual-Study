#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000] = {0,};

//토마토가 들어있는 칸이 다 익었는지
bool tomato(int n, int m){
    bool check = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0) check = 0;
        }
    }
    return check;
}

//방문 가능한지
bool visitPos(int x, int y, int n, int m){
    if(x<0 || x>n-1) return false;
    if(y<0 || y>m-1) return false;
    if(arr[x][y]==-1 || arr[x][y]==1) return false;

    return true;
}

int minDay(queue<pair<int, int>> q, int n, int m){
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int x = q.front().first; int y = q.front().second;
            q.pop();
            if(visitPos(x-1, y, n, m)){
                q.push(make_pair(x-1, y));
                arr[x-1][y] = 1;
            }
            if(visitPos(x+1, y, n, m)){
                q.push(make_pair(x+1, y));
                arr[x+1][y] = 1;
            }
            if(visitPos(x, y-1, n, m)){
                q.push(make_pair(x, y-1));
                arr[x][y-1] = 1;
            }
            if(visitPos(x, y+1, n, m)){
                q.push(make_pair(x, y+1));
                arr[x][y+1] = 1;
            }
        }
        count++;
    }
    return count;
}

int main(){
    int n, m, mul, res;
    int count = 0, cminus=0, cplus=0;
    queue<pair<int, int>> q;
    cin>>m>>n;
    mul = m * n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==0) count++; // 익지않은 토마토
            else if(arr[i][j]==1) {
                cplus++;// 익은 토마토가  채워진 것
                q.push(make_pair(i, j));
            }
            else cminus++; //토마토가 들어있지 않은 부분
        }
    }

    if(mul-cminus == cplus) cout<<0<<endl;
    
    else {
        res = minDay(q, n, m)-1;
        if(tomato(n,m)) cout<<res<<endl;
        else cout<<"-1"<<endl;

    }

    return 0;
}