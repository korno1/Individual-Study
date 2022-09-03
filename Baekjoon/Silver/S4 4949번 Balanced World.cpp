#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    while(1){
        string a;
        bool k=true;
        stack<char> s;
        getline(cin, a);

        if(a==".") break;
        
        for(int i=0; i<a.length(); i++){
            if(a[i]=='[' || a[i]=='(')
                s.push(a[i]);
            else{
                if(a[i]==']'){
                    if(!s.empty() && s.top()=='[') s.pop();
                    else {
                        k=false;
                        break;
                    }
                }
                else if(a[i]==')'){
                    if(!s.empty() && s.top()=='(') s.pop();
                    else{
                        k=false;
                        break;
                    }
                }
            } 
        }
        if(!s.empty()) k=false;
        if(k==true) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }

    return 0;
}