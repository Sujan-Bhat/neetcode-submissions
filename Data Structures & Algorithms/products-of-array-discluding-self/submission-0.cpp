class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int numOfZero = 0;
        int idx;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                numOfZero++;
                idx = i;
                if(numOfZero > 1){
                    break;
                }
                continue;
            }
            product *= nums[i];
        }

        vector<int> ans(nums.size(), 0);

        if(numOfZero == 1){
            ans[idx] = product;
        } else if(numOfZero < 1){
            for(int i = 0; i < nums.size(); i++){
                ans[i] = (int)(product / nums[i]);
            }
        }

        return ans;
    }
};
