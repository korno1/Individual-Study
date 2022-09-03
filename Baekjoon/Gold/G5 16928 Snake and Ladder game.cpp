#include <iostream>
#include <queue>
using namespace std;

int visitSeq[101] = {0,};
int lad[101] = {0,}; 

void game(queue<int> q){
    q.push(1);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        //cout<<u<<endl;
        //현재 있는 칸에서 주사위를 굴려서 갈 수 있는 칸을 살펴본다. 
        for(int i=u+1; i<u+7; i++){
            if(i<=100){
                if(lad[i]==0){ //사다리나 뱀이 없는경우, 즉 주사위를 굴린것만 이동
                    if(visitSeq[i]==0){ //이전에 방문했던 칸이면 관여하지 않는다(최소값을 위함)
                        visitSeq[i] = visitSeq[u]+1; 
                        q.push(i);
                    }
                }
                else if(lad[i]!=0){ //사다리나 뱀이 있는경우
                    visitSeq[i] = visitSeq[u]+1; //현재칸은 이전칸에서 +1을 해줌
                    //사다리나 뱀의 끝이 시작의 값보다 크거나 끝이 0일때 
                    if(visitSeq[lad[i]] > visitSeq[i] || visitSeq[lad[i]]==0)
                        visitSeq[lad[i]] = visitSeq[i];
                    q.push(lad[i]); //뱀을 타고 내려오는 경우가 더 빠를 수 있어서 먼저 계산해줌
                    /*
                    ex)
                        2 1
                        2 60
                        30 98
                        65 25  
                    */
                    lad[i] = 0; //사다리나 뱀의 경로가 <=6일 경우 무한 반복
                }
            }
        }
    }

}

int main(){
    int n, m;
    int max=0, maxlad=0;
    queue<int> q;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        lad[x] = y;
    }

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        lad[x] = y;
    }

    game(q);
    cout<<visitSeq[100]<<endl;

    return 0;
}