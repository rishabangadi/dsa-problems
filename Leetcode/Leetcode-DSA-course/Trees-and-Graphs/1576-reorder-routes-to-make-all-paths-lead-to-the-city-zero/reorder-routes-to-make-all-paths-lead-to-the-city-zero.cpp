class Solution {
public:
    set<vector<int>> roads;
    unordered_map<int,vector<int>> graph;
    vector<bool> seen;
    int minReorder(int n, vector<vector<int>>& connections) {
        seen=vector(n,false);
        for(auto &edge:connections){
            int x=edge[0],y=edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            roads.insert({x,y});
        }

        seen[0]=true;

        stack<int> stack;
        stack.push(0);
        seen[0]=true;
        int ans=0;
        while(!stack.empty()){
            int node=stack.top();stack.pop();
            for(int n:graph[node]){
                if(!seen[n]){
                    if(roads.find({node,n})!=roads.end())
                        ans++;
                    seen[n]=true;
                    stack.push(n);
                }
            }
        }
        return ans;
    }
};