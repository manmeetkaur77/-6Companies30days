#include <set>
class Solution {
public:
    int findTheWinner(int n, int k) {
        std::set<int> players;
        for (int i = 1; i <= n; ++i) {
            players.insert(i);
        }
        
        auto it = players.begin();
        while (players.size() > 1) {
            // Advance `k-1` steps, wrapping around the set if needed
            for (int count = 1; count < k; ++count) {
                ++it;
                if (it == players.end()) {
                    it = players.begin();
                }
            }
            // Erase the current element and move iterator to the next element
            it = players.erase(it);
            if (it == players.end()) {
                it = players.begin();
            }
        }
        
        return *players.begin();
    }
};
