//1309. Decrypt String from Alphabet to Integer Mapping
class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        if(s.empty()) return result;
        //ASCII('0')=48, ASCII('a')=97, ASCII('i')=105
        for (auto it = s.cbegin()+2; it < s.cend(); ++it){
            if (*it != '#') {
                result.push_back(48 + *(it - 2));
            }
            else{
                result.push_back((*(it - 2) - 48) * 10 + 96 + *(it - 1) - 48);
                ++it;
                ++it;
            }
        }
        
        if(s.back() != '#') {
            if(s.at(s.size() - 2) != '#') result.push_back(s.at(s.size() - 2) + 48);
            result.push_back(s.at(s.size() - 1) + 48);
        }
        return result;
    }
};
/*
Runtime: 4 ms, faster than 51.90% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
Memory Usage: 6.2 MB, less than 85.69% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
*/
