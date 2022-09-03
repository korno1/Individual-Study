//LCS
#include <iostream>
using namespace std;

string x, y, z;
int c[101][101][101];

int LCS(int s1, int s2, int s3){
    for(int i=1; i<=s1; i++){
        for(int j=1; j<=s2; j++){
            for(int k=1; k<=s3; k++){
                if(x[i-1] == y[j-1] && x[i-1] == z[k-1]){
                    c[i][j][k] = c[i-1][j-1][k-1]+1;
                }
                else{
                    c[i][j][k] = max(max(c[i-1][j][k], c[i][j-1][k]), c[i][j][k-1]);
                }
            }
        }
    }

    return c[s1][s2][s3];
}

int main(){
    cin>>x>>y>>z;

    cout<<LCS(x.size(), y.size(), z.size())<<endl;
    return 0;
}