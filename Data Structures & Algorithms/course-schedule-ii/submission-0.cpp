class Solution {
public:
    bool isCyclic(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prereq){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < prereq.size(); i++){
            for(int j = 0; j < 2; j++){
                if(prereq[i][1] == src){
                    if(!vis[prereq[i][0]]){
                        if(isCyclic(prereq[i][0], vis,recPath, prereq)) return true;
                    } else if(recPath[prereq[i][0]]) return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topo(int src, vector<bool>& vis, vector<vector<int>>& prereq, stack<int>& s){
        vis[src] = true;
    
        for(int i = 0; i < prereq.size(); i++){
            for(int j = 0; j < 2; j++){
                if(prereq[i][1] == src){
                    if(!vis[prereq[i][0]]){
                        topo(prereq[i][0], vis, prereq, s);
                    }
                }      
            }
        }
        s.push(src);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);
        
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(isCyclic(i, vis, recPath, prerequisites)){
                    return {};
                }
            }
        }
        vector<int> ans;
        stack<int> s;
        vis.assign(numCourses, false);
        
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                topo(i, vis, prerequisites, s);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;

    }
};