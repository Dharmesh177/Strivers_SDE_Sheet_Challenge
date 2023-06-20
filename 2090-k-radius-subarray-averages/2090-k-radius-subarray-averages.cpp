class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
         int n=nums.size();
      vector<int> res(nums.size(),-1);
      vector<long long>pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];
        
        
       
      for(int i=k; i<=(n-k-1); i++){
       
          long long lsum =0;
          long long rsum = pref[i+k];
           if (i - k > 0)
                    lsum = pref[i - k - 1];
          res[i] = ((rsum - lsum)/(2*k+1));
      }
        return res;
    }
};