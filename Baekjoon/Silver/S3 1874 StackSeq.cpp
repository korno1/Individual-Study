#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n, in, j=1;
    stack<int> s;
    vector<char> v;
    
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>in;

        if(j<=in){
            while(j<in){
                s.push(j++);
                v.push_back('+');
            }
            if(j==in){
                j++;
                v.push_back('+');
                v.push_back('-');
            }
            
        }

        else{
            if(s.top()==in){
                s.pop();
                v.push_back('-');
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    for(int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";

    return 0;
}