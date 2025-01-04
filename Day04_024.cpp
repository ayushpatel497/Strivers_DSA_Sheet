class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Q. Longest Substring Without Repeating Characters
        vector<int> dict(226, -1);
        int ans = 0, start = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};