class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        if(temperature.size() <= 1) return {0};
        vector<int> ans(temperature.size(), 0);
        stack<pair<int, int>> s;//temp, size
        s.push({temperature[0], 0});

        for(int i = 1; i < temperature.size(); i++){
            while(!s.empty() && temperature[i] > s.top().first){
                //int ele = s.top().first; ->not required
                int idxOfEle = s.top().second;
                s.pop();

                ans[idxOfEle] = i - idxOfEle;
            }
            s.push({temperature[i], i});
        }
        while(!s.empty()){
            int idxOfEle = s.top().second;
            s.pop();
            ans[idxOfEle] = 0;
        }
        return ans;
    }
};
