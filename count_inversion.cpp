#include <bits/stdc++.h> 

int merge(long long *arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    int cnt=0;
    vector<int> t;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
         t.push_back(arr[left]);
         left++;
        }else{
            t.push_back(arr[right]);
            cnt += mid-left+1; //modificatiion in std merge sort
            right++;
        }
    }

    while(left<=mid){
         t.push_back(arr[left]);
         left++;
    }

    while(right<=high){
            t.push_back(arr[right]);
            right++;
    }

    for(int i=low; i<=high; i++){
        arr[i]=t[i-low];
    }
    return cnt;
}
int mergeSort(long long *arr,int s,int e){
    int mid = (s+e)/2;
     int cnt=0;
     if (s >= e) return cnt;
   
    cnt+=mergeSort(arr,s,mid);
    cnt+=mergeSort(arr,mid+1,e);
    cnt+=merge(arr,s,mid,e);
    return cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
     return mergeSort(arr, 0, n - 1);
}