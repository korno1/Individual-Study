#include <iostream>
#include <vector>
using namespace std;

int dp[1000001] = {0,};

int tile(int n){
    if(n==0 || n==1) return 1;
    
    if(dp[n] > 0) return dp[n];
    
    return dp[n] = (tile(n-1) + tile(n-2))%15746;
}

int main(){
    int n;
    cin>>n;

    cout<<tile(n)<<endl;
    return 0;
}