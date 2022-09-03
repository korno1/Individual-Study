#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(1){
        int r = a%b;
        if(r==0) return b;

        a=b;
        b=r;
    }
}

int main(){
    int n;
    int f;
    int arr[100]={0,};
    cin>>n>>f;
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
        int g = gcd(f, arr[i]);
        cout<<f/g<<"/"<<arr[i]/g<<endl;
    }

    return 0;
}