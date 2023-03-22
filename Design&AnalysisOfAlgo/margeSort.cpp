#include<iostream>
using namespace std;

void marge(int arr[],int l,int mid,int h){
    //length of two sub arrays a and b
    int an=mid+1-l;
    int bn=h-mid;
    //create 2 temporary array
    int a[an];
    int b[bn];
    for(int i=0;i<an;i++){
        a[i]=arr[l+i];
    }
    for(int j=0;j<bn;j++){
        b[j]=arr[mid+1+j];
    }
    int i=0;//initial index of first subarray,a 
    int j=0;//initial index of second subarray ,b
    int k=l;//initial index of marged subarray
    while(i<an and j<bn){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }
}

void margeSort(int arr[],int l,int h){
    //base case
    if(l>=h){
        return;
    }
    else{
        int mid=(l+h)/2;
        margeSort(arr,l,mid);
        margeSort(arr,mid+1,h);
        marge(arr,l,mid,h);
    }
}

int main(){
    int arr[]={10,28,24,6,34,18,38,44};
    int n=sizeof(arr)/sizeof(arr[0]);
    margeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}