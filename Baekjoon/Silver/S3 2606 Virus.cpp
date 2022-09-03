#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[101];
int check[101] = {0,};
int count = 0;

void dfs(int k){
    check[k] = 1;
    for(int i=0; i<v[k].size(); i++){
        if(check[v[k][i]]==0){
            count++;
            dfs(v[k][i]);
        }
    }
    
}

int main(){
    int n, m;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);

    cout<<count<<endl;

    return 0;
}