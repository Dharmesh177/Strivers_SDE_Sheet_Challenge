class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int ans=-1,cnt=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]==1){
                cnt++;
            }else{
              cnt=0;
            }
            ans=max(ans,cnt);
        }
     return ans;       
    }
};