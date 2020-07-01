//1046. Last Stone Weight
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int i = 0;
        for (auto it = stones.rbegin(); it != stones.rend()-1; ++it) {
            std::sort(stones.begin(), stones.end() - i);
            ++i;
            if (*it == *(it+1)) {
                *(it+1) = 0;
            }
            else if (*it > *(it+1)) {
                *(it+1) = *it - *(it+1) ;
            }
            else {
                *(it+1) -= *it;
            }
                
        }
        return stones.front();
    }
};
/*
Runtime: 4 ms, faster than 59.66% of C++ online submissions for Last Stone Weight.
Memory Usage: 7.6 MB, less than 57.66% of C++ online submissions for Last Stone Weight.
*/
