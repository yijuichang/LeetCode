//1309. Decrypt String from Alphabet to Integer Mapping
class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        if(s.empty()) return result;
        //ASCII('0')=48, ASCII('a')=97, ASCII('i')=105
        for (auto it = s.cbegin()+2; it < s.cend(); ++it){
            if (*it != '#') {
                result.push_back(*(it - 2) - '1' + 'a');
            }
            else{
                result.push_back((*(it - 2) - '0') * 10 + 'a' - 1 + *(it - 1) - '0' );
                ++it;
                ++it;
            }
        }
        
        if(s.back() != '#') {
            if(s.at(s.size() - 2) != '#') result.push_back(s.at(s.size() - 2) + '0');
            result.push_back(s.at(s.size() - 1) + '0');
        }
        return result;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
Memory Usage: 6.2 MB, less than 89.66% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
*/
