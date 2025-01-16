class Solution {
public:
    string sortString(string s){
        vector<int> frequency(26, 0);
        for(int index = 0; index < s.length(); ++index){
            frequency[s[index] - 'a'] += 1;
        }
        string reversedString = "";
        for(int index = 0; index < 26; ++index){
            reversedString += string(frequency[index], index + 'a');
        }

        return reversedString;
    }
    bool isAnagram(string s, string t) {
        // Q. Valid Anagram
        string sortedS = sortString(s);
        string sortedT = sortString(t);
        return sortedS == sortedT;
    }
};