class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //if(s.size() == 1) return 1;

        int ans = 0;
        int low  = 0;
        int high = 0;
        int len;
        vector<int> hash(95,-1);
        // i - j valid substring -> j+1 ->invalid -> prevIndx of i = s[j+1] + 1;

        while(high < s.size()){
            if(hash[s[high]-' '] >= low){
                low = hash[s[high]-' '] + 1;
            }
            len = high - low + 1;
            if(len > ans){
                ans = len;
            }
            hash[s[high]-' '] = high;
            high++;
        }


        return ans;
    }
};
