class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        for(int i=0; i<letters.size(); i++){
          if(letters[i]-97 > target - 97 ){
              return letters[i];
          }
        }
        return letters[0];
    }
};