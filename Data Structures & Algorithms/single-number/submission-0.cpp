class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int unique = nums[0];
        for(int i=1;i<n;i++){
            unique = unique ^ nums[i];
        }
        return unique;
    }
};
