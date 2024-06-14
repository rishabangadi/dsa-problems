class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int limit = 5000;
        sort(weight.begin(), weight.end());
        int sum = 0;
        for (int i = 0; i < weight.size(); i++) {
            sum += weight[i];
            if (sum > limit)
                return i;
        }
        return weight.size();
    }
};