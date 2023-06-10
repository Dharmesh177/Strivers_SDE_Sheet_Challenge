class Solution {
    void swapper(vector<int>& arr1, vector<int>&arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int len = n +m;
        int gap = len/2 +len%2;
        while(gap>0){
            int left=0,right=left+gap;
            while(right <len){
                //arr1 and arr2 case
                if(left<m && right >=m){
                    swapper(arr1,arr2,left,right-m);
                }else if(left>=m){
                    //arr2 and arr2
                    swapper(arr2,arr2,left-m,right-m);
                }else{
                    swapper(arr1,arr1,left,right);
                }
                left++,right++;
            }
             if (gap == 1) break;

            gap = gap/2 + gap%2;
        }
        for(int i=0; i<n; i++){
            arr1[m+i] = arr2[i];
        }
        
    }
};