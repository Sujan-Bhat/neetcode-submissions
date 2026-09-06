class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>> maxHeap;

        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }

        for(auto it: hash){
            maxHeap.push({it.second, it.first});
        }

        while(k > 0 && !maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }

        return ans;
    }
};
