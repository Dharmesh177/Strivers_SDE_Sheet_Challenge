//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void f(int idx, int &sum,vector<int> & arr,int n,vector<int> &res){
        if(idx>=n){
            res.push_back(sum);
            return;
        } 
        
        sum += arr[idx];
        f(idx+1,sum,arr,n,res);
        sum-=arr[idx];
        f(idx+1,sum,arr,n,res);
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> res;
        int sum=0;
        f(0,sum,arr,n,res);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends