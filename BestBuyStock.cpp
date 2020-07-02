//122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for (auto it = prices.cbegin() + 1; it != prices.cend(); ++it) {
            if(*it > *(it-1)) profit += *it - *(it-1);
        }
        return profit;
    }
};
/*
Runtime: 12 ms, faster than 68.88% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 13.2 MB, less than 46.59% of C++ online submissions for Best Time to Buy and Sell Stock II.
*/
