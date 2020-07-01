//944. Delete Columns to Make Sorted
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // if (A.empty()) return 0; 
        int count=0;
        for (int i = 0; i < A[0].size(); ++i) {
            for (int j =0; j < A.size() - 1; ++j) {
                if (A[j][i] > A[j+1][i]) {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};
/*
Runtime: 84 ms, faster than 47.75% of C++ online submissions for Delete Columns to Make Sorted.
Memory Usage: 12.4 MB, less than 30.67% of C++ online submissions for Delete Columns to Make Sorted.
*/
