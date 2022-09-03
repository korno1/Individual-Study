#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main(){
    vector<pair<int, int>> v;
    int n, x, y;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    return 0;
}