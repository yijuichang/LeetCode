//1221. Split a String in Balanced Strings
class Solution {
public:
    int balancedStringSplit(string s) {
        int count_L = 0;
        int count_R = 0;
        int count_pair = 0;
        for (auto it=s.cbegin();it!=s.cend();++it){
            if ( *it == 'L') ++count_L;
            if ( *it == 'R') ++count_R;
            if (count_L == count_R) {
                ++count_pair;
                count_L = count_R = 0;
            }
        }
        return count_pair;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split a String in Balanced Strings.
Memory Usage: 6.3 MB, less than 28.21% of C++ online submissions for Split a String in Balanced Strings.
*/
