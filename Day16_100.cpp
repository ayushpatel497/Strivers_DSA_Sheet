Solution{
    int minimumCharRequired(string s) {
        // Q. Minimum Characters required to make a String Palindromic
        int k = s.size();
        string text = s;
        reverse(text.begin(), text.end());
        s = s + '#' + text;
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        lps[0] = 0;
        while(i < n){
            if(s[i] == s[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    j = lps[j - 1];
                }
            }
        }
        return k - lps[n - 1];
    }
};

