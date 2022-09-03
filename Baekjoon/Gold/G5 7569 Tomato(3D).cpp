#include <iostream>
#include <queue>
using namespace std;

int arr[100][100][100] = {0,};

//토마토가 전부 익을수 있는지 가능성에 대한 판단
bool tomato(int n, int m, int h){
    bool check = 1;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j][k]==0) check = 0;
            }
        }
    }
    return check;
}

//방문할 수 있는지?
bool visitPos(int x, int y, int z, int n, int m, int h){
    if(x<0 || x>n-1) return false;
    if(y<0 || y>m-1) return false;
    if(z<0 || z>h-1) return false;
    if(arr[x][y][z]==-1 || arr[x][y][z]==1) return false;

    return true;
}

int minDay(queue<pair<pair<int, int>, int>> q, int n, int m, int h){
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second;
            q.pop();
            if(visitPos(x-1, y, z, n, m, h)){
                q.push(make_pair(make_pair(x-1, y), z));
                arr[x-1][y][z] = 1;
            }
            if(visitPos(x+1, y,z , n, m, h)){
                q.push(make_pair(make_pair(x+1, y), z));
                arr[x+1][y][z] = 1;
            }
            if(visitPos(x, y-1, z, n, m, h)){
                q.push(make_pair(make_pair(x, y-1), z));
                arr[x][y-1][z] = 1;
            }
            if(visitPos(x, y+1, z, n, m, h)){
                q.push(make_pair(make_pair(x, y+1), z));
                arr[x][y+1][z] = 1;
            }
            if(visitPos(x, y, z-1, n, m, h)){
                q.push(make_pair(make_pair(x, y), z-1));
                arr[x][y][z-1] = 1;
            }
            if(visitPos(x, y, z+1, n, m, h)){
                q.push(make_pair(make_pair(x, y), z+1));
                arr[x][y][z+1] = 1;
            }
        }
        count++;
    }
    return count;
}

int main(){
    int n, m, h, mul, res;
    int count = 0, cminus=0, cplus=0;
    queue<pair<pair<int, int>, int>> q;
    cin>>m>>n>>h;
    mul = m * n * h;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j][k];
                if(arr[i][j][k]==0) count++; //익지않은 토마토의 개수
                else if(arr[i][j][k]==1) {
                    cplus++;//익은 토마토의 개수
                    q.push(make_pair(make_pair(i, j), k));
                }
                else cminus++; // 토마토가 들어있지 않은 개수
            }
        }
    }
 

    if(mul-cminus == cplus) cout<<0<<endl;

    else {
        res = minDay(q, n, m, h)-1;
        if(tomato(n, m, h)) cout<<res<<endl;
        else cout<<"-1"<<endl;

    }

    return 0;
}