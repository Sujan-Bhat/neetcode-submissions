class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> maxHeap;

        for(int i = 0; i < n; i++){
            maxHeap.push(nums[i]);
        }

        for(int i = 1; i < k; i++){
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};
