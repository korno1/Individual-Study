#include <iostream>
#include <vector>

using namespace std;

long long arr[100000][3]={0,};
vector<string> res;

inline bool CheckSL(long long i){
    vector<long long> v[2];
    long long x, y, z;
    for(long long j=0; j<2; j++){
        v[j].push_back(arr[i+j+1][0] - arr[i+j][0]);
        v[j].push_back(arr[i+j+1][1] - arr[i+j][1]);
        v[j].push_back(arr[i+j+1][2] - arr[i+j][2]);
    }

    x = (v[0][1] * v[1][2]) - (v[0][2] * v[1][1]);
    y = -((v[0][0] * v[1][2]) - (v[0][2] * v[1][0]));
    z = (v[0][0] * v[1][1]) - (v[0][1] * v[1][0]);
    if(x==0 && y==0 && z==0){
        return false;
    }

    return true;
}

inline void spider(long long n){
    long long seq=0, x, y, z;
    vector<long long> v[2];
    long long count = 0;

    if(n<=3){
        res.push_back("TAK");
        return ;
    }

    for(long long i=0; i<n-2; i++){
        if(CheckSL(i)){
            seq = i;
            break;
        }
    }

    for(long long i=0; i<2; i++){
        v[i].push_back(arr[seq+i+1][0] - arr[seq][0]);
        v[i].push_back(arr[seq+i+1][1] - arr[seq][1]);
        v[i].push_back(arr[seq+i+1][2] - arr[seq][2]);
    }
 

    x = (v[0][1] * v[1][2]) - (v[0][2] * v[1][1]);
    y = -((v[0][0] * v[1][2]) - (v[0][2] * v[1][0]));
    z = (v[0][0] * v[1][1]) - (v[0][1] * v[1][0]);
    

    for(long long i=0; i<n-1; i++){
        long long sum = (x*(arr[i+1][0] - arr[i][0])) + (y*(arr[i+1][1] - arr[i][1])) + (z*(arr[i+1][2] - arr[i][2]));
        if(sum==0) count++;
    }
    if(count==n-1) res.push_back("TAK");
    else res.push_back("NIE");

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    long long tc, n;
    cin>>tc;

    for(long long i=0; i<tc; i++){
        cin>>n;
        for(long long j=0; j<n; j++){
            long long x, y, z;
            cin>>x>>y>>z;
            arr[j][0] = x;
            arr[j][1] = y;
            arr[j][2] = z;
        }
        spider(n);
    }

    for(long long i=0; i<tc; i++){
        cout<<"#"<<i+1<<" "<<res[i]<<"\n";
    }

    return 0;
}