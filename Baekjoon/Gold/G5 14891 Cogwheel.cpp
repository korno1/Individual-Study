#include <iostream>
#include <deque>

using namespace std;

int cal(deque<char> d[]){
    int sum=0;
    int score[5] = {0,1,2,4,8};
    
    for(int i=1; i<=4; i++){
        if(d[i][0]=='1') {
            sum += score[i];
        }
    }
    return sum;
    
}

int wheel(deque<char> d[], int k){
    for(int i=0; i<k; i++){
        int rotate[5] = {0,};
        int num, dir; //번호, 방향
        cin>>num>>dir;
        rotate[num] = dir; //톱니바퀴 번호의 회전방향

        //모든 톱니바퀴의 회전의 유무와 방향을 미리 결정
        for(int j=num; j<4; j++){
            if(rotate[j]!=0) {
                if(d[j][2] != d[j+1][6]){
                    rotate[j+1] = -rotate[j];
                }
            }
        }
        for(int j=num; j>1; j--){
            if(rotate[j]!=0) { 
                if(d[j][6] != d[j-1][2])
                    rotate[j-1] = -rotate[j];
            }
        }

        //회전
        for(int j=1; j<=4; j++){
            if(rotate[j]==1){
                d[j].push_front(d[j].back());
                d[j].pop_back();
            }
            else if(rotate[j]==-1){
                d[j].push_back(d[j].front());
                d[j].pop_front();
            }
        }
    }

    return cal(d);
}

int main(){
    int k;
    deque<char> d[5];
    string s;

    for(int i=1; i<=4; i++){
        cin>>s;
        for(int j=0; j<8; j++){
            d[i].push_back(s[j]);
        }
    }
    
    cin>>k;


    cout<<wheel(d, k)<<endl;

    return 0;
}