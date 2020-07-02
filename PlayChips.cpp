//1217. Play with Chips
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int count_even=0, count_odd=0;
        for (auto it = chips.cbegin(); it != chips.cend(); ++it) {
            (*it % 2 == 0) ? ++count_odd : ++count_even;
        }
        return std::min(count_even, count_odd);
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Play with Chips.
Memory Usage: 7.5 MB, less than 30.66% of C++ online submissions for Play with Chips.
*/
