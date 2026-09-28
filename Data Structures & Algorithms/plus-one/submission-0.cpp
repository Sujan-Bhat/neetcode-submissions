class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int sum  = 0, carry = 1;

        for(int i = digits.size() - 1; i >= 0 ; i--){
            sum = digits[i] + carry;
            carry = 0;
            if(sum > 9){
                sum = sum - 10;
                carry = 1;
            }
            ans.push_back(sum);
        }
        if(carry > 0){
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
