//1351. Count Negative Numbers in a Sorted Matrix
class Solution {
public:
    // The main algorithm problem is that you copy half of the vector every time, how can you save the space?
    // function name cases should be consistent
    int binarySearchInRow(vector<int> row){
        // What are the differences between vector<int>, vector<int>&, const vector<int>, and const vector<int>&?
        // Add comments
        if( row.empty() || row.at(row.size() - 1) >= 0) return 0;
        
        int count = 0;
        // Add comments
        if (row[0] < 0) {
            return row.size();
        }
        else {
            if (row[row.size()/2] < 0) {
                count += row.size() - row.size()/2;   
                vector<int> newVec(row.begin(), row.begin() + row.size()/2);
                // What are the differences between begin() and cbegin()? (Also rbegin() and crbegin())?
                count += binarySearchInRow(newVec);
            }
            else {
                vector<int> newVec(row.begin() + row.size()/2, row.end());
                count = binarySearchInRow(newVec);
            }
        }
        return count;
    }
 
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            // What is the difference between i++ and ++i?
            count += binarySearchInRow(grid[i]);
        }
        return count;
    }
};
/*
Runtime: 40 ms, faster than 28.26% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 12.9 MB, less than 5.08% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.


Should not use recursive


 int binarysearch(vector<int> nums)
    {
        int low=0;
        int high=nums.size()-1;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<0)
                high=mid;
            else
                low=mid+1;
        }
        
        if(nums[low]<0)
            return nums.size()-low;
        else
            return 0;
    }



Runtime: 32 ms, faster than 91.10% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 11.1 MB, less than 10.63% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.



*/
