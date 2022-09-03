#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int arr[21][21] = {0,};
vector<int> res;


void combi(vector<int> v, vector<int> p, int r, int l, int k){
    //p에 r개만큼 담은경우
    if(r==0){  
        int sum=0;
        for(int i=0; i<p.size()-1; i++){
            for(int j=i+1; j<p.size(); j++){
                sum += arr[p[i]][p[j]] + arr[p[j]][p[i]];
            }
        }
        res.push_back(sum);
    }

    //더이상 뽑지 않고 k의 크기가 n의 크기만큼 됐을 때 
    else if(k==v.size()) {return;}

    
    else{
        p[l] = v[k]; // 뽑는 경우
        combi(v, p, r-1, l+1, k+1);

        //뽑지 않는 경우
        combi(v, p, r, l , k+1);
    }
}

int main(){
    int n, r;
    vector<int> v;
    vector<int> diff;

    cin>>n;
    r = n/2;
    
    vector<int> pick(r);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }

   combi(v, pick, r, 0, 0);

    
    for(int i=0; i<res.size()/2; i++){
        diff.push_back(abs(res[i] - res[res.size()-1-i]));
    }   
    
    
    int min = 101;
 
    for(int i=0; i<diff.size(); i++){
        if(diff[i]<min) min = diff[i];
    }

   
    cout<<min<<endl;
    // 
    return 0;
}