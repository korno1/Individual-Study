//BasicSortingAlgorithm
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int comp=0;
    int intswap=0;

    for(int i=n-1; i>0; i--){
        int k=0;
        for(int j=1; j<=i; j++){
            comp++;
            if(arr[j]>arr[k])
                k=j;
        }
        if(k!=i){
            intswap++;
            swap(arr[k], arr[i]);
        }
    }
    cout<<"comp: "<<comp<<", swap: "<<intswap<<endl;
}

void bubbleSort(int arr[], int n){
    int comp=0;
    int intswap=0;

    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            comp++;
            if(arr[j]>arr[j+1]){
                intswap++;
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout<<"comp: "<<comp<<", swap: "<<intswap<<endl;
}

void insertionSort(int arr[], int n){
    int comp=0;
    int intswap=0;

    for(int i=1; i<n; i++){
        int loc = i-1;
        int item = arr[i];
        while(loc>=0){
            comp++;
            if(item<arr[loc]){
                intswap++;
                arr[loc+1] = arr[loc];
                loc--;
            }
            else{
                break;
            }
        }
        arr[loc+1] = item;
        intswap++;
    }

    cout<<"comp: "<<comp<<", swap: "<<intswap<<endl;
}

int main(){
    int n;
    int selectArr[10000]={0,}, bubbleArr[10000]={0,}, insertArr[10000]={0,};
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>selectArr[i];
        bubbleArr[i] = selectArr[i];
        insertArr[i] = selectArr[i];
    }
    
    
    selectionSort(selectArr, n);
    bubbleSort(bubbleArr, n);
    insertionSort(insertArr, n);

    return 0;
}