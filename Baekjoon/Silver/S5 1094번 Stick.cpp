#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int input;
    int sum=0;
    cin>>input;

    v.push_back(64);

    while(1){
        sum = 0;
        if(v[v.size()-1]/2 > input){
            v[v.size()-1]/=2;
        }
        else{
            v[v.size()-1]/=2;
            v.push_back(v[v.size()-1]);
        }

        for(int i=0; i<v.size()-1; i++){
            sum += v[i];
        }
        cout<<sum<<endl;
        if(sum==input) {
            cout<<v.size()-2<<endl;
            break;
        }
    }

    return 0;
}