#include <iostream>
#include <vector>
using namespace std;

long long exam(vector<long long> a, long long n, long long b, long long c){
    long long sum = n;

    for(int i=0; i<n; i++){
        a[i] -= b;
        if(a[i]<0) a[i]=0;

        if(a[i]!=0 && a[i]<=c) sum++;
        
        else{
            if(a[i]%c==0) sum += a[i]/c;
            else sum += a[i]/c+1;
        }
    }
    return sum;
}

int main(){
    long long  n;
    vector<long long> a;
    long long  b, c;

    cin>>n;
    for(int i=0; i<n; i++){
        long long input;
        cin>>input;
        a.push_back(input);
    }
    cin>>b>>c;
    
    cout<<exam(a, n, b, c)<<endl;

    return 0;
}