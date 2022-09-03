#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v(100000);

bool cycleDeteted(int n, int degree[]){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i]==0) q.push(i);
    }

    for(int i=1; i<=n; i++){
        if(q.empty()) return true;
        int u = q.front();
        q.pop();
        for(int i=0; i<v[u].size(); i++){
            int p = v[u][i];
            degree[p]--;
            if(degree[p]==0)
                q.push(p);
        }
    }

    return false;

}

int main(){
    int n, m;
    int x, y;
    bool cycle = false;
    cin>>n>>m;
    int degree[n+1] = {0,};
    
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v[x].push_back(y);
        degree[y]++;
    }

    cycle = cycleDeteted(n, degree);

    if(cycle==true) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}