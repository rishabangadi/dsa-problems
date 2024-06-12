class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> queue({start});
        vector<bool> seen(n, false);
        seen[start] = true;
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            if (arr[node] == 0)
                return true;

            vector<int> neighbours;
            if (node + arr[node] < n)
                neighbours.push_back(node + arr[node]);
            if (node - arr[node] >= 0)
                neighbours.push_back(node - arr[node]);

            for (int neighbour : neighbours) {
                if (!seen[neighbour]) {
                    seen[neighbour] = true;
                    queue.push(neighbour);
                }
            }
        }
        return false;
    }
};