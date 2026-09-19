class Solution {
public:
    bool isCyclic(int cur, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prerequisites){
        vis[cur] = true;
        recPath[cur] = true;

        for(int i = 0; i < prerequisites.size(); i++){
            if(prerequisites[i][1] == cur){
                if(!vis[prerequisites[i][0]]){
                    if(isCyclic(prerequisites[i][0], vis, recPath, prerequisites)) return true;
                } else if(recPath[prerequisites[i][0]]) return true;
            }
        }
        recPath[cur] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(isCyclic(i, vis, recPath, prerequisites)) return false;
            }
        }

        return true;
    }
};
