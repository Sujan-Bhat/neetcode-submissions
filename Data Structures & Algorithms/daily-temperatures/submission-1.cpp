class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        if(temperature.size() <= 1) return {0};
        vector<int> ans(temperature.size(), 0);
        stack<int> s;//temp, idx
        s.push(0);

        for(int i = 1; i < temperature.size(); i++){
            while(!s.empty() && temperature[i] > temperature[s.top()]){
                //int ele = s.top().first; ->not required
                int idxOfEle = s.top();
                s.pop();

                ans[idxOfEle] = i - idxOfEle;
            }
            s.push(i);
        }

        return ans;
    }
};
