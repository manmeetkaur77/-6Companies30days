class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Step 1: Sort envelopes by width in ascending order and by height in descending order if widths are the same
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
    });
    
    // Step 2: Extract the heights
    vector<int> heights;
    for (const auto& envelope : envelopes) {
        heights.push_back(envelope[1]);
    }
    
    // Step 3: Find the LIS of the heights
    vector<int> dp;
    for (int h : heights) {
        auto it = lower_bound(dp.begin(), dp.end(), h);
        if (it == dp.end()) {
            dp.push_back(h);
        } else {
            *it = h;
        }
    }
    
    return dp.size();
}
};