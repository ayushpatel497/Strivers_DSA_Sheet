class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Q. Assign Cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = g.size() - 1;
        int j = s.size() - 1;
        while(i >= 0 && j >= 0){
            if(g[i] > s[j]) 
                i--;
            else{ 
                ans++;
                j--;
                i--;
            }
        }
        return ans;
    }
};