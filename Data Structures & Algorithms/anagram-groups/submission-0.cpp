class Solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs){
            vector<vector<string>> ans;
            map<vector<int>, vector<string>> hash;
            
            for(int k = 0; k < strs.size(); k++){
                vector<int> tempFreq(26);
                for(int i = 0; i < strs[k].size(); i++){
                    tempFreq[strs[k][i] - 'a']++;
                }
                hash[tempFreq].push_back(strs[k]);
            }

            for(auto it: hash){
                ans.push_back(it.second);
            }

            return ans;
        }
};