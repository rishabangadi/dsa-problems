class Solution {
public:
    vector<bool> seen;
    vector<vector<int>> graph;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        graph=rooms;
        seen=vector(n,false);

        seen[0]=true;
        dfs(0);
        for(bool val:seen)
            if(!val) return false;
        return true;
    }

    void dfs(int node){
        for(auto n:graph[node]){
            if(!seen[n]){
                seen[n]=true;
                dfs(n);
            }
        }
    }
};