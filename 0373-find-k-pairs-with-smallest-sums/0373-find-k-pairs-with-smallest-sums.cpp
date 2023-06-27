class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==1) return  {{nums1[0],nums2[0]}};
        vector<vector<int>> res;
        int n1 = nums1.size();
               int n2 = nums2.size();
         priority_queue<pair<int, pair<int, int>>> pq;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                int sum = nums1[i] + nums2[j];
                
                if(pq.size() < k) pq.push({sum , {nums1[i],nums2[j]}});
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum , {nums1[i],nums2[j]}});
                }else if(sum > pq.top().first) break;
            }
        }
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            res.push_back({x.second.first, x.second.second});
        }

        return res;
    }
};

