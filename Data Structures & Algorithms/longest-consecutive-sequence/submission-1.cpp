class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0 || n == 1) return n;

        unordered_set<int> hashSet;

        for(const int& number: nums){
            hashSet.insert(number);
        }

        int ans = 1;

        for(const int& number: hashSet){ 
            
            if(hashSet.find(number - 1) == hashSet.end()){
                int len = 1;
                while(hashSet.find(number + len) != hashSet.end()){
                    len++;
                }
                ans = max(len, ans);
            }
        }

        return ans;
        
    }
};