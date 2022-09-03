//Advanced Sorting Algorithms
#include <iostream>
using namespace std;

int mcomp=0, mswap=0;
int qcomp=0, qswap=0;
int hcomp=0, hswap=0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int arr[], int l, int m, int r){
    int i = l, j = m+1, t = 0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        mcomp++;
        if(arr[i]<=arr[j]){
            temp[t++] = arr[i++];
            mswap++;
        }
        else{
            temp[t++] = arr[j++];
            mswap++;
        }
    }

    while(i<=m){
        temp[t++] = arr[i++];
        mswap++;
    }

    while(j<=r){
        temp[t++] = arr[j++];
        mswap++;
    }

    i=l; t=0;
    while(i<=r){
        arr[i++] = temp[t++];
        mswap++;
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

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<=r-1; j++){
        qcomp++;
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
            qswap++;
        }
        for(int k=0; k<5; k++) cout<<arr[k]<<" ";
        cout<<endl;
    }
    swap(arr[i+1], arr[r]);
    qswap++;

    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

void downHeap(int arr[], int i, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;

    if(l<=n){
        hcomp++;
        if(arr[l]>arr[largest]){
            largest = l;
        }
    }

    if(r<=n){
        hcomp++;
        if(arr[r]>arr[largest])
            largest = r;
    }

    if(largest!=i){
        swap(arr[i], arr[largest]);
        hswap++;
        downHeap(arr, largest, n);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2; i>=0; i--){
        downHeap(arr, i, n);
    }

    for(int i=n; i>=1; i--){
        swap(arr[i], arr[0]);
        hswap++;
        downHeap(arr, 0, i-1);
    }
}

int main(){
    int n;
    int mergeArr[100000]={0,}, quickArr[100000]={0,}, heapArr[100000]={0,};
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>mergeArr[i];
        quickArr[i] = mergeArr[i];
        heapArr[i] = mergeArr[i];
    }
    
    //mergeSort(mergeArr, 0, n-1);
    //cout<<"comp: "<<mcomp<<", swap: "<<mswap<<endl;
    quickSort(quickArr, 0, n-1);
    //cout<<"comp: "<<qcomp<<", swap: "<<qswap<<endl;
    //heapSort(heapArr, n-1);
    //cout<<"comp: "<<hcomp<<", swap: "<<hswap<<endl;
    
    return 0;
}