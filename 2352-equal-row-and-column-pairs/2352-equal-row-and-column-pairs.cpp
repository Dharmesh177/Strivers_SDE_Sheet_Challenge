class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> temp;
        temp=grid;
        int n=temp.size();
        for(int i=0; i<temp.size(); i++)
        {
            for(int j=0; j<i; j++){
               swap(temp[i][j],temp[j][i]);
            }
        }
        int ans=0;
         for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i] == temp[j])
                {
                    ans++;
                }
            }
        }
        return ans;
        
        
    }
};