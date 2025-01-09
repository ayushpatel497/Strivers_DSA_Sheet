class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Q. Palindrome Partitioning
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }

    void solve(string s, int index, vector<string> curr, vector<vector<string>>& ans){
        if(index == s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i = index; i < s.length(); ++i){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, curr, ans);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string str, int l, int r){
        while (l < r){
            if (str[l++] != str[r--]){
                return false;
            }    
        }
        return true;
    }
};