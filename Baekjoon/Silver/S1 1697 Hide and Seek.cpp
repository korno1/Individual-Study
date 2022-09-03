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
    int sec = 1;
    if(n==0) {
        arr[1] = sec;
        q.push(1);
    }
    else{
        q.push(n-1); arr[n-1] = sec;
        if(rangeCheck(n+1, n)){
        q.push(n+1); arr[n+1] = sec;}
        if(rangeCheck(n*2, n)){
        q.push(n*2); arr[n*2] = sec;}
    }

    while(!q.empty()){
        int size = q.size();
        int sq=0;

        for(int i=0; i<size; i++){
            int u = q.front();
            q.pop();
            if(arr[u]==0){
                arr[u] = sec;
            }

            if(rangeCheck(u+1, n)){
                if(arr[u+1]==0 || arr[u+1] > sec+1){
                    arr[u+1] = sec+1;
                    q.push(u+1);
                }
            }

            if(rangeCheck(u-1, n)){
                if(arr[u-1]==0 || arr[u-1] > sec+1){
                    arr[u-1] = sec+1;
                    q.push(u-1);
                }
            }
            
            if(rangeCheck(u*2, n)){
                if(arr[u*2]==0 || arr[u*2] > sec+1){
                    arr[u*2] = sec+1;
                    q.push(u*2);
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

    return 0;
}