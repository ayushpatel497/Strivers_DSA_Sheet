class Solution {
public:
    void makeLPS(string needle, vector<int>& longestPrefixSuffix){
        longestPrefixSuffix[0] = 0;
        int indexNeedle = 1;
        int prefixSuffixLength = 0;
        while(indexNeedle < needle.length()){
            if(needle[indexNeedle] == needle[prefixSuffixLength]){
                prefixSuffixLength += 1;
                longestPrefixSuffix[indexNeedle] = prefixSuffixLength;
                indexNeedle += 1;
            }
            else{
                if(prefixSuffixLength != 0){
                    prefixSuffixLength = longestPrefixSuffix[prefixSuffixLength - 1];
                }
                else{
                    longestPrefixSuffix[indexNeedle] = 0;
                    indexNeedle += 1;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        // Q. Find the Index of the First Occurrence in a String
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        if(needleSize == 0){
            return 0;
        }
        vector<int> longestPrefixSuffix(needleSize);
        makeLPS(needle, longestPrefixSuffix);
        int indexHaystack = 0;
        int indexNeedle = 0;
        while(indexHaystack < haystackSize){
            if(haystack[indexHaystack] == needle[indexNeedle]){
                indexHaystack += 1;
                indexNeedle += 1;
            }
            if(indexNeedle == needleSize){
                return indexHaystack - indexNeedle;
            }
            if(indexHaystack < haystackSize && haystack[indexHaystack] != needle[indexNeedle]){
                indexNeedle ? indexNeedle = longestPrefixSuffix[indexNeedle - 1] : indexHaystack += 1;
            }
        }
        return -1;
    }
};