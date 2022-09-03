#include <iostream>
using namespace std;

string reverse(string str){
    if(str.length()==1) return str;
    
    return reverse(str.substr(1)) + str[0];
}

int main(){
    string s = "ABCD";
    cout<<reverse(s)<<endl;
    return 0;
}
