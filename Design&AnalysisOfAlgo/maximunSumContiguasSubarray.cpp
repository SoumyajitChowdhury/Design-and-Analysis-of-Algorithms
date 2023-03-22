//Given an array of size n .Find the sum of contiguous subarray 
//in the given  array with leargest value
#include <iostream>
#include<limits.h>
using namespace std;

int maxCrossingSum(int arr[],int l,int m,int h){
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = m ; i>=0 ;i--){
        sum = sum + arr[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for(int i = m+1 ; i<=h ;i++){
        sum = sum + arr[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }

    return max((left_sum + right_sum , left_sum) , right_sum);
}
int maxSubArraySum(int arr[],int l ,int h){
    if(l>=h)    return arr[l];
    int m = (l+h)/2;
    int lss = maxSubArraySum(arr,l,m);
    int rss = maxSubArraySum(arr,m+1,h);
    int css = maxCrossingSum(arr,l,m,h);

    return max((lss , rss ), css);
}
int main(){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0 , n-1);
    cout<<"Maximum contiguous sub array sum is "<<max_sum<<endl;
}