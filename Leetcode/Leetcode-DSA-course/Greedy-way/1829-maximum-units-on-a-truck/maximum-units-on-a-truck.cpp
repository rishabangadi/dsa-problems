class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> boxes;
        for (auto& box : boxTypes) {
            boxes.push_back(pair(box[1], box[0]));
        }
        sort(boxes.begin(), boxes.end(), greater<pair<int, int>>());

        int total = 0;
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i].second <= truckSize) {
                total += boxes[i].first * boxes[i].second;
                truckSize -= boxes[i].second;
            } else {
                total += boxes[i].first * truckSize;
                break;
            }
        }
        return total;
    }
};