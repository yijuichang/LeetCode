//852. Peak Index in a Mountain Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        int mid = (right - left) / 2;
        while (left < right){
            if (A[mid] < A[mid + 1]){
                left = mid + 1;
                mid = left + (right - left) / 2;
            }
            else if (A[mid] < A[mid - 1]) {
                right = mid - 1;
                mid = left + (right - left) / 2;
            }
            else {
                left = right;
            }
        }
        return mid;
    }
};
/*
Runtime: 20 ms, faster than 90.25% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 11.6 MB, less than 61.44% of C++ online submissions for Peak Index in a Mountain Array.
*/
