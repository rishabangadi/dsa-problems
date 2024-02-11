class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int maxAltitude = 0;
        for (int g : gain) {
            curr += g;
            maxAltitude = max(maxAltitude, curr);
        }
        return maxAltitude;
    }
};