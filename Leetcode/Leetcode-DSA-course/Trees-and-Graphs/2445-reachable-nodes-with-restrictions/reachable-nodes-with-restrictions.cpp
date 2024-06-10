class Solution {
public:
    unordered_map<int,vector<int>> graph;
    vector<bool> seen;
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> set(restricted.begin(),restricted.end());
        seen=vector(n,false);
        for(auto &edge:edges){
            int x=edge[0], y=edge[1];
            graph[x].push_back(y);            
            graph[y].push_back(x);
        }
        
        int ans=1;
        
        seen[0]=true;
        stack<int> stack;
        stack.push(0);
        while(!stack.empty()){
            int node=stack.top();
            stack.pop();
            // if(set.find(node)!=set.end()) return 0;
            for(int n:graph[node]){
                if(!seen[n] && set.find(n)==set.end()){
                    ans++;
                    seen[n]=true;
                    stack.push(n);
                }
            }
        }
        return ans;
    }   
};