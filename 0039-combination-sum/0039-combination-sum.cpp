class Solution {
public:
    void f(int i,vector<int>& arr, int target,vector<vector<int>> &res,vector<int> ss){
        if(i>arr.size()) return;
        if(i==arr.size()){
            if(target==0){
                res.push_back(ss);
            }
            return;
        }
        
        if(arr[i]<=target){
            ss.push_back(arr[i]);
            f(i,arr,target-arr[i],res,ss);
            ss.pop_back();
        }
        
        f(i+1,arr,target,res,ss);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> ss;
        f(0,arr,target,res,ss);
            return res;
    }
};