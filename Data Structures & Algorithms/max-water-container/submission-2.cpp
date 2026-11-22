class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = INT_MIN;
        int left = 0;
        int right = heights.size() - 1;

        while(left < right){
            int curArea = std::min(heights[left], heights[right]) * (right - left);
            ans = std::max(ans, curArea);

            if(heights[left] <= heights[right]){
                left++;
            } else{
                right--;
            }
        }
        return ans;
    }
};
