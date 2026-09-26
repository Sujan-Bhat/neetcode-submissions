class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //1. Find indegree
        //2. Push elements with zero indegree into queue
        //3. Perform bfs

        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < prerequisites.size(); i++){
                indegree[prerequisites[i][0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            //neigbours
            for(int i = 0; i < prerequisites.size(); i++){
                if(prerequisites[i][1] == cur){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]] == 0){
                        q.push(prerequisites[i][0]);
                    }
                }
            }
        }
        if(ans.size() < numCourses){
            return {};
        }

        return ans;

    }
};
