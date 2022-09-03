#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

#define Max_i INT_MAX

int make_one(int *dp, int n){
    for(int i=4; i<=n; i++){
        /*
        int min = Max_i;
        if(i%3==0) {
            if(dp[i/3]+1 < min) min = dp[i/3]+1; 
        }
        if(i%2==0){
            if(dp[i/2]+1 < min) min = dp[i/2]+1; 
        }

        if(dp[i-1] + 1 < min) min = dp[i-1]+1;
        

        dp[i] = min;
        */
       if(i%3==0) {
            dp[i] = min(dp[i/3]+1, dp[i-1]+1);
       }
       if(i%2==0) {
            dp[i] = min(dp[i/2]+1, dp[i-1]+1);

       }
       dp[i] = dp[i-1]+1;
    }

    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[n+1] = {0,};
    
    dp[2] = 1;
    dp[3] = 1;

    cout<<make_one(dp, n)<<endl;


    return 0;
}