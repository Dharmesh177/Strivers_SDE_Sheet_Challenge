class Solution {
public:
 
bool isPalindrom (string s,int st,int en){
    while(st<=en){
        if(s[st]!=s[en])return false;
        st++;en--;
    }
    return true;
}

void f(int idx,string &s,vector<string>&path,vector<vector<string>> &res){
  if(idx==s.size()){
      res.push_back(path);
      return;
  }

  for(int i=idx; i<s.size(); i++){
      if(isPalindrom(s, idx,i)){
          path.push_back(s.substr(idx,i-idx+1));
          f(i+1,s,path,res);
          path.pop_back();
      }
  }
}

vector<vector<string>> partition(string s) 
{
    // Write your code here.
    vector<string> path;
    vector<vector<string>> res;
    f(0,s,path,res);
    return res;
}
};