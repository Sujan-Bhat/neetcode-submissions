class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n == 1) return 1;
        if(n == k) return k;

        int i = 0;
        int j = 1;
        int ans = 1;

        vector<int> hash(26, 0);
        hash[s[i] - 'A'] = 1;
        
        int count  = 1;

        while(j < n){

            hash[s[j] - 'A']++;
            count = max(count, hash[s[j] - 'A']);

            int curLen = j - i + 1;

            int maxReplacement = curLen - count;
            if(maxReplacement > k){
                hash[s[i] - 'A']--;
                i++;
                curLen = j - i + 1;
            }
                       
            ans = max(ans, curLen);
            j++;
        }
        return ans;
    }
};
