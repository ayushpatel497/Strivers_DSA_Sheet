class Solution {
public:
    string reverseWords(string s) {
        // Q. Reverse Words in a String
        s += " ";
        string ans = "";
        string temp = "";
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' ' && temp.length()>0) {
                if(ans.length() == 0)
                    ans = temp + ans;
                else
                    ans = temp + " " + ans;    
                temp = "";
            }
            else if(s[i] == ' ') continue;
            else {
                temp = temp + s[i];
            }
        }
        return ans;
    }
};