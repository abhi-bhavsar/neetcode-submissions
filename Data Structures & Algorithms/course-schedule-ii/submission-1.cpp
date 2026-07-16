class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0) ;
        vector<vector<int>> grid(numCourses) ;
        for(int i=0;i<prerequisites.size();i++) {
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;

            grid[v].push_back(u) ;
            indegree[u]++ ;
        }
        queue<int>qu ;
        vector<int>ans ;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                qu.push(i) ;
            }
        }
        if(qu.empty()) {return ans; }

        while(!qu.empty()) {
            int node = qu.front() ;
            ans.push_back(node) ;
            qu.pop() ;

            for(int i=0;i<grid[node].size();i++) {
                int curr_node = grid[node][i] ;
                indegree[curr_node]-- ;
                if(indegree[curr_node]==0){
                    qu.push(curr_node) ;
                }
            }
        }

        return ans.size()==numCourses ? ans : vector<int>{} ;
    }
};
