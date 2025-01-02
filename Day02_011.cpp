class Solution {
public:
    vector<int> repeatedNumber(vector<int> &A) {
        // Q. Repeat and Missing Number Array
        vector<int> help(A.size(),0);
        for(int i = 0; i < A.size(); ++i){
            help[A[i]-1]++;
        }
        int miss = 0;
        int rep = 0;
        for(int i = 0; i < A.size(); ++i){
            if(help[i] == 0){
                miss = i + 1;
            }
            else if(help[i] == 2){
                rep = i + 1;
            }
        }
        return {rep,miss};
    }
};