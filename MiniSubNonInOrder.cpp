//1403. Minimum Subsequence in Non-Increasing Order
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> subsequence;
        std::sort (nums.begin(),nums.end()); 
        //should copy to a new vector before sort?
        //I am wondering if this operation change the input vector?

        
        int sum = 0;
        for(auto it = nums.cbegin(); it != nums.cend(); ++it) sum += *it;
        int sum_subsequence = 0;
       
        auto it = nums.crbegin();
        while (sum_subsequence <= sum) {
            subsequence.emplace_back(*it);
            sum -= *it;
            sum_subsequence += *it;
            ++it;
        }
        
        // The for loop below is much slower than the while loop why? (since the if statement inside it?)
        // for (auto rit = nums.crbegin(); rit != nums.crend(); ++rit) {
        //     if(sum_subsequence > sum) break;
        //     subsequence.emplace_back(*rit);
        //     sum -= *rit;
        //     sum_subsequence += *rit;
        // }
        
        return subsequence;
    }
};


/*
Runtime: 16 ms, faster than 77.59% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
Memory Usage: 10.8 MB, less than 30.52% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
*/
