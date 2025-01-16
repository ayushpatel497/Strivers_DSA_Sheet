class Solution {
public:
    string countAndSay(int n) {
        // Q. Count and Say
        if(n == 1){
            return "1";
        }
        string prevSay = countAndSay(n - 1);
        string currSay = "";
        int count = 1;
        for(int index = 0; index < prevSay.length(); ++index){
            if(index + 1 < prevSay.length() && prevSay[index] == prevSay[index + 1]){
                count += 1;
            }
            else{
                currSay += to_string(count) + prevSay[index];
                count = 1;
            }
        }
        return currSay;
    }
};