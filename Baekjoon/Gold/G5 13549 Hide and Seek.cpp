#include <iostream>
#include <queue>
using namespace std;

int arr[100001] = {0,};
bool visited[100001] = {0,};

bool rangeCheck(int x, int n){
    if(x<0) return false;
    if(x>100000) return false;
    if(x==n) return false;
    return true;
}

void bfs(queue<int> q, int n){
    int sec = 0;
    visited[n] = 1;
    q.push(n);

    //if(rangeCheck(n-1, n)) arr[n-1] = sec+1;

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int u = q.front();
            q.pop();
            if(rangeCheck(u*2, n)){
                if(visited[u*2]==1){//이미 방문했는데 들어갈 수 있는 값이 더 작다면
                    if(arr[u*2] > arr[u]){
                        arr[u*2] = arr[u];
                        q.push(u*2);
                    }
                }
                else{ // 방문을 한적이 없을때
                    arr[u*2] = arr[u];
                    visited[u*2] = true;
                    q.push(u*2);
                }
            }

            if(rangeCheck(u+1, n)){
                if(visited[u+1]==1){
                    if(arr[u+1] > arr[u]+1){
                        arr[u+1] = arr[u]+1;
                        q.push(u+1);
                    }
                }
                else{
                    arr[u+1] = arr[u]+1;
                    visited[u+1] = true;
                    q.push(u+1);
                }
            }

            if(rangeCheck(u-1, n)){
                if(visited[u-1]==1){
                    if(arr[u-1] > arr[u]+1){
                        arr[u-1] = arr[u]+1;
                        q.push(u-1);
                    }
                }
                else{
                    arr[u-1] = arr[u]+1;
                    visited[u-1] = true;
                    q.push(u-1);
                }
            }
        }
        sec++;
    }
}

int main(){
    int n, k;
    queue<int> q;
    cin>>n>>k;

    arr[n] = 0;
    

    bfs(q, n);

    cout<<arr[k]<<endl;
/*
    for(int i=1; i<20; i++)
        cout<<"i="<<i<<" "<<arr[i]<<endl;
        */
    return 0;
}