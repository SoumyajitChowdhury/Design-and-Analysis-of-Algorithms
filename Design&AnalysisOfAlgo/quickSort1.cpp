//here we consider the first element in array as pivot element
#include<iostream>
using namespace std;
int pertition(int arr[], int low ,int high){
    int x = arr[low];
    int i = low;
    // int j = low+1;
    for(int j = low+1;j<=high;j++){///j<=high because we sent high as (n-1) 
        if(x>=arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[i]);
    return i;
}

void quickSort(int arr[],int low ,int high){
    if(low>=high){
        return;
    }
    int i = pertition(arr,low,high);
    quickSort(arr,low,i-1);
    quickSort(arr,i+1,high);
}
int main(){
    int arr[]={33,55,11,44,22,66};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
} 