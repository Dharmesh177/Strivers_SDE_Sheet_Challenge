class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ss;
        int f=1;
        for(int i=1; i<n; i++){
            f *= i;
            ss.push_back(i);
        }
        ss.push_back(n);
         string ans = "";
      k = k - 1;
         while (true) {
        ans = ans + to_string(ss[k / f]);
        ss.erase(ss.begin() + k / f);
        if (ss.size() == 0) {
          break;
        }

        k = k % f;
        f = f / ss.size();
      }
      return ans;
    }
};