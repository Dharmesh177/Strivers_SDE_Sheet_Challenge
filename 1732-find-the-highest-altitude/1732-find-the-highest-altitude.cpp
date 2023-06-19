class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=INT_MIN;
        int sum=0;
        for(int i=0; i<gain.size(); i++){
            sum += gain[i];
            res=max(res,sum);
        }
        if(res <0)return 0;
        return res;
    }
};