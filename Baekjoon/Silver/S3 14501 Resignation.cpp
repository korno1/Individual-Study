#include <iostream>
using namespace std;

int t[16] = {0,};
int p[16] = {0,};
int max_res=0;

void dp(int n){
    for(int i=n-1; i>=0; i--){
        if(t[i] + i > n) { //현재일 + 해야할 일 > 최대 날
            p[i] = p[i+1];
        }

        else{
            //현재 t의 pay와 t시간이 흐르고 난 후 pay
            if(p[i]+p[i+t[i]] > p[i+1]) p[i] += p[i+t[i]];
            else p[i] = p[i+1];
        }

        if(p[i]>max_res) max_res = p[i];
    }
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>t[i]>>p[i];
    }

    dp(n);
    
    cout<<max_res;

    return 0;
}