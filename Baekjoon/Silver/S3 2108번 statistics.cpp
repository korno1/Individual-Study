#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> v;
    int input, sum=0;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>input;
        v.push_back(input);
        sum += input;
    }

    cout<<sum/n<<endl;

    sort(v.begin(), v.end());
    cout<<v[n/2]<<endl;
    
    cout<<v[n-1] - v[0]<<endl;

    return 0;
    
    
}