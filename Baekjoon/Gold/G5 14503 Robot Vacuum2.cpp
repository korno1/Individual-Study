#include <iostream>
using namespace std;

int arr[50][50] = {0,};
bool visited[50][50] = {0,};
int sum=0;
int d1[4] = {0, -1, 0, 1};
int d2[4] = {-1, 0, 1, 0};

void vacum(int r, int c, int d, int rotate){
    if(rotate==4){ //사방이 청소가 되어있거나, 벽일 때
        int rd = r + -d2[d]; //후방의 r좌표
        int cd = c + d1[d]; //후방의 c좌표

        if(arr[rd][cd]==0) vacum(rd, cd, d, rotate-4);
        else return;
    }
    else{
        int rd = r + d1[d]; //왼쪽의 r좌표
        int cd = c + d2[d]; //왼쪽의 c좌표
        int td = (d+3)%4; //왼쪽 방향
        
        if(visited[r][c]==0) {
            sum++;
            visited[r][c] = 1;
        } //청소 x일때만 더하기
        
        if(arr[rd][cd]==0 && visited[rd][cd]==0){ //왼쪽 벽x, 청소x
            rotate=0;
            vacum(rd, cd, td, rotate);
        }
        else vacum(r, c, td, rotate+1);
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