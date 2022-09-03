#include <iostream>
using namespace std;

int bio(int n, int k){
    if(k==0 || k==n)
        return 1;
    
    else return bio(n-1, k-1) + bio(n-1, k);
}

int main(){
    int n, k;
    cin>>n>>k;
    
    cout<<bio(n, k)<<endl;

    return 0;
}