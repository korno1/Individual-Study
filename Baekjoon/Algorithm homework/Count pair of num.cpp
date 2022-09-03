//입력의 합이 되는 숫자 쌍 세기
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int arr[], int l, int m, int r){
    int i = l, j = m+1, t = 0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp[t++] = arr[i++];
        }
        else{
            temp[t++] = arr[j++];
        }
    }

    while(i<=m){
        temp[t++] = arr[i++];
    }

    while(j<=r){
        temp[t++] = arr[j++];
    }

    i=l; t=0;
    while(i<=r){
        arr[i++] = temp[t++];
    }

}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int middle = (l+r)/2;
        mergeSort(arr, l, middle);
        mergeSort(arr, middle+1, r);
        merge(arr, l, middle, r);
    }
    
}

int main(){
    int n, m;
    int arr[100000]={0,};
    int count = 0;
    int i=0, j;

    cin>>n>>m;
    j=n-1;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    while(i!=j){
        if((arr[i]+arr[j])==m){
            count++;
            i++;
        }

        else if((arr[i]+arr[j])>m) j--;

        else i++;
    }

    cout<<count;

    return 0;
}