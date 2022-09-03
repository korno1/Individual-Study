//날짜 정렬하기
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void radixSort(string arr[], int n){
    queue<string> q[10];
    for(int i=7; i>=0; i--){
        for(int j=0; j<n; j++){
            int d = arr[j][i] - '0';
            q[d].push(arr[j]);
        }
        int p = 0;
        for(int j=0; j<10; j++){
            while(!q[j].empty()){
                arr[p++] = q[j].front();
                q[j].pop();
            }
        }
    }
}

int main(){
    string arr[500000];
    string day, month, year;
    int n;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>day>>month>>year;
    
        if(year.size()<4){
            while(year.size()<4){
                year = '0' + year;
            }
        }
        
        arr[i] = year;

        if(month.size()<2) month = '0' + month;
        arr[i] += month;
        
        if(day.size()<2) day = '0' + day;
        arr[i] += day;
    }
    
    radixSort(arr, n);


    
    for(int i=0; i<n; i++){
        year = "", month = "", day = "";
        
        if(arr[i]<"00100000"){
            year.append(arr[i], 3, 1);
        }

        else if(arr[i]<"01000000"){
            year.append(arr[i], 2, 2);
        }

        else if(arr[i]<"10000000"){
            year.append(arr[i], 1, 3);
        }

        else year.append(arr[i], 0, 4);

        if(arr[i][4]!='0')
            month.append(arr[i], 4, 2);
        else month.append(arr[i], 5, 1);

        if(arr[i][6]!='0')
            day.append(arr[i], 6, 2);
        else day.append(arr[i], 7, 1);

        cout<<day<<" "<<month<<" "<<year<<endl;
    }
    
    return 0;


}