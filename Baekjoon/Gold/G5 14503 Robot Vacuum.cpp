#include <iostream>
using namespace std;

int arr[50][50] = {0,};
bool visited[50][50] = {0,};
int sum=0;

void vacum(int r, int c, int d, int dnum){
    if(dnum==4){
        if(d==0){
            if(arr[r+1][c]==0) vacum(r+1, c, d, dnum-4);
            else return;
        }

        else if(d==1){
            if(arr[r][c-1]==0) vacum(r, c-1, d, dnum-4);
            else return;
            
        }

        else if(d==2){
            if(arr[r-1][c]==0) vacum(r-1, c, d, dnum-4);
            else return;
            
        }

        else if(d==3){
            if(arr[r][c+1]==0) vacum(r, c+1, d, dnum-4);
            else return;
        }
    }
    else{
        
        if(visited[r][c]==0) {
            sum++;
            visited[r][c] = 1;
        }
        
    
        if(d==0){
            if(arr[r][c-1]==0 && visited[r][c-1]==0)
                vacum(r, c-1, d+3, 0);
            else vacum(r, c, d+3, dnum+1);
            
        }

        else if(d==1){
            if(arr[r-1][c]==0 && visited[r-1][c]==0)
                vacum(r-1, c, d-1, 0);
            else vacum(r, c, d-1, dnum+1);
        }

        else if(d==2){
            if(arr[r][c+1]==0 && visited[r][c+1]==0)
                vacum(r, c+1, d-1, 0);
            else vacum(r, c, d-1, dnum+1);
        }
    
        else if(d==3){
            if(arr[r+1][c]==0 && visited[r+1][c]==0)
                vacum(r+1, c, d-1, 0);
            else vacum(r, c, d-1, dnum+1);
        }
    }
}

int main(){
    int n, m;
    int r, c, d;
    cin>>n>>m;
    cin>>r>>c>>d;

    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }

    vacum(r, c, d, 0);

    cout<<sum<<endl;

    return 0;
}