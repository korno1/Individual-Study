//MincostPath
#include<iostream>
#include <limits.h>
using namespace std;

int arr[2000][2000]={0,};
int c[2000][2000]={0,};

int mincost(int n){
    for(int i=1; i<=n; i++){
        for(int j=n; j>=1; j--){
            if(i==1 && j==n) c[i][j] = arr[i][j];
            else 
                c[i][j] = arr[i][j] + min(min(c[i-1][j], c[i][j+1]), c[i-1][j+1]);
        }
    }
    return c[n][1];      
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=n+1; j++){
            c[i][j] = INT_MAX;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<mincost(n)<<endl;
    
    return 0;
}
