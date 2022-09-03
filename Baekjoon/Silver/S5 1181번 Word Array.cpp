#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> s;
    string in;
    int n;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>in;
        s.push_back(in);
    }

    sort(s.begin(), s.end());
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<s[i]<<endl;
    }

    return 0;
}