class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     set<int> st;
     for(auto xx : nums){
         st.insert(xx);
     }
        
     int ans = 0;
     
        for(auto num :nums){
            if(!st.count(num-1)){
               int  cur = num;
               int currstreak = 1;
                
                while(st.count(cur+1)){
                   cur++;
                   currstreak++;
                }
                ans = max(ans,currstreak);
            }
        }
     return ans;
    }
};