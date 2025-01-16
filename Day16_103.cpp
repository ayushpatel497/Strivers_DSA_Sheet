class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Q. Compare Version Numbers
        int v1Size = version1.length();
        int v2Size = version2.length();
        int revision1 = 0, revision2 = 0;
        for(int v1Index = 0, v2Index = 0; v1Index < v1Size || v2Index < v2Size; ++v1Index, ++v2Index){
            while(v1Index < v1Size && version1[v1Index] != '.'){
                revision1 = 10 * revision1 + (version1[v1Index] - '0');
                v1Index += 1;
            }
            while(v2Index < v2Size && version2[v2Index] != '.'){
                revision2 = 10 * revision2 + (version2[v2Index] - '0');
                v2Index += 1;
            }
            if(revision1 < revision2) return -1;
            else if(revision1 > revision2) return 1;
            revision1 = 0;
            revision2 = 0;
        }
        return 0;
    }
};