class Solution {
public:
    int romanToInt(string s) {
        // Q Roman to Integer
        unordered_map<char, int> um;

        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); ++i){
            if(um[s[i]] < um[s[i + 1]]){
                ans -= um[s[i]];
            }
            else{
                ans += um[s[i]];
            }
        }
        return ans;
    }
};