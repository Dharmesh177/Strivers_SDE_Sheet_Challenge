class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
       priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int count=0,left=0,right=costs.size()-1;
        long long result=0;
        while(count<k) {
            while(left<=right && pq1.size()<candidates) {
                pq1.push(costs[left]);
                left++;
            }
            while(right>=left && pq2.size()<candidates) {
                pq2.push(costs[right]);
                right--;
            }
            int first=pq1.size()>0?pq1.top():INT_MAX;
            int last=pq2.size()>0?pq2.top():INT_MAX;
            if(first<=last) {
                result+=first;
                pq1.pop();
            } else {
                result+=last;
                pq2.pop();
            }
            count++;
        }
        return result;
    }
};