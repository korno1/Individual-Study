//Worst-case Linear Selection Algorithm
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;

    for(int j=l; j<r; j++){
        if(arr[j]<=pivot)
            swap(arr[++i], arr[j]);
    }

    swap(arr[i+1], arr[r]);
    return i+1;
}

int mom_partition(int arr[], int l, int r, int m){
    int idx=r;
    for(int i=l; i<r; i++){
        if(arr[i]==m){
            idx = i;
            break;
        }
    }

    swap(arr[idx], arr[r]);

    return partition(arr, l, r);
}

int quick_select(int arr[], int l, int r, int i){
    if(l==r)
        return arr[l];
    
    int p = partition(arr, l , r);
    int k = p-l+1;

    if(i<k) return quick_select(arr, l, p-1, i);
    else if(i==k) return arr[p];
    else if(i>k) return quick_select(arr, p+1, r, i-k);
}

int mom_select(int arr[], int l, int r, int i){
    int n = r - l + 1;
    if(n<=5) return quick_select(arr, l, r, i);
    
    else{
        int g = ceil(n/5.0);
        int brr[g];
  
        for(int j=0; j<g; j++){
            if(j==g-1)
				brr[j] = quick_select(arr,l+(j*5),r,ceil((double)(n-(j*5))/2));
			
			else 
				brr[j] = quick_select(arr, l+(j*5), l+(j*5)+4, 3);
        }

        
        int m = mom_select(brr, 0, g-1, ceil(g/2.0));
        
        int p = mom_partition(arr, l, r, m);

        
        int k = p - l + 1;
        cout << fixed << setprecision(2);
        cout<<m<<" "<<k<<" "<<n<<" "<<(double)k/n<<endl;


        if(i<k) return mom_select(arr, l, p-1, i);
		else if(i==k) return arr[p];
		else return mom_select(arr,p+1,r,i-k);
    }

}

int main(){
    int n, i;
    int arr[10001];
    
    cin>>n>>i;
    
    for(int j=0; j<n; j++) {
        cin>>arr[j];
    }

    mom_select(arr, 0, n-1, i);

    return 0;

}