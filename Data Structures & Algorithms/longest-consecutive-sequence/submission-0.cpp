class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0 || n == 1) return n;

        unordered_set<int> hashSet;

        for(const int& number: nums){ //O(n)
            hashSet.insert(number);
        }

        vector<int> startingValue;

        for(const int& number: hashSet){ // O(n)
            if(hashSet.find(number - 1) == hashSet.end()){
                startingValue.push_back(number);
            }
        }

        int count = 0;
        int curNumber = startingValue[0];
        int idx = 0;
        int len = 1, ans = 1;

        while(count < hashSet.size()){
            count++;
            if(hashSet.find(curNumber + 1) != hashSet.end()){
                curNumber = curNumber + 1;
                len += 1;
                ans = max(ans, len);
            } else{
                if(idx + 1 < startingValue.size()){
                    curNumber = startingValue[++idx];
                    len = 1;
                } else{
                    break;
                }
            }
        }
        ans = max(ans, len);
        return ans;
        
    }
};