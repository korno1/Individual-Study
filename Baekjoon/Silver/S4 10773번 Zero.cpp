#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int n;
    int in;
    int sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>in;
        if(in==0) s.pop();
        else{
            s.push(in);
        }
    }
    
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout<<sum<<endl;

    return 0;
}