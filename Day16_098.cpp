class Solution {
public:
    vector<int> z_function(string s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    
    int strStr(string haystack, string needle) {
        // Z Algorithm
        int k = (int) needle.size();
        if(haystack == needle || k == 0) return 0;
        string s = needle + "$" + haystack;
        vector<int> z = z_function(s);
        int n = (int) s.size();
        for(int i = 0; i < n; i++) {
            if(z[i] == k) {
                return i - k - 1;
            }
        }
        return -1;
    }
};