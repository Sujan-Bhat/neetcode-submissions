class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums;

        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;
        int n = nums.size();

        for(int i = 0; i < k; ++i){
            maxHeap.push({nums[i], i});
        }

        ans.push_back(maxHeap.top().first);
        if(k == n) return ans;

        for(int en = k; en < n; ++en){
            maxHeap.push({nums[en], en}); // log(n)
            while(maxHeap.top().second < en - k + 1){
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};
