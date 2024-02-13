class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s)
            freq[ch]++;

        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), myCmp);
        string ans = "";
        for (auto p : v) {
            for (int i = 0; i < p.second; i++)
                ans += p.first;
        }
        return ans;
    }
    static bool myCmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};