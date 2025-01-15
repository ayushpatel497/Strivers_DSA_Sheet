class Solution {
public:
    string longestPalindrome(string s) {
        // Q. Longest Palindromic Substring
        int n = s.length();
        int palindromeLength = 0;
        pair<int, int> position;
        for (int i = 0; i < n; ) {
            int left = i;
            int right = i;
            while (right < n - 1 && s[right] == s[right + 1])
                right++;
            i = right + 1;
            while (right < n - 1 && left > 0 && s[left - 1] == s[right + 1])
                left--, right++;
            if(right - left + 1 > palindromeLength){
                palindromeLength = right - left + 1;
                position = {left, right};
            }
        }
        return s.substr(position.first, position.second - position.first + 1);
    }
};